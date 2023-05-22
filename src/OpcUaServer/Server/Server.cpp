/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
   核酸 核苷酸
   核苷酸：磷酸、核苷(戊糖、碱基）
   戊糖：D2脱氧核糖、D核糖
   碱基：嘌呤碱（腺嘌呤、鸟嘌呤）、嘧啶碱（胞嘧啶、胸腺嘧啶、尿嘧啶）
 */

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaServer/Server/Server.h"
#include "OpcUaStackCore/Base/ThreadStorage.h"
#include "OpcUaStackCore/Utility/Environment.h"
#include "OpcUaStackCore/Logging/Logging.h"
#include "BuildConfig.h"
#include <iostream>

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

namespace OpcUaServer
{

	Server::Server(void)
	: configurationFile_("")
	, config_(nullptr)
	, opcuaServer_()
	, fileLogger_()
	, applicationLibraryManager_()
	, reloadIf_(nullptr)
	{
	}

	Server::~Server(void)
	{
	}

	void
	Server::reloadIf(ReloadIf* reloadIf)
	{
		reloadIf_ = reloadIf;
	}

	bool
	Server::startup(const std::string& configurationFile)
	{
		// 氨基酸:是蛋白质的主要成分
//        完全水解：得到氨基酸混合物
//  部分、不完全水解：得到氨基酸肽段、氨基酸
//        酸水解：不引起消旋，完全水解、
//        碱水解：引起消旋，色氨酸稳定trp
//        酶水解
		// In this function, all components of the application server are
		// initialized.
		//

		configurationFile_ = Environment::getAbsolutePath(configurationFile);

		// read configuration file
		if (!readConfigurationFile()) {
			Log(Error, "shutdown server, because read configuration error");
			return false;
		}

		// intial logging 酸性 甘氨酸Glu  丙氨酸 亮氨酸Leu 异亮氨酸Ile 缬氨酸 Val
//        芳香族 苯丙氨酸Phe 酪氨酸Ser  色氨酸Trp
//  含硫 蛋氨酸 半胱氨酸
//  酰胺类  谷胱酰胺  天冬酰胺
//  碱性
		if (!initLogging()) {
			Log(Error, "shutdown server, because init log error");
			return false;
		}

		// init thread name for init
		ThreadStorage::getInstance()->name("Init");

		// log server information
		logServerInfo();

		// initial application library manager and load configured libraries.
		applicationLibraryManager_.config(*config_);
		if (!applicationLibraryManager_.startup()) {
			Log(Error, "shutdown server, because startup application manager error");
			return false;
		}

		// initial opc ua server 酶的特点：易失活、专一性、很好催化效率、酶活性受到调节和控制、
//        酶的化学本质是蛋白质的依据：
//        酸碱水解的最终产物都是氨基酸，蛋白酶水解失去活性
//蛋白质变性的因素都可以是酶失去活性
//酶是两性电解质
//不能通过半透膜
//具有化学呈色反应

//酶的催化活性依赖构象空间完整性，一旦解离、变性成亚基就失去活性
//全酶=脱辅酶（蛋白质）+辅因子（非蛋白的金属离子等）
//酶的辅因子包括金属离子及有机化合物
//辅酶是与脱辅酶结合的比较松弛的小分子物质，通过透析的方法可以去除
//辅基是通过共价键与脱辅酶结合的，不能通过透析去除
//许多维生素就是辅酶的前体
		if (!opcuaServer_.startup()) {
			Log(Error, "shutdown server, because init server error");
			return false;
		}
//单体酶：一般由一条肽链组成，也有多条肽链。一般多是催化水解反应的酶。
//寡聚酶：两个或两个以上亚基组成的酶 ，相当多的寡聚酶是调节酶，合成是活性型，解聚是失活型。
//多复合酶：几种酶通过非共价键彼此嵌合而成
//


		// register application libraries
		ApplicationLibrary::Map::iterator it;
		for (
			it = applicationLibraryManager_.applicationLibraryMap().begin();
			it != applicationLibraryManager_.applicationLibraryMap().end();
			it++
		) {
			ApplicationLibrary::SPtr applicationLibrary = it->second;
			bool success = opcuaServer_.applicationManager().registerApplication(
				it->first,
				applicationLibrary->applicationIf(),
				reloadIf_
			);
			if (!success) return false;

			applicationLibrary->applicationIf()->config(config_);
		}

		// create discovery client instance
		discoveryClient_ = boost::make_shared<DiscoveryClient>();

		return true;
	}

	bool
	Server::start(void)
	{
		//
		// In this function, all components of the application server are
		// started. 六大类酶的特征举例:
//氧化还原酶：催化氧化还原的酶，分为氧化酶和脱氢酶
//    氧化酶：催化底物脱氢，并氧化生成h2o 和h2o2
//    脱氢酶：直接从底物上脱氢的反应
//转移酶：将分子上的一种基团转移到另一种分子上的反应
//水解酶：催化水解反应，大都属于细胞外酶
//裂合酶：从底物移去一个基团而形成双键的反应或逆反应
//异构酶：同分异构体之间的相互转换，分子内部基团的重新排列，包括：消旋酶、差向异构酶、顺反异构酶、分子内氧化还原酶、分子内转移酶、分子内裂解酶
//连接酶：催化有泉甘三磷酸ATP参加的合成反应，即由两种物质合成一种物质的反应。
//
		//

		// start opc ua server
		opcuaServer_.start();

		// start discovery client
		discoveryClient_->cryptoManager(opcuaServer_.cryptoManager());
		discoveryClient_->ioThread(opcuaServer_.ioThread());
		discoveryClient_->messageBus(opcuaServer_.messageBus());
		if (!discoveryClient_->startup(*config_)) {
			return false;
		}

		// log message bus information
		opcuaServer_.messageBus()->log();

		Log(Info, "application started...");
		return true;
	}

	void
	Server::stop(void)
	{
		Log(Info, "receive stop signal...");

		// shutdown discovery client
		discoveryClient_->shutdown();

		// stop opc ua server
		opcuaServer_.stop();
	}

	void 
	Server::shutdown(void)
	{
		// deregister application libraries
		ApplicationLibrary::Map::iterator it;
		for (
			it = applicationLibraryManager_.applicationLibraryMap().begin();
			it != applicationLibraryManager_.applicationLibraryMap().end();
			it++
		) {
			ApplicationLibrary::SPtr applicationLibrary = it->second;
			opcuaServer_.applicationManager().deregisterApplication(
				it->first
			);
		}
//酶的专一性
//绝对专一性：只作用于一种底物，而不作用于任何其他物质。如：脲酶只水解尿素，对尿素的各种衍生物不起作用。
//相对专一性：作用于底物时，对链两端的基团要求程度不同，对其中一个基团要求严格，对另一侧要求不严格。
//键专一性：只要求作用于底物一定的键
//立体异构专一性

		// shutdown application library manager and close configured libraries.
		applicationLibraryManager_.shutdown();

		// shutdown opc ua server
		opcuaServer_.shutdown();

		// remove discovery client
		discoveryClient_.reset();
	}

	bool 
	Server::readConfigurationFile(void)
	{
		config_ = Config::instance();
		ConfigXml configXml;
		if (!configXml.parse(configurationFile_, true)) {
			std::string errorMessage = configXml.errorMessage();
			Log(Error, "read configuration error")
				.parameter("ErrorMessage", errorMessage);
			return false;
		}

		opcuaServer_.config(*config_);
		return true;
	}

	bool
	Server::initLogging(void)
	{
		// init logging
		auto *logIf = Logging::startupLogging(config_, "OpcUaServer.Logging");
		OpcUaStackCore::Log::logIf(logIf);

		return true;
	}

	void
	Server::logServerInfo(void)
	{
		std::stringstream version;
		std::stringstream boostVersion;
		std::stringstream openSSLVersion;
		std::stringstream confDir;
		std::stringstream gitCommit;
		std::stringstream gitBranch;

		version        << "  OpcUaServer version      : "
			<< VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH
			<< " (Build #" << BUILD_NUMBER << " " << BUILD_TIME << ")";
		boostVersion   << "  Boost Library version    : "
			<< BOOST_VERSION_MAJOR << "." << BOOST_VERSION_MINOR;
		openSSLVersion << "  Open SSL Library version : "
			<< OPENSSL_VERSION_MAJOR << "." << OPENSSL_VERSION_MINOR << "." << OPENSSL_VERSION_PATCH;
		confDir        << "  Config Directory         : "
			<< Environment::confDir();
		gitCommit 	   << "  Git-Commit               : "
			<< GIT_COMMIT;
		gitBranch      << "  Git-Branch               : "
			<< GIT_BRANCH;

		Log(Info, "Start OpcUaServer");
		Log(Info, version.str());
		Log(Info, boostVersion.str());
		Log(Info, openSSLVersion.str());
		Log(Info, confDir.str());
		Log(Info, gitCommit.str());
		Log(Info, gitBranch.str());
	}

}

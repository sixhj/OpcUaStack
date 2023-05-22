
/*
   Copyright 2016-2017 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackCore/Logging/Logging.h"
#include "OpcUaClient/Client/ClientApplication.h"
#include "OpcUaClient/ClientCommand/CommandParser.h"
#include "OpcUaClient/ClientService/ClientServiceExecute.h"

// commands
#include "OpcUaClient/ClientCommand/CommandConnect.h"
#include "OpcUaClient/ClientCommand/CommandDisconnect.h"
#include "OpcUaClient/ClientCommand/CommandRead.h"
#include "OpcUaClient/ClientCommand/CommandReadH.h"
#include "OpcUaClient/ClientCommand/CommandWrite.h"
#include "OpcUaClient/ClientCommand/CommandWriteH.h"
#include "OpcUaClient/ClientCommand/CommandDelay.h"
#include "OpcUaClient/ClientCommand/CommandNodeSetServer.h"
#include "OpcUaClient/ClientCommand/CommandNodeSetFilter.h"
#include "OpcUaClient/ClientCommand/CommandBrowse.h"
#include "OpcUaClient/ClientCommand/CommandFunction.h"
#include "OpcUaClient/ClientCommand/CommandBrowsePathToNodeId.h"
#include "OpcUaClient/ClientCommand/CommandGetEndpoint.h"
#include "OpcUaClient/ClientCommand/CommandFindServer.h"
#include "OpcUaClient/ClientCommand/CommandRegisterServer.h"

// services
#include "OpcUaClient/ClientService/ClientServiceConnect.h"
#include "OpcUaClient/ClientService/ClientServiceDisconnect.h"
#include "OpcUaClient/ClientService/ClientServiceRead.h"
#include "OpcUaClient/ClientService/ClientServiceReadH.h"
#include "OpcUaClient/ClientService/ClientServiceWrite.h"
#include "OpcUaClient/ClientService/ClientServiceWriteH.h"
#include "OpcUaClient/ClientService/ClientServiceDelay.h"
#include "OpcUaClient/ClientService/ClientServiceNodeSetServer.h"
#include "OpcUaClient/ClientService/ClientServiceNodeSetFilter.h"
#include "OpcUaClient/ClientService/ClientServiceBrowse.h"
#include "OpcUaClient/ClientService/ClientServiceFunction.h"
#include "OpcUaClient/ClientService/ClientServiceBrowsePathToNodeId.h"
#include "OpcUaClient/ClientService/ClientServiceGetEndpoint.h"
#include "OpcUaClient/ClientService/ClientServiceFindServer.h"
#include "OpcUaClient/ClientService/ClientServiceRegisterServer.h"

using namespace OpcUaStackCore;
//蛋白质分子：氨基酸首尾相连形成的共价多肽链，三维结构称为蛋白质的构象

//单纯蛋白质
//缀合蛋白质：非蛋白的部分称为辅基。通过共价键连接的，水解时可以释放；非共价键连接的，蛋白质变性就可以去除
//蛋白质结构：
//纤维状蛋白质：起结构作用，典型的不溶于水和稀盐溶液，
//球状蛋白：形状接近球形，多肽链紧密折叠，疏水氨基酸侧链在内部，亲水氨基酸侧链在外部，在水溶液中溶解极好
//膜蛋白质：疏水氨基酸侧链在外部，不易溶于水，溶于去污剂
//单体蛋白质：一条肽链组成
//寡聚、多聚蛋白质：两条或多条肽链，每条肽链称为亚基或亚单位，亚基通过非共价键结合



namespace OpcUaClient
{

	ClientApplication::ClientApplication(void)
	: core_()
	{
		core_.init();
	}

	ClientApplication::~ClientApplication(void)
	{
		core_.cleanup();
	}

	int
	ClientApplication::run(uint32_t argc, char** argv)
	{
		// register command in command factory
		CommandParser::addCommand("CONNECT", boost::make_shared<CommandConnect>());
		CommandParser::addCommand("DISCONNECT", boost::make_shared<CommandDisconnect>());
		CommandParser::addCommand("READ", boost::make_shared<CommandRead>());
		CommandParser::addCommand("WRITE", boost::make_shared<CommandWrite>());
		CommandParser::addCommand("READH", boost::make_shared<CommandReadH>());
		CommandParser::addCommand("WRITEH", boost::make_shared<CommandWriteH>());
		CommandParser::addCommand("DELAY", boost::make_shared<CommandDelay>());
		CommandParser::addCommand("NODESETSERVER", boost::make_shared<CommandNodeSetServer>());
		CommandParser::addCommand("NODESETFILTER", boost::make_shared<CommandNodeSetFilter>());
		CommandParser::addCommand("BROWSE", boost::make_shared<CommandBrowse>());

		CommandParser::addCommand("FUNCTION", boost::make_shared<CommandFunction>());
		CommandParser::addCommand("BROWSEPATHTONODEID", boost::make_shared<CommandBrowsePathToNodeId>());
		CommandParser::addCommand("GETENDPOINT", boost::make_shared<CommandGetEndpoint>());
		CommandParser::addCommand("FINDSERVER", boost::make_shared<CommandFindServer>());
		CommandParser::addCommand("REGISTERSERVER", boost::make_shared<CommandRegisterServer>());


		// register service in service factory
		ClientServiceExecute::addClientService(CommandBase::Cmd_Connect, boost::make_shared<ClientServiceConnect>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_Disconnect, boost::make_shared<ClientServiceDisconnect>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_Read, boost::make_shared<ClientServiceRead>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_ReadH, boost::make_shared<ClientServiceReadH>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_Write, boost::make_shared<ClientServiceWrite>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_WriteH, boost::make_shared<ClientServiceWriteH>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_Delay, boost::make_shared<ClientServiceDelay>());


		ClientServiceExecute::addClientService(CommandBase::Cmd_NodeSetServer, boost::make_shared<ClientServiceNodeSetServer>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_NodeSetFilter, boost::make_shared<ClientServiceNodeSetFilter>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_Browse, boost::make_shared<ClientServiceBrowse>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_Function, boost::make_shared<ClientServiceFunction>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_BrowsePathToNodeId, boost::make_shared<ClientServiceBrowsePathToNodeId>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_GetEndpoint, boost::make_shared<ClientServiceGetEndpoint>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_FindServer, boost::make_shared<ClientServiceFindServer>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_RegisterServer, boost::make_shared<ClientServiceRegisterServer>());
//蛋白质结构
//1级结构：链，多肽链的氨基酸组成序列 。由多肽链主链共价连接的氨基酸残基决定的
//2级结构：片段，多肽链借助共价键排列成的片段，a螺旋 ，折叠股片段。由非共价键，如：氢键、离子键、范德华力、疏水作用决定的。
//3级结构：球状，多肽链借助非共价键形成紧密球状构象
//4级结构：空间结构，寡聚蛋白质中个各亚基之间在空间上的相互关系和结合方式

//蛋白质是生物功能的载体：
//1、催化  酶是蛋白质最大的一类
//2、调节 调节其他蛋白质生理能力 ，调节蛋白参与基因的表达的调控
//3、存贮、4 转运；5 运动；6 支架； 7 结构；8 防御和进攻；9 异常功能

//肽是氨基酸线性聚合物，也称肽链
//蛋白质：是由一条或多条有确定的氨基酸序列的多肽链构成的分子 。

		// parse command line
		CommandParser commandParser;
		CommandBase::Vec commandBaseVec;
		if (!commandParser.parse(argc, argv, commandBaseVec)) {
			std::cerr << commandParser.errorString() << std::endl;
			return -1;
		}



		// init logging
		Logging::defaultLogFile("OpcUaClient.log");
		auto *logIf = Logging::startupLogging(commandParser.config(), "OpcUaClient.Logging");
		OpcUaStackCore::Log::logIf(logIf);

		// execute commands from command line line
		ClientServiceExecute clientServiceExecute;
		if (!clientServiceExecute.run(commandBaseVec)) {
			std::cerr << clientServiceExecute.errorString() << std::endl;
			return -1;
		}

		std::cout << "OK" << std::endl;
		return 0;
	}

}

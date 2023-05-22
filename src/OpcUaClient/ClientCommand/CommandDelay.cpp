
/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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
//abdicate v.退位 ; ab- 远离 ; dic=说 ; -ate v.
//abide v. 遵守,忍受 ; a- 去; bid 命令
//abolish 废除 ;a- 否定 ;bol=bor=产生
//abound ; a-否定 ;bound=bond=边界
//absolute adj.  ab-强调 ;sol 单独; isolate 孤立; solo ;solar ;solar energy ;
//absorb v. ab-强调; sorb=吸收;
//abstract adj. 抽象; abs- = ab- 远离; trac=拉 ;tractor
//abundantly adv.大量的 abound abundant  abundantly
//abuse  ; ab- ; use=  ; abnormal ; abdicate
//academic adj.学术 ; academy ;academic;performance
//accelerate v.加速; ac-去  ; celer= 跑 ; -ate v. ;decelerate ;
//acclaim ;  ac-去 ; claim=clam=叫 喊
//accommodate 容纳,适应 v. ;ac-去 ; com-多;mod=模子;-ate v
//mode ;model ;modest; accommodation ;
//accompany v.陪伴,伴随 ; ac-去 ; company 陪伴 公司 ;
//account v.占比,解释 n.账户 ; ac-去 ;count ; account for 占比;asset;access
//accuracy n.准确 精确 ;ac-强调 ;cur=关心 ; -acy n.
//account  count  ac-去 account for
#include <boost/lexical_cast.hpp>
#include <sstream>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaClient/ClientCommand/CommandDelay.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	CommandDelay::CommandDelay(void)
	: CommandBase(CommandBase::Cmd_Delay)
	, timeout_(0)
	{
	}

	CommandDelay::~CommandDelay(void)
	{
	}

	CommandBase::SPtr
	CommandDelay::createCommand(void)
	{
		CommandBase::SPtr commandBase = constructSPtr<CommandDelay>();
		return commandBase;
	}

	bool
	CommandDelay::validateCommand(void)
	{
		if (timeout_ == 0) {
			std::stringstream ss;
			ss << "need timeout parameter";
			errorMessage(ss.str());
			return false;
		}
		return true;
	}

	bool
	CommandDelay::addParameter(const std::string& parameterName, const std::string& parameterValue)
	{
		if (parameterName == "-TIMEOUT") {
			try {
				timeout_ = boost::lexical_cast<uint32_t>(parameterValue);
			}
			catch (...)
			{
				std::stringstream ss;
				ss << "timeout parameter invalid (" << parameterValue << ")";
				errorMessage(ss.str());
				return false;
		    }
		}
		else {
			std::stringstream ss;
			ss << "invalid parameter " << parameterName;
			errorMessage(ss.str());
			return false;
		}
		return true;
	}

	std::string
	CommandDelay::help(void)
	{
		std::stringstream ss;
		ss << "  -Delay: Stops the application for a defined period\n"
		   << "    -Timeout (1): Time in milli seconds\n";
		return ss.str();
	}

	uint32_t
	CommandDelay::timeout(void)
	{
		return timeout_;
	}

}

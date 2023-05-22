/*
   Copyright 2016-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)

2023年5月17日09:18:23
    symbolic adj.象征 符号 ;sym-相同=sim- ; bol = ball ;symbol 标志 象征; symbolize v.象征
sympathy n.同情; sym-相同 ;path=pass=感情 ; passion 感情 激情; passionate 有激情的 ;dispassioned 客观的;compassion 同情
 in sympathy with 支持 赞同
 temper v.调好控制  n.脾气 性情; temper=tempor=时间
temporary adj.暂时 临时的  ;
 tempt v.引诱  ; temp=尝试  attempt 尝试;contempt 尝试;
 terminal adj.重点;  term=重点;termination ;terminate ; terminator; determine 下定决心;determination 决心
 terrify ;terr=恐怖;terrorist 恐怖分子; terror 恐怖 n. ; terrible 可怕的;
 testify v.证实 作证 ; test 测试; -fy v. ;
 thorny adj.棘手的 麻烦的; thorn=刺 ; -y adj.;
 threaten v.威胁; threat 威胁;  eat
 thrive v.繁荣 盛行;   live
 tissue n.动植物组织 ;tis=动植物组织;
 tolerate v.容忍;rol=容忍 ;tolerant 容忍的; tolerance 容忍;
 tough adj.强硬的
 toxic adj.有毒的 不良的; asset ;access ;tox=有毒的
 transaction ;trans-穿越;act=行动;

 */

#ifndef __OpcUaClient_CommandConnect_h__
#define __OpcUaClient_CommandConnect_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaClient/ClientCommand/CommandBase.h"

namespace OpcUaClient
{

	class CommandConnect
	: public CommandBase
	{
	  public:
		typedef boost::shared_ptr<CommandConnect> SPtr;

		CommandConnect(void);
		virtual ~CommandConnect(void);

		//- CommandConnect interface ---------------------------------------------
		virtual CommandBase::SPtr createCommand(void);
		virtual bool validateCommand(void);
		virtual bool addParameter(const std::string& parameterName, const std::string& parameterValue);
		virtual std::string help(void);
		//- CommandConnect interface ---------------------------------------------

		std::string& endpointUrl(void);
		bool activateSession(void);

	  private:
		std::string endpointUrl_;
		bool activateSession_;
	};

}

#endif

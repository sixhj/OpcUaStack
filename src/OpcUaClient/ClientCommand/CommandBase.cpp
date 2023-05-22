
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
    primary  prim=prin 主要

     transcendence n.超越; scend=攀爬; ascend ;descend;
 transfer 传递 转移;fer=拿 ;
 transform v.改变;form 形状;transformer 变形金刚;deception ;deceive 欺骗; magn=大 ;prime 首领;
 transition n.转型 ;visit 参观 ;circuit 循环;
 transparency n.透明度 ;par=出现;apparent 明显的;
 transplant  n.移植 ; plant 植物 ;
 transportation  n.运输 ; port 港口 ;porter 搬运工 portable 可移动的; import 进口 ;export 出口;important 重要的
 tremendous adj.巨大的 ;tremble 因害怕颤抖; enormous  巨大;immense 巨大的;giant巨大的
 triumph 成功;
turbulent adj.混乱 ;turb=搅动;disturb 打搅;turbid 搅动;
 ultimate adj.最终的;ulti=最终
 unanimous adj. 全体同意 ; una- = uni  一 ; unite 联合
 undermine v.破坏 ;under 下方 ; mine 采矿;
 uniform adj. 统一的 ; form 服装 ;
 unique adj.独特
 universal adj.普遍 通用;
 unsurpassed adj . ;surpass 超越 ; sur- 后;pass 经过
 surname 姓 ;last name ;family name;
 upset 打乱;set over ; set up ;upset;
 urban adj.城市;suburb 郊区;
 urge v.推动 ;
 utility n.功用 效用; use ;ut=us=使用; s-d d-t ;utilize ;
 vacuum  v.吸入 n.真空 ;vac=空;
 vague adj 模糊的 ;vag=走 游走;
 vain adj.自负 ;vain=van=vac=空
 valid adj.有效 ;val 价值;
 vanish v.消失 ; vanity n.虚荣;
various adj.各种各样的; var=变化 ;vary 变化; variety 多样性; a variety of 多种多样 ; variable 可变 变量
verbal adj.口头 ;verb 词汇; verdict n.结论 ; dict=说 ;ver=正确;
 viable adj.可行的 ;via=vi=通道 ;previous 之前的; viaduct 导水渠;  convey 传递;
 vibrant adj.充满活力 ;vib=震动; vibrate 震动 v. ;
 victory  n.胜利 ;  vigorously adv.精力充沛的 ;vigor 精力 ;
 violate v.违反;  violence 暴力;
 virtually adv.几乎; virt=vert= 转;virtual 虚拟的 事实的; virtual reality  虚拟现实
 visible adj.可见的  ;vision n.视力 ; vis=看 ;-ion n.
 visualize  v.想象 ; visual 视觉; -ize v. ;
 vital adj.至关重要; vit=生命; vitamin 维生素 ; fatal  adj.致命的
 vivid adj.生动的;viv=活 ;revive 复活;survive 幸存;
 vocation n.职业 ;voc=声音; vacation 假期 ;vac=空
 withdraw v.撤销 ;with- = re- 反向 ; draw 拉
 withstand v.承受 ; worship v.敬奉 ;
 yield v.生产 产生 ; field 地 ;
 zone n.地区

   Autor: Kai Huebl (kai@huebl-sgh.de) skip
 */

#include "OpcUaClient/ClientCommand/CommandBase.h"


namespace OpcUaClient
{

	CommandBase::CommandBase(void)
	: cmd_(Cmd_Unknown)
	, session_("Main")
	, errorMessage_()
	, parameterFlags_()
	{
	}

	CommandBase::CommandBase(Cmd cmd)
	: cmd_(cmd)
	, session_("Main")
	{
	}

	CommandBase::~CommandBase(void)
	{
	}

	void
	CommandBase::cmd(const Cmd cmd)
	{
		cmd_ = cmd;
	}

	CommandBase::Cmd
	CommandBase::cmd(void)
	{
		return cmd_;
	}

	void
	CommandBase::command(const std::string& command)
	{
		command_ = command;
	}

	std::string&
	CommandBase::command(void)
	{
		return command_;
	}

	void
	CommandBase::session(const std::string& session)
	{
		session_ = session;
	}

	std::string&
	CommandBase::session(void)
	{
		return session_;
	}

	void
	CommandBase::errorMessage(const std::string& errorMessage)
	{
		errorMessage_ = errorMessage;
	}

	std::string&
	CommandBase::errorMessage(void)
	{
		return errorMessage_;
	}

	ParameterFlags&
	CommandBase::parameterFlags(void)
	{
		return parameterFlags_;
	}

}

/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ServiceSet/MethodService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	MethodService::MethodService(void)
	: componentSession_(nullptr)
	, methodServiceIf_(nullptr)
	{
	}

	MethodService::~MethodService(void)
	{
	}

	void 
	MethodService::componentSession(Component* componentSession)
	{
		componentSession_ = componentSession;
	}

	void 
	MethodService::methodServiceIf(MethodServiceIf* methodServiceIf)
	{
		methodServiceIf_ = methodServiceIf;
	}

	void 
	MethodService::sendSync(ServiceTransactionCall::SPtr serviceTransactionCall)
	{
		serviceTransactionCall->sync(true);
		serviceTransactionCall->conditionBool().conditionInit();
		send(serviceTransactionCall);
		serviceTransactionCall->conditionBool().waitForCondition();
	}

	void 
	MethodService::send(ServiceTransactionCall::SPtr serviceTransactionCall)
	{
		serviceTransactionCall->componentService(this);
		OpcUaNodeId nodeId;
		componentSession_->send(serviceTransactionCall);
	}


	void 
	MethodService::receive(OpcUaNodeId& typeId, Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		
		// check if transaction is synchron
		if (serviceTransaction->sync()) {
			serviceTransaction->conditionBool().conditionTrue();
			return;
		}
		
		switch (typeId.nodeId<uint32_t>()) 
		{
			case OpcUaId_CallResponse_Encoding_DefaultBinary:
			{
				if (methodServiceIf_ != nullptr) {
					methodServiceIf_->methodServiceCallResponse(
						boost::static_pointer_cast<ServiceTransactionCall>(serviceTransaction)
					);
				}
				break;
			}

			default:
				Log(Error, "call service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());
		}
	}

}

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

#include "OpcUaStackCore/ServiceSet/TransferSubscriptionsRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa TransferSubscriptionsRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	TransferSubscriptionsRequest::TransferSubscriptionsRequest(void)
	: ObjectPool<TransferSubscriptionsRequest>()
	, subscriptionIdArraySPtr_(OpcUaUInt32Array::construct())
	, sendInitialValues_()
	{
	}

	TransferSubscriptionsRequest::~TransferSubscriptionsRequest(void)
	{
	}

	void 
	TransferSubscriptionsRequest::subscriptionIds(const OpcUaUInt32Array::SPtr subscriptionIds)
	{
		subscriptionIdArraySPtr_ = subscriptionIds;
	}
	
	OpcUaUInt32Array::SPtr 
	TransferSubscriptionsRequest::subscriptionIds(void) const
	{
		return subscriptionIdArraySPtr_;
	}

	void 
	TransferSubscriptionsRequest::sendInitialValues(const OpcUaBoolean& sendInitialValues)
	{
		sendInitialValues_ = sendInitialValues;
	}
	
	OpcUaBoolean 
	TransferSubscriptionsRequest::sendInitialValues(void) const
	{
		return sendInitialValues_;
	}

	void 
	TransferSubscriptionsRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		subscriptionIdArraySPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, sendInitialValues_);
	}
	
	void 
	TransferSubscriptionsRequest::opcUaBinaryDecode(std::istream& is)
	{
		subscriptionIdArraySPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, sendInitialValues_);
	}
}

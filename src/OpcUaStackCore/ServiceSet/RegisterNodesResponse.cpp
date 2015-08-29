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

#include "OpcUaStackCore/ServiceSet/RegisterNodesResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RegisterNodesResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RegisterNodesResponse::RegisterNodesResponse(void)
	: ObjectPool<RegisterNodesResponse>()
	, registeredNodeIdArraySPtr_(OpcUaNodeIdArray::construct())
	{
	}

	RegisterNodesResponse::~RegisterNodesResponse(void)
	{
	}

	void 
	RegisterNodesResponse::registeredNodeIds(const OpcUaNodeIdArray::SPtr registeredNodeIds)
	{
		registeredNodeIdArraySPtr_ = registeredNodeIds;
	}
	
	OpcUaNodeIdArray::SPtr 
	RegisterNodesResponse::registeredNodeIds(void) const
	{
		return registeredNodeIdArraySPtr_;
	}

	void 
	RegisterNodesResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		registeredNodeIdArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	RegisterNodesResponse::opcUaBinaryDecode(std::istream& is)
	{
		registeredNodeIdArraySPtr_->opcUaBinaryDecode(is);
	}
}

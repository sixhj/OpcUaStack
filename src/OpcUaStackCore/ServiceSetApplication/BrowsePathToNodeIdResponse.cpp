/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSetApplication/BrowsePathToNodeIdResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// NodeIdResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	NodeIdResult::NodeIdResult(void)
	: statusCode_(Success)
	, nodeId_()
	{
	}

	NodeIdResult::~NodeIdResult(void)
	{
	}

	void
	NodeIdResult::statusCode(OpcUaStatusCode& statusCode)
	{
		statusCode_ = statusCode;
	}

	OpcUaStatusCode
	NodeIdResult::statusCode(void)
	{
		return statusCode_;
	}

	void
	NodeIdResult::nodeId(OpcUaNodeId& nodeId)
	{
		nodeId_ = nodeId;
	}

	OpcUaNodeId&
	NodeIdResult::nodeId(void)
	{
		return nodeId_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// BrowsePathToNodeIdResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	BrowsePathToNodeIdResponse::BrowsePathToNodeIdResponse(void)
	: Object()
	, nodeIdResults_()
	{
	}

	BrowsePathToNodeIdResponse::~BrowsePathToNodeIdResponse(void)
	{
	}

	void
	BrowsePathToNodeIdResponse::nodeIdResults(NodeIdResultArray::SPtr& nodeIdResults)
	{
		nodeIdResults_ = nodeIdResults;
	}

	NodeIdResultArray::SPtr&
	BrowsePathToNodeIdResponse::nodeIdResults(void)
	{
		return nodeIdResults_;
	}

	void
	BrowsePathToNodeIdResponse::opcUaBinaryEncode(std::ostream& os) const
	{
	}

	void
	BrowsePathToNodeIdResponse::opcUaBinaryDecode(std::istream& is)
	{
	}

}

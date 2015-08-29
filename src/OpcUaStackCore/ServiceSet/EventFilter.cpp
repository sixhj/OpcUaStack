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

#include "OpcUaStackCore/ServiceSet/EventFilter.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa EventFilter
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	EventFilter::EventFilter(void)
	: ObjectPool<EventFilter>()
	, selectClausesArraySPtr_(SimpleAttributeOperandArray::construct())
	, whereClause_()
	{
	}

	EventFilter::~EventFilter(void)
	{
	}

	void 
	EventFilter::selectClauses(const SimpleAttributeOperandArray::SPtr selectClauses)
	{
		selectClausesArraySPtr_ = selectClauses;
	}
	
	SimpleAttributeOperandArray::SPtr 
	EventFilter::selectClauses(void) const
	{
		return selectClausesArraySPtr_;
	}
	
	void 
	EventFilter::whereClause(const ContentFilter& whereClause)
	{
		whereClause_ = whereClause;
	}
	
	ContentFilter& 
	EventFilter::whereClause(void)
	{
		return whereClause_;
	}

	ExtensibleParameterBase::BSPtr 
	EventFilter::factory(void)
	{
		return EventFilter::construct();
	}

	void 
	EventFilter::opcUaBinaryEncode(std::ostream& os) const
	{
		selectClausesArraySPtr_->opcUaBinaryEncode(os);
		whereClause_.opcUaBinaryEncode(os);
	}
	
	void 
	EventFilter::opcUaBinaryDecode(std::istream& is)
	{
		selectClausesArraySPtr_->opcUaBinaryDecode(is);
		whereClause_.opcUaBinaryDecode(is);
	}
}

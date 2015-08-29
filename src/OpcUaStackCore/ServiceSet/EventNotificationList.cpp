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

#include "OpcUaStackCore/ServiceSet/EventNotificationList.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa EventNotificationList
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	EventNotificationList::EventNotificationList(void)
	: ObjectPool<EventNotificationList>()
	, eventFieldListArraySPtr_(EventFieldListArray::construct())
	{
	}

	EventNotificationList::~EventNotificationList(void)
	{
	}

	void 
	EventNotificationList::events(const EventFieldListArray::SPtr events)
	{
		eventFieldListArraySPtr_ = events;
	}

	
	EventFieldListArray::SPtr 
	EventNotificationList::events(void) const
	{
		return eventFieldListArraySPtr_;
	}

	ExtensibleParameterBase::BSPtr 
	EventNotificationList::factory(void)
	{
		return EventNotificationList::construct();
	}

	void 
	EventNotificationList::opcUaBinaryEncode(std::ostream& os) const
	{
		eventFieldListArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	EventNotificationList::opcUaBinaryDecode(std::istream& is)
	{
		eventFieldListArraySPtr_->opcUaBinaryDecode(is);
	}
}

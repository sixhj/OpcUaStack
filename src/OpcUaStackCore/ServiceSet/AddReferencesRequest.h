/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_AddReferencesRequest_h__
#define __OpcUaStackCore_AddReferencesRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"
#include "OpcUaStackCore/StandardDataTypes/AddReferencesItem.h"

namespace OpcUaStackCore
{

	class DLLEXPORT AddReferencesRequest
	: public Object
	, public JsonFormatter
	{
	  public:
		typedef boost::shared_ptr<AddReferencesRequest> SPtr;

		AddReferencesRequest(void);
		virtual ~AddReferencesRequest(void);

		void referencesToAdd(const AddReferencesItemArray::SPtr addReferencesItemArray);
		AddReferencesItemArray::SPtr referencesToAdd() const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  protected:
	    bool jsonEncodeImpl(boost::property_tree::ptree &pt) const { return false; }
	    bool jsonDecodeImpl(const boost::property_tree::ptree &pt) { return false; }

	  private:
		AddReferencesItemArray::SPtr addReferencesItemArray_;
	};

}

#endif

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

#ifndef __OpcUaStackCore_GetEndpointsRequest_h__
#define __OpcUaStackCore_GetEndpointsRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{

	class DLLEXPORT GetEndpointsRequest : public  ObjectPool<GetEndpointsRequest>
	{
	  public:
		typedef boost::shared_ptr<GetEndpointsRequest> SPtr;

		GetEndpointsRequest(void);
		virtual ~GetEndpointsRequest(void);

		void endpointUrl(const OpcUaString& endpointUrl);
		void endpointUrl(const std::string& endpointUrl);
		OpcUaString& endpointUrl(void);
		void localeIds(const OpcUaStringArray::SPtr localIds);
		OpcUaStringArray::SPtr localeIds(void) const;
		void profileUris(const OpcUaStringArray::SPtr profileUris);
		OpcUaStringArray::SPtr profileUris(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaString endpointUrl_;
		OpcUaStringArray::SPtr localeIdArraySPtr_;
		OpcUaStringArray::SPtr profileUriArraySPtr_;
	};

}

#endif

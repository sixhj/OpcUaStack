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

#ifndef __CDAINTERFACE_H__
#define __CDAINTERFACE_H__

#include "Common/Base/DataValue.h"

class CDAInterfaceCallback
{
  public:
	typedef enum {
		Ok,
		NotAvailable,
		NotExist
	} State;

	virtual void handleReadComplete(const std::string& name, DataValue::Type dataValueType, DataValue::VecSPtr dataValueVecSPtr, State state) = 0;
	virtual void handleWriteComplete(const std::string& name, DataValue::Type dataValueType, State state) = 0;
	virtual void handleChangeValue(const std::string& name, DataValue::Type dataValueType, DataValue::VecSPtr dataValueVecSPtr, State state) = 0;
	virtual void handleSubscribeOn(const std::string& name, DataValue::Type dataValueType, State state) = 0;
	virtual void handleSubscribeOff(const std::string& name, DataValue::Type dataValueType, State state) = 0;
	virtual void handleReset(State state) = 0;

	virtual void handleStoped(void) = 0;
	virtual void handleStarted(void) = 0;
};

class CDAInterface
{
  public:
	virtual void readValue(const std::string& name, DataValue::Type dataValueType) = 0;
	virtual void writeValue(const std::string& name, DataValue::Type dataValueType, DataValue::VecSPtr dataValueVecSPtr) = 0;
	virtual void subscribeOn(const std::string& name, DataValue::Type dataValueType) = 0;
	virtual void subscribeOff(const std::string& name) = 0;
	virtual void reset(void) = 0;

	virtual void stoped(void) = 0;
	virtual void started(void) = 0;
};

#endif

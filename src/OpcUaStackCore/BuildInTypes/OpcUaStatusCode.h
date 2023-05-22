/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_OpcUaStatusCode_h__
#define __OpcUaStackCore_OpcUaStatusCode_h__

#include <iostream>
#include <map>
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"


namespace OpcUaStackCore
{

	typedef enum {
		Success =								0x00000000,
		BadUnexpectedError =					0x80010000,
		BadInternalError =						0x80020000,
		BadOutOfMemory =						0x80030000,
		BadResourceUnavailable =				0x80040000,
		BadCommunicationError =					0x80050000,
		BadEncodingError =						0x80060000,
		BadDecodingError =						0x80070000,
		BadEncodingLimitsExceeded =				0x80080000,
		BadRequestTooLarge =					0x80B80000,
		BadResponseTooLarge =					0x80B90000,
		BadUnknownResponse =					0x80090000,
		BadTimeout =							0x800A0000,
		BadServiceUnsupported =					0x800B0000,
		BadShutdown =							0x800C0000,
		BadServerNotConnected =					0x800D0000,
		BadServerHalted =						0x800E0000,
		BadNothingToDo =						0x800F0000,
		BadTooManyOperations =					0x80100000,
		BadTooManyMonitoredItems =				0x80DB0000,
		BadDataTypeIdUnknown =					0x80110000,
		BadCertificateInvalid =					0x80120000,
		BadCertificateChainIncomplete =			0x810D0000,
		BadSecurityChecksFailed =				0x80130000,
		BadCertificateTimeInvalid =				0x80140000,
		BadCertificateIssuerTimeInvalid =		0x80150000,
		BadCertificateHostNameInvalid =			0x80160000,
		BadCertificateUriInvalid =				0x80170000,
		BadCertificateUseNotAllowed =			0x80180000,
		BadCertificateIssuerUseNotAllowed =		0x80190000,
		BadCertificateUntrusted =				0x801A0000,
		BadCertificateRevocationUnknown =		0x801B0000,
		BadCertificateIssuerRevocationUnknown =	0x801C0000,
		BadCertificateRevoked =					0x801D0000,
		BadCertificateIssuerRevoked =			0x801E0000,
		BadUserAccessDenied =					0x801F0000,
		BadIdentityTokenInvalid =				0x80200000,
		BadIdentityTokenRejected =				0x80210000,
		BadSecureChannelIdInvalid =				0x80220000,
		BadInvalidTimestamp =					0x80230000,
		BadNonceInvalid =						0x80240000,
		BadSessionIdInvalid =					0x80250000,
		BadSessionClosed =						0x80260000,
		BadSessionNotActivated =				0x80270000,
		BadSubscriptionIdInvalid =				0x80280000,
		BadRequestHeaderInvalid =				0x802A0000,
		BadTimestampsToReturnInvalid =			0x802B0000,
		BadRequestCancelledByClient =			0x802C0000,
		GoodSubscriptionTransferred =			0x002D0000,
		GoodCompletesAsynchronously =			0x002E0000,
		GoodOverload =							0x002F0000,
		GoodClamped =							0x00300000,
		BadNoCommunication =					0x80310000,
		BadWaitingForInitialData =				0x80320000,
		BadNodeIdInvalid =						0x80330000,
		BadNodeIdUnknown =						0x80340000,
		BadAttributeIdInvalid =					0x80350000,
		BadIndexRangeInvalid =					0x80360000,
		BadIndexRangeNoData =					0x80370000,
		BadDataEncodingInvalid =				0x80380000,
		BadDataEncodingUnsupported =			0x80390000,
		BadNotReadable =						0x803A0000,
		BadNotWritable =						0x803B0000,
		BadOutOfRange =							0x803C0000,
		BadNotSupported =						0x803D0000,
		BadNotFound =							0x803E0000,
		BadObjectDeleted =						0x803F0000,
		BadNotImplemented =						0x80400000,
		BadMonitoringModeInvalid =				0x80410000,
		BadMonitoredItemIdInvalid =				0x80420000,
		BadMonitoredItemFilterInvalid =			0x80430000,
		BadMonitoredItemFilterUnsupported =		0x80440000,
		BadFilterNotAllowed =					0x80450000,
		BadStructureMissing =					0x80460000,
		BadEventFilterInvalid =					0x80470000,
		BadContentFilterInvalid =				0x80480000,
		BadFilterOperatorInvalid =				0x80C10000,
		BadFilterOperatorUnsupported =			0x80C20000,
		BadFilterOperandCountMismatch =			0x80C30000,
		BadFilterOperandInvalid =				0x80490000,
		BadFilterElementInvalid =				0x80C40000,
		BadFilterLiteralInvalid =				0x80C50000,
		BadContinuationPointInvalid =			0x804A0000,
		BadNoContinuationPoints =				0x804B0000,
		BadReferenceTypeIdInvalid =				0x804C0000,
		BadBrowseDirectionInvalid =				0x804D0000,
		BadNodeNotInView =						0x804E0000,
		BadServerUriInvalid =					0x804F0000,
		BadServerNameMissing =					0x80500000,
		BadDiscoveryUrlMissing =				0x80510000,
		BadSempahoreFileMissing =				0x80520000,
		BadRequestTypeInvalid =					0x80530000,
		BadSecurityModeRejected =				0x80540000,
		BadSecurityPolicyRejected =				0x80550000,
		BadTooManySessions =					0x80560000,
		BadUserSignatureInvalid =				0x80570000,
		BadApplicationSignatureInvalid =		0x80580000,
		BadNoValidCertificates =				0x80590000,
		BadIdentityChangeNotSupported =			0x80C60000,
		BadRequestCancelledByRequest =			0x805A0000,
		BadParentNodeIdInvalid =				0x805B0000,
		BadReferenceNotAllowed =				0x805C0000,
		BadNodeIdRejected =						0x805D0000,
		BadNodeIdExists =						0x805E0000,
		BadNodeClassInvalid =					0x805F0000,
		BadBrowseNameInvalid =					0x80600000,
		BadBrowseNameDuplicated =				0x80610000,
		BadNodeAttributesInvalid =				0x80620000,
		BadTypeDefinitionInvalid =				0x80630000,
		BadSourceNodeIdInvalid =				0x80640000,
		BadTargetNodeIdInvalid =				0x80650000,
		BadDuplicateReferenceNotAllowed =		0x80660000,
		BadInvalidSelfReference =				0x80670000,
		BadReferenceLocalOnly =					0x80680000,
		BadNoDeleteRights =						0x80690000,
		UncertainReferenceNotDeleted =			0x40BC0000,
		BadServerIndexInvalid =					0x806A0000,
		BadViewIdUnknown =						0x806B0000,
		BadViewTimestampInvalid =				0x80C90000,
		BadViewParameterMismatch =				0x80CA0000,
		BadViewVersionInvalid =					0x80CB0000,
		UncertainNotAllNodesAvailable =			0x40C00000,
		GoodResultsMayBeIncomplete =			0x00BA0000,
		BadNotTypeDefinition =					0x80C80000,
		UncertainReferenceOutOfServer =			0x406C0000,
		BadTooManyMatches =						0x806D0000,
		BadQueryTooComplex =					0x806E0000,
		BadNoMatch =							0x806F0000,
		BadMaxAgeInvalid =						0x80700000,
		BadHistoryOperationInvalid =			0x80710000,
		BadHistoryOperationUnsupported =		0x80720000,
		BadInvalidTimestampArgument =			0x80BD0000,
		BadWriteNotSupported =					0x80730000,
		BadTypeMismatch =						0x80740000,
		BadMethodInvalid =						0x80750000,
		BadArgumentsMissing =					0x80760000,
		BadTooManySubscriptions =				0x80770000,
		BadTooManyPublishRequests =				0x80780000,
		BadNoSubscription =						0x80790000,
		BadSequenceNumberUnknown =				0x807A0000,
		BadMessageNotAvailable =				0x807B0000,
		BadInsufficientClientProfile =			0x807C0000,
		BadStateNotActive =						0x80BF0000,
		BadTcpServerTooBusy =					0x807D0000,
		BadTcpMessageTypeInvalid =				0x807E0000,
		BadTcpSecureChannelUnknown =			0x807F0000,
		BadTcpMessageTooLarge =					0x80800000,
		BadTcpNotEnoughResources =				0x80810000,
		BadTcpInternalError =					0x80820000,
		BadTcpEndpointUrlInvalid =				0x80830000,
		BadRequestInterrupted =					0x80840000,
		BadRequestTimeout =						0x80850000,
		BadSecureChannelClosed =				0x80860000,
		BadSecureChannelTokenUnknown =			0x80870000,
		BadSequenceNumberInvalid =				0x80880000,
		BadProtocolVersionUnsupported =			0x80BE0000,
		BadConfigurationError =					0x80890000,
		BadNotConnected =						0x808A0000,
		BadDeviceFailure =						0x808B0000,
		BadSensorFailure =						0x808C0000,
		BadOutOfService =						0x808D0000,
		BadDeadbandFilterInvalid =				0x808E0000,
		UncertainNoCommunicationLastUsableValue = 0x408F0000,
		UncertainLastUsableValue =				0x40900000,
		UncertainSubstituteValue =				0x40910000,
		UncertainInitialValue =					0x40920000,
		UncertainSensorNotAccurate =			0x40930000,
		UncertainEngineeringUnitsExceeded =		0x40940000,
		UncertainSubNormal =					0x40950000,
		GoodLocalOverride =						0x00960000,
		BadRefreshInProgress =					0x80970000,
		BadConditionAlreadyDisabled =			0x80980000,
		BadConditionAlreadyEnabled =			0x80CC0000,
		BadConditionDisabled =					0x80990000,
		BadEventIdUnknown =						0x809A0000,
		BadEventNotAcknowledgeable =			0x80BB0000,
		BadDialogNotActive =					0x80CD0000,
		BadDialogResponseInvalid =				0x80CE0000,
		BadConditionBranchAlreadyAcked =		0x80CF0000,
		BadConditionBranchAlreadyConfirmed =	0x80D00000,
		BadConditionAlreadyShelved =			0x80D10000,
		BadConditionNotShelved =				0x80D20000,
		BadShelvingTimeOutOfRange =				0x80D30000,
		BadNoData =								0x809B0000,
		BadBoundNotFound =						0x80D70000,
		BadBoundNotSupported =					0x80D80000,
		BadDataLost =							0x809D0000,
		BadDataUnavailable =					0x809E0000,
		BadEntryExists =						0x809F0000,
		BadNoEntryExists =						0x80A00000,
		BadTimestampNotSupported =				0x80A10000,
		GoodEntryInserted =						0x00A20000,
		GoodEntryReplaced =						0x00A30000,
		UncertainDataSubNormal =				0x40A40000,
		GoodNoData =							0x00A50000,
		GoodMoreData =							0x00A60000,
		BadAggregateListMismatch =				0x80D40000,
		BadAggregateNotSupported =				0x80D50000,
		BadAggregateInvalidInputs =				0x80D60000,
		BadAggregateConfigurationRejected =		0x80DA0000,
		GoodDataIgnored =						0x00D90000,
		GoodCommunicationEvent =				0x00A70000,
		GoodShutdownEvent =						0x00A80000,
		GoodCallAgain =							0x00A90000,
		GoodNonCriticalTimeout =				0x00AA0000,
		BadInvalidArgument =					0x80AB0000,
		BadConnectionRejected =					0x80AC0000,
		BadDisconnect =							0x80AD0000,
		BadConnectionClosed =					0x80AE0000,
		BadInvalidState =						0x80AF0000,
		BadEndOfStream =						0x80B00000,
		BadNoDataAvailable =					0x80B10000,
		BadWaitingForResponse =					0x80B20000,
		BadOperationAbandoned =					0x80B30000,
		BadExpectedStreamToBlock =				0x80B40000,
		BadWouldBlock =							0x80B50000,
		BadSyntaxError =						0x80B60000,
		BadMaxConnectionsReached =				0x80B70000,

		BadSignatureInvalid =					0x85000000,
		BadStatusCodeUnknown =					0xFFFFFFFF,
	} OpcUaStatusCode;


	class DLLEXPORT OpcUaStatusCodeMap
	{
	  public:
		typedef std::map<OpcUaStatusCode, std::string> StatusCodeMap;
		typedef std::map<std::string,OpcUaStatusCode> StatusCodeReverseMap;

		static std::string shortString(OpcUaStatusCode statusCode);
		static std::string longString(OpcUaStatusCode statusCode);
		static OpcUaStatusCode statusCode(const std::string& statusCodeString);
		static void getStatusCodeVec(std::vector<std::string>& statusCodeVec);
		static bool exist(OpcUaStatusCode statusCode);
		static bool exist(const std::string& statusCodeString);

	  private:
		static void initial(void);
		static void insert(OpcUaStatusCode statusCode, const std::string& shortStatusCodeString, const std::string& longStatusCodeString);

		static bool mapExist_;
		static StatusCodeMap shortStatusCodeMap_;
		static StatusCodeMap longStatusCodeMap_;
		static StatusCodeReverseMap reverseStatusCodeMap_;

		OpcUaStatusCodeMap(void);
		~OpcUaStatusCodeMap(void);
	};

	class DLLEXPORT OpcUaStatusCodeArray
	: public OpcUaArray<OpcUaStatusCode, EnumTypeCoder<OpcUaStatusCode> >
	{
	  public:
		typedef boost::shared_ptr<OpcUaStatusCodeArray> SPtr;
	};

};

#endif

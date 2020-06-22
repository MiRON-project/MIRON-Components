

#ifndef _SIMPLEWANTEDPEOPLEPUSHSERVICEINHANDLERWantedPersonFound_HH
#define _SIMPLEWANTEDPEOPLEPUSHSERVICEINHANDLERWantedPersonFound_HH

#include "SimpleWantedPeoplePushServiceInHandlerWantedPersonFoundCore.hh"
#include <RoqmeWriterImpl.h>
	
class SimpleWantedPeoplePushServiceInHandlerWantedPersonFound : public SimpleWantedPeoplePushServiceInHandlerWantedPersonFoundCore
{		
public:
	SimpleWantedPeoplePushServiceInHandlerWantedPersonFound(Smart::InputSubject<CommObjectRecognitionObjects::SimpleRecognitionState> *subject, const int &prescaleFactor=1);
	virtual ~SimpleWantedPeoplePushServiceInHandlerWantedPersonFound();
	
	virtual void on_SimpleWantedPeoplePushServiceInWantedPersonFound(const CommObjectRecognitionObjects::SimpleRecognitionState &input);
	
private:
	Roqme::RoqmeBoolWriter boolean_dw;
};

#endif

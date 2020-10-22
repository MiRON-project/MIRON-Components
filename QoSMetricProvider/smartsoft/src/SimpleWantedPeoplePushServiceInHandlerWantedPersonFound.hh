

#ifndef _SIMPLEWANTEDPEOPLEPUSHSERVICEINHANDLERWantedPersonFound_HH
#define _SIMPLEWANTEDPEOPLEPUSHSERVICEINHANDLERWantedPersonFound_HH

#include "SimpleWantedPeoplePushServiceInHandlerWantedPersonFoundCore.hh"
#include <RoqmeWriterImpl.h>
#ifdef ROQME_DEBUG
#include <RoqmeDebug.h>
#endif
	
class SimpleWantedPeoplePushServiceInHandlerWantedPersonFound : public SimpleWantedPeoplePushServiceInHandlerWantedPersonFoundCore
{		
public:
	SimpleWantedPeoplePushServiceInHandlerWantedPersonFound(Smart::InputSubject<CommObjectRecognitionObjects::SimpleRecognitionState> *subject, const int &prescaleFactor=1);
	virtual ~SimpleWantedPeoplePushServiceInHandlerWantedPersonFound();
	
	virtual void on_SimpleWantedPeoplePushServiceInWantedPersonFound(const CommObjectRecognitionObjects::SimpleRecognitionState &input);
	
private:
	Roqme::RoqmeBoolWriter boolean_dw;
	bool previous_value;
#ifdef ROQME_DEBUG
	Roqme::RoqmeDebug roqmeOut;
#endif
};

#endif

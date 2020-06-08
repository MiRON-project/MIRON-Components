

#ifndef _PEOPLEEVENTBUMPINHANDLERPersonBump_HH
#define _PEOPLEEVENTBUMPINHANDLERPersonBump_HH

#include "PeopleEventBumpInHandlerPersonBumpCore.hh"
#include <RoqmeWriterImpl.h>
	
class PeopleEventBumpInHandlerPersonBump : public PeopleEventBumpInHandlerPersonBumpCore
{		
public:
	PeopleEventBumpInHandlerPersonBump(Smart::InputSubject<Smart::EventInputType<CommObjectRecognitionObjects::CommObjectRecognitionEventBumpResult>> *subject, const int &prescaleFactor=1);
	virtual ~PeopleEventBumpInHandlerPersonBump();
	
	virtual void on_PeopleEventBumpInPersonBump(const Smart::EventInputType<CommObjectRecognitionObjects::CommObjectRecognitionEventBumpResult> &input);
	
private:
	Roqme::RoqmeEnumWriter enum_dw;
};

#endif

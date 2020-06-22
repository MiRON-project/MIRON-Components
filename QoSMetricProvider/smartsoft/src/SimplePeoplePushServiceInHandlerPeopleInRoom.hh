

#ifndef _SIMPLEPEOPLEPUSHSERVICEINHANDLERPeopleInRoom_HH
#define _SIMPLEPEOPLEPUSHSERVICEINHANDLERPeopleInRoom_HH

#include "SimplePeoplePushServiceInHandlerPeopleInRoomCore.hh"
#include <RoqmeWriterImpl.h>
	
class SimplePeoplePushServiceInHandlerPeopleInRoom : public SimplePeoplePushServiceInHandlerPeopleInRoomCore
{		
public:
	SimplePeoplePushServiceInHandlerPeopleInRoom(Smart::InputSubject<CommObjectRecognitionObjects::SimpleRecognitionState> *subject, const int &prescaleFactor=1);
	virtual ~SimplePeoplePushServiceInHandlerPeopleInRoom();
	
	virtual void on_SimplePeoplePushServiceInPeopleInRoom(const CommObjectRecognitionObjects::SimpleRecognitionState &input);
	
private:
	Roqme::RoqmeBoolWriter boolean_dw;
};

#endif



#ifndef _SIMPLEBUMPERSERVICEINHANDLERRobotBump_HH
#define _SIMPLEBUMPERSERVICEINHANDLERRobotBump_HH

#include "SimpleBumperServiceInHandlerRobotBumpCore.hh"
#include <RoqmeWriterImpl.h>
#ifdef ROQME_DEBUG
#include <RoqmeDebug.h>
#endif
	
class SimpleBumperServiceInHandlerRobotBump : public SimpleBumperServiceInHandlerRobotBumpCore
{		
public:
	SimpleBumperServiceInHandlerRobotBump(Smart::InputSubject<CommBasicObjects::SimpleBumpState> *subject, const int &prescaleFactor=1);
	virtual ~SimpleBumperServiceInHandlerRobotBump();
	
	virtual void on_SimpleBumperServiceInRobotBump(const CommBasicObjects::SimpleBumpState &input);
	
private:
	Roqme::RoqmeBoolWriter boolean_dw;
	bool previous_value;
#ifdef ROQME_DEBUG
	Roqme::RoqmeDebug roqmeOut;
#endif
};

#endif

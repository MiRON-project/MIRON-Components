

#ifndef _SIMPLEOBJECTBUMPPUSHSERVICEINHANDLERObjectBump_HH
#define _SIMPLEOBJECTBUMPPUSHSERVICEINHANDLERObjectBump_HH

#include "SimpleObjectBumpPushServiceInHandlerObjectBumpCore.hh"
#include <RoqmeWriterImpl.h>
#ifdef ROQME_DEBUG
#include <RoqmeDebug.h>
#endif
	
class SimpleObjectBumpPushServiceInHandlerObjectBump : public SimpleObjectBumpPushServiceInHandlerObjectBumpCore
{		
public:
	SimpleObjectBumpPushServiceInHandlerObjectBump(Smart::InputSubject<CommBasicObjects::SimpleBumpState> *subject, const int &prescaleFactor=1);
	virtual ~SimpleObjectBumpPushServiceInHandlerObjectBump();
	
	virtual void on_SimpleObjectBumpPushServiceInObjectBump(const CommBasicObjects::SimpleBumpState &input);
	
private:
	Roqme::RoqmeBoolWriter boolean_dw;
	bool previous_value;
#ifdef ROQME_DEBUG
	Roqme::RoqmeDebug roqmeOut;
#endif
};

#endif



#ifndef _SIMPLEOBJECTBUMPPUSHSERVICEINHANDLERObjectBump_HH
#define _SIMPLEOBJECTBUMPPUSHSERVICEINHANDLERObjectBump_HH

#include "SimpleObjectBumpPushServiceInHandlerObjectBumpCore.hh"
#include <RoqmeWriterImpl.h>
	
class SimpleObjectBumpPushServiceInHandlerObjectBump : public SimpleObjectBumpPushServiceInHandlerObjectBumpCore
{		
public:
	SimpleObjectBumpPushServiceInHandlerObjectBump(Smart::InputSubject<CommBasicObjects::SimpleBumpState> *subject, const int &prescaleFactor=1);
	virtual ~SimpleObjectBumpPushServiceInHandlerObjectBump();
	
	virtual void on_SimpleObjectBumpPushServiceInObjectBump(const CommBasicObjects::SimpleBumpState &input);
	
private:
	Roqme::RoqmeBoolWriter boolean_dw;
};

#endif

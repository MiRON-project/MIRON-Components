

#ifndef _SIMPLEPEOPLEBUMPPUSHSERVICEINHANDLERPersonBump_HH
#define _SIMPLEPEOPLEBUMPPUSHSERVICEINHANDLERPersonBump_HH

#include "SimplePeopleBumpPushServiceInHandlerPersonBumpCore.hh"
#include <RoqmeWriterImpl.h>
	
class SimplePeopleBumpPushServiceInHandlerPersonBump : public SimplePeopleBumpPushServiceInHandlerPersonBumpCore
{		
public:
	SimplePeopleBumpPushServiceInHandlerPersonBump(Smart::InputSubject<CommBasicObjects::SimpleBumpState> *subject, const int &prescaleFactor=1);
	virtual ~SimplePeopleBumpPushServiceInHandlerPersonBump();
	
	virtual void on_SimplePeopleBumpPushServiceInPersonBump(const CommBasicObjects::SimpleBumpState &input);
	
private:
	Roqme::RoqmeBoolWriter boolean_dw;
};

#endif

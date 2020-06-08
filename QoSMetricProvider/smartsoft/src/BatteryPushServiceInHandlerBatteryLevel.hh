

#ifndef _BATTERYPUSHSERVICEINHANDLERBatteryLevel_HH
#define _BATTERYPUSHSERVICEINHANDLERBatteryLevel_HH

#include "BatteryPushServiceInHandlerBatteryLevelCore.hh"
#include <RoqmeWriterImpl.h>
	
class BatteryPushServiceInHandlerBatteryLevel : public BatteryPushServiceInHandlerBatteryLevelCore
{		
public:
	BatteryPushServiceInHandlerBatteryLevel(Smart::InputSubject<CommBasicObjects::CommBatteryLevel> *subject, const int &prescaleFactor=1);
	virtual ~BatteryPushServiceInHandlerBatteryLevel();
	
	virtual void on_BatteryPushServiceInBatteryLevel(const CommBasicObjects::CommBatteryLevel &input);
	
private:
	Roqme::RoqmeIntWriter int32_dw;
};

#endif

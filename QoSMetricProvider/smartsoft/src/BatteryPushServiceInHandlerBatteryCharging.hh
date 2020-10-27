

#ifndef _BATTERYPUSHSERVICEINHANDLERBatteryCharging_HH
#define _BATTERYPUSHSERVICEINHANDLERBatteryCharging_HH

#include "BatteryPushServiceInHandlerBatteryChargingCore.hh"
#include <RoqmeWriterImpl.h>
#ifdef ROQME_DEBUG
#include <RoqmeDebug.h>
#endif
	
class BatteryPushServiceInHandlerBatteryCharging : public BatteryPushServiceInHandlerBatteryChargingCore
{		
public:
	BatteryPushServiceInHandlerBatteryCharging(Smart::InputSubject<CommBasicObjects::CommBatteryLevel> *subject, const int &prescaleFactor=1);
	virtual ~BatteryPushServiceInHandlerBatteryCharging();
	
	virtual void on_BatteryPushServiceInBatteryCharging(const CommBasicObjects::CommBatteryLevel &input);
	
private:
	Roqme::RoqmeBoolWriter boolean_dw;
#ifdef ROQME_DEBUG
	Roqme::RoqmeDebug roqmeOut;
#endif
	bool previous_value;
};

#endif

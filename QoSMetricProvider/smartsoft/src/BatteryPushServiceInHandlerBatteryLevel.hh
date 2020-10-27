

#ifndef _BATTERYPUSHSERVICEINHANDLERBatteryLevel_HH
#define _BATTERYPUSHSERVICEINHANDLERBatteryLevel_HH

#include "BatteryPushServiceInHandlerBatteryLevelCore.hh"
#include <RoqmeWriterImpl.h>
#ifdef ROQME_DEBUG
#include <RoqmeDebug.h>
#endif
	
class BatteryPushServiceInHandlerBatteryLevel : public BatteryPushServiceInHandlerBatteryLevelCore
{		
public:
	BatteryPushServiceInHandlerBatteryLevel(Smart::InputSubject<CommBasicObjects::CommBatteryLevel> *subject, const int &prescaleFactor=1);
	virtual ~BatteryPushServiceInHandlerBatteryLevel();
	
	virtual void on_BatteryPushServiceInBatteryLevel(const CommBasicObjects::CommBatteryLevel &input);
	
private:
	Roqme::RoqmeDoubleWriter contextWr;
#ifdef ROQME_DEBUG
	Roqme::RoqmeDebug roqmeOut;
#endif
	double previous_value;
};

#endif

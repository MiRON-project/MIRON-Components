 
#include "BatteryPushServiceInHandlerBatteryCharging.hh"
#include <iostream>
#include <chrono>

BatteryPushServiceInHandlerBatteryCharging::BatteryPushServiceInHandlerBatteryCharging(Smart::InputSubject<CommBasicObjects::CommBatteryLevel> *subject, const int &prescaleFactor)
:	BatteryPushServiceInHandlerBatteryChargingCore(subject, prescaleFactor)
{
	std::cout << "constructor BatteryPushServiceInHandler\n";
}
BatteryPushServiceInHandlerBatteryCharging::~BatteryPushServiceInHandlerBatteryCharging() 
{
	std::cout << "destructor BatteryPushServiceInHandlerBatteryCharging\n";
}

void BatteryPushServiceInHandlerBatteryCharging::on_BatteryPushServiceInBatteryCharging(const CommBasicObjects::CommBatteryLevel &input)
{
	
	try
	{
		RoqmeDDSTopics::RoqmeBoolContext booleanContext;
		booleanContext.name("BatteryCharging");
		booleanContext.value().push_back(input.getExternalPower());
		unsigned long long now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		std::cout << now << " - BatteryCharging - " << input.getExternalPower() << std::endl;
		boolean_dw.write(booleanContext);
	}
	catch(Roqme::RoqmeDDSException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}

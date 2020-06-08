 
#include "BatteryPushServiceInHandlerBatteryLevel.hh"
#include <iostream>

BatteryPushServiceInHandlerBatteryLevel::BatteryPushServiceInHandlerBatteryLevel(Smart::InputSubject<CommBasicObjects::CommBatteryLevel> *subject, const int &prescaleFactor)
:	BatteryPushServiceInHandlerBatteryLevelCore(subject, prescaleFactor)
{
	std::cout << "constructor BatteryPushServiceInHandler\n";
}
BatteryPushServiceInHandlerBatteryLevel::~BatteryPushServiceInHandlerBatteryLevel() 
{
	std::cout << "destructor BatteryPushServiceInHandlerBatteryLevel\n";
}

void BatteryPushServiceInHandlerBatteryLevel::on_BatteryPushServiceInBatteryLevel(const CommBasicObjects::CommBatteryLevel &input)
{
	
	try
	{
		RoqmeDDSTopics::RoqmeIntContext int32Context;
		int32Context.name("BatteryLevel");
		int32Context.value().push_back(input.getChargeLevel());
		std::cout << "Publishing data context" << std::endl;
		int32_dw.write(int32Context);
	}
	catch(Roqme::RoqmeDDSException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}

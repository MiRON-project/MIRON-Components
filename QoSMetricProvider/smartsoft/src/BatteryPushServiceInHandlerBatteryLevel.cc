 
#include "BatteryPushServiceInHandlerBatteryLevel.hh"
#include <iostream>
#include <chrono>

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
		RoqmeDDSTopics::RoqmeDoubleContext int32Context;
		int32Context.name("BatteryLevel");
		int32Context.value().push_back(input.getChargeLevel());
		unsigned long long now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		std::cout << now << " - BatteryLevel - " << input.getChargeLevel() << std::endl;
		int32_dw.write(int32Context);
	}
	catch(Roqme::RoqmeDDSException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}

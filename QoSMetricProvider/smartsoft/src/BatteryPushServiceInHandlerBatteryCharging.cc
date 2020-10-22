 
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

	
	static bool first_execution = true;
	bool current_value = input.getExternalPower();
	if(first_execution || (!first_execution && previous_value != current_value))
	{
		try
		{
			RoqmeDDSTopics::RoqmeBoolContext booleanContext;
			booleanContext.name("BatteryCharging");
			booleanContext.value().push_back(current_value);
			boolean_dw.write(booleanContext);
#ifdef ROQME_DEBUG
			if(input.getExternalPower())
				roqmeOut.roqmeDebug(Roqme::RoqmeDebug::ContextType::BOOLEAN, "BatteryCharging", "true");
			else
				roqmeOut.roqmeDebug(Roqme::RoqmeDebug::ContextType::BOOLEAN, "BatteryCharging", "false");
#else
			unsigned long long now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
			std::cout << now << " - BatteryCharging - " << input.getExternalPower() << std::endl;
#endif
			previous_value = current_value;
			first_execution = false;
		}
		catch(Roqme::RoqmeDDSException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	
	

}

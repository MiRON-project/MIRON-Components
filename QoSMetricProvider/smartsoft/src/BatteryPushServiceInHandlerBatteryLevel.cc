 
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
	
	static bool first_execution = true;
	double current_value = input.getChargeLevel();

	if(first_execution || (!first_execution && previous_value != current_value))
	{
		try
		{
			RoqmeDDSTopics::RoqmeDoubleContext context;
			context.name("BatteryLevel");
			context.value().push_back(current_value);
			contextWr.write(context);
			std::stringstream ss;
			ss << input.getChargeLevel();
#ifdef ROQME_DEBUG
			roqmeOut.roqmeDebug(Roqme::RoqmeDebug::ContextType::DOUBLE, "BatteryLevel", ss.str());
#else
			unsigned long long now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
			std::cout << now << " - BatteryLevel - " << input.getChargeLevel() << std::endl;
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

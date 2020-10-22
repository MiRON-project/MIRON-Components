 
#include "SimpleBumperServiceInHandlerRobotBump.hh"
#include <iostream>
#include <chrono>

SimpleBumperServiceInHandlerRobotBump::SimpleBumperServiceInHandlerRobotBump(Smart::InputSubject<CommBasicObjects::SimpleBumpState> *subject, const int &prescaleFactor)
:	SimpleBumperServiceInHandlerRobotBumpCore(subject, prescaleFactor)
{
	std::cout << "constructor SimpleBumperServiceInHandler\n";
}
SimpleBumperServiceInHandlerRobotBump::~SimpleBumperServiceInHandlerRobotBump() 
{
	std::cout << "destructor SimpleBumperServiceInHandlerRobotBump\n";
}

void SimpleBumperServiceInHandlerRobotBump::on_SimpleBumperServiceInRobotBump(const CommBasicObjects::SimpleBumpState &input)
{
	
	static bool first_execution = true;
	bool current_value = input.getIs_bumped();

	try
	{
		if(first_execution || (!first_execution && previous_value != current_value))
		{
			RoqmeDDSTopics::RoqmeBoolContext booleanContext;
			booleanContext.name("RobotBump");
			booleanContext.value().push_back(input.getIs_bumped());
			boolean_dw.write(booleanContext);
#ifdef ROQME_DEBUG
			if(input.getIs_bumped())
				roqmeOut.roqmeDebug(Roqme::RoqmeDebug::ContextType::BOOLEAN, "RobotBump", "true");
			else
				roqmeOut.roqmeDebug(Roqme::RoqmeDebug::ContextType::BOOLEAN, "RobotBump", "false");
#else
			unsigned long long now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
			std::cout << now << " - RobotBump - " << input.getIs_bumped() << std::endl;
#endif
			previous_value = current_value;
			first_execution = false;
		}
	}
	catch(Roqme::RoqmeDDSException& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

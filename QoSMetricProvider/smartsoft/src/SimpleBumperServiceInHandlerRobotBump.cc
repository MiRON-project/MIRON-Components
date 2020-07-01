 
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
	
	try
	{
		RoqmeDDSTopics::RoqmeBoolContext booleanContext;
		booleanContext.name("RobotBump");
		booleanContext.value().push_back(input.getIs_bumped());
		unsigned long long now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		std::cout << now << " - RobotBump - " << input.getIs_bumped() << std::endl;
		boolean_dw.write(booleanContext);
	}
	catch(Roqme::RoqmeDDSException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}

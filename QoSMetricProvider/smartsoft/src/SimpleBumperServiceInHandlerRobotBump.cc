 
#include "SimpleBumperServiceInHandlerRobotBump.hh"
#include <iostream>

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
		std::cout << "Publishing data context" << std::endl;
		boolean_dw.write(booleanContext);
	}
	catch(Roqme::RoqmeDDSException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}

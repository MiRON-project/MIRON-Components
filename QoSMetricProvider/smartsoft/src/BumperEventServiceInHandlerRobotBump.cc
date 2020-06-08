 
#include "BumperEventServiceInHandlerRobotBump.hh"
#include <iostream>

BumperEventServiceInHandlerRobotBump::BumperEventServiceInHandlerRobotBump(Smart::InputSubject<Smart::EventInputType<CommBasicObjects::CommBumperEventResult>> *subject, const int &prescaleFactor)
:	BumperEventServiceInHandlerRobotBumpCore(subject, prescaleFactor)
{
	std::cout << "constructor BumperEventServiceInHandler\n";
}
BumperEventServiceInHandlerRobotBump::~BumperEventServiceInHandlerRobotBump() 
{
	std::cout << "destructor BumperEventServiceInHandlerRobotBump\n";
}

void BumperEventServiceInHandlerRobotBump::on_BumperEventServiceInRobotBump(const Smart::EventInputType<CommBasicObjects::CommBumperEventResult> &input)
{
	
	try
	{
		RoqmeDDSTopics::RoqmeEnumContext enumContext;
		enumContext.name("RobotBump");
		enumContext.value().push_back(input.event.getState().to_string());
		std::cout << "Publishing data context" << std::endl;
		enum_dw.write(enumContext);
	}
	catch(Roqme::RoqmeDDSException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}

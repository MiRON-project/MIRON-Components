 
#include "SimpleObjectBumpPushServiceInHandlerObjectBump.hh"
#include <iostream>

SimpleObjectBumpPushServiceInHandlerObjectBump::SimpleObjectBumpPushServiceInHandlerObjectBump(Smart::InputSubject<CommBasicObjects::SimpleBumpState> *subject, const int &prescaleFactor)
:	SimpleObjectBumpPushServiceInHandlerObjectBumpCore(subject, prescaleFactor)
{
	std::cout << "constructor SimpleObjectBumpPushServiceInHandler\n";
}
SimpleObjectBumpPushServiceInHandlerObjectBump::~SimpleObjectBumpPushServiceInHandlerObjectBump() 
{
	std::cout << "destructor SimpleObjectBumpPushServiceInHandlerObjectBump\n";
}

void SimpleObjectBumpPushServiceInHandlerObjectBump::on_SimpleObjectBumpPushServiceInObjectBump(const CommBasicObjects::SimpleBumpState &input)
{
	
	try
	{
		RoqmeDDSTopics::RoqmeBoolContext booleanContext;
		booleanContext.name("ObjectBump");
		booleanContext.value().push_back(input.getIs_bumped());
		std::cout << "Publishing data context" << std::endl;
		boolean_dw.write(booleanContext);
	}
	catch(Roqme::RoqmeDDSException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}

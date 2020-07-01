 
#include "SimpleObjectBumpPushServiceInHandlerObjectBump.hh"
#include <iostream>
#include <chrono>

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
		unsigned long long now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		std::cout << now << " - ObjectBump - " << input.getIs_bumped() << std::endl;
		boolean_dw.write(booleanContext);
	}
	catch(Roqme::RoqmeDDSException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}

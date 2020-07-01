 
#include "SimplePeopleBumpPushServiceInHandlerPersonBump.hh"
#include <iostream>
#include <chrono>

SimplePeopleBumpPushServiceInHandlerPersonBump::SimplePeopleBumpPushServiceInHandlerPersonBump(Smart::InputSubject<CommBasicObjects::SimpleBumpState> *subject, const int &prescaleFactor)
:	SimplePeopleBumpPushServiceInHandlerPersonBumpCore(subject, prescaleFactor)
{
	std::cout << "constructor SimplePeopleBumpPushServiceInHandler\n";
}
SimplePeopleBumpPushServiceInHandlerPersonBump::~SimplePeopleBumpPushServiceInHandlerPersonBump() 
{
	std::cout << "destructor SimplePeopleBumpPushServiceInHandlerPersonBump\n";
}

void SimplePeopleBumpPushServiceInHandlerPersonBump::on_SimplePeopleBumpPushServiceInPersonBump(const CommBasicObjects::SimpleBumpState &input)
{
	
	try
	{
		RoqmeDDSTopics::RoqmeBoolContext booleanContext;
		booleanContext.name("PersonBump");
		booleanContext.value().push_back(input.getIs_bumped());
		unsigned long long now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		std::cout << now << " - PersonBump - " << input.getIs_bumped() << std::endl;
		boolean_dw.write(booleanContext);
	}
	catch(Roqme::RoqmeDDSException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}

 
#include "SimplePeopleBumpPushServiceInHandlerPersonBump.hh"
#include <iostream>

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
		std::cout << "Publishing data context" << std::endl;
		boolean_dw.write(booleanContext);
	}
	catch(Roqme::RoqmeDDSException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}

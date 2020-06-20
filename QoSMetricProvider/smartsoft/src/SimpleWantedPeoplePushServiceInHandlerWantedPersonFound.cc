 
#include "SimpleWantedPeoplePushServiceInHandlerWantedPersonFound.hh"
#include <iostream>

SimpleWantedPeoplePushServiceInHandlerWantedPersonFound::SimpleWantedPeoplePushServiceInHandlerWantedPersonFound(Smart::InputSubject<CommObjectRecognitionObjects::SimpleRecognitionState> *subject, const int &prescaleFactor)
:	SimpleWantedPeoplePushServiceInHandlerWantedPersonFoundCore(subject, prescaleFactor)
{
	std::cout << "constructor SimpleWantedPeoplePushServiceInHandler\n";
}
SimpleWantedPeoplePushServiceInHandlerWantedPersonFound::~SimpleWantedPeoplePushServiceInHandlerWantedPersonFound() 
{
	std::cout << "destructor SimpleWantedPeoplePushServiceInHandlerWantedPersonFound\n";
}

void SimpleWantedPeoplePushServiceInHandlerWantedPersonFound::on_SimpleWantedPeoplePushServiceInWantedPersonFound(const CommObjectRecognitionObjects::SimpleRecognitionState &input)
{
	
	try
	{
		RoqmeDDSTopics::RoqmeBoolContext booleanContext;
		booleanContext.name("WantedPersonFound");
		booleanContext.value().push_back(input.getIs_visible());
		std::cout << "Publishing data context" << std::endl;
		boolean_dw.write(booleanContext);
	}
	catch(Roqme::RoqmeDDSException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}

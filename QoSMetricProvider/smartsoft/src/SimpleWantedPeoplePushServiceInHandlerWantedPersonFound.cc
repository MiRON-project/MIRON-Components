 
#include "SimpleWantedPeoplePushServiceInHandlerWantedPersonFound.hh"
#include <iostream>
#include <chrono>

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
		unsigned long long now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		std::cout << now << " - WantedPersonFound - " << input.getIs_visible() << std::endl;
		boolean_dw.write(booleanContext);
	}
	catch(Roqme::RoqmeDDSException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}

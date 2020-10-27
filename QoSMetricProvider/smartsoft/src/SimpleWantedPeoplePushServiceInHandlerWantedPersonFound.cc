 
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
	static bool first_execution = true;
	bool current_value = input.getIs_visible();

	if(first_execution || (!first_execution && previous_value != current_value)){
		try
		{
			RoqmeDDSTopics::RoqmeBoolContext booleanContext;
			booleanContext.name("WantedPersonFound");
			booleanContext.value().push_back(input.getIs_visible());
			boolean_dw.write(booleanContext);
#ifdef ROQME_DEBUG
			if(input.getIs_visible())
				roqmeOut.roqmeDebug(Roqme::RoqmeDebug::ContextType::BOOLEAN, "WantedPersonFound", "true");
			else
				roqmeOut.roqmeDebug(Roqme::RoqmeDebug::ContextType::BOOLEAN, "WantedPersonFound", "false");
#else
			unsigned long long now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
			std::cout << now << " - WantedPersonFound - " << input.getIs_visible() << std::endl;
#endif
			previous_value = current_value;
			first_execution = false;
		}
		catch(Roqme::RoqmeDDSException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

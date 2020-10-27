 
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
	static bool first_execution = true;
	bool current_value = input.getIs_bumped();

	if(first_execution || (!first_execution && previous_value != current_value)){
		try
		{
			RoqmeDDSTopics::RoqmeBoolContext booleanContext;
			booleanContext.name("PersonBump");
			booleanContext.value().push_back(input.getIs_bumped());
			boolean_dw.write(booleanContext);
#ifdef ROQME_DEBUG
			if(input.getIs_bumped())
				roqmeOut.roqmeDebug(Roqme::RoqmeDebug::ContextType::BOOLEAN, "PersonBump", "true");
			else
				roqmeOut.roqmeDebug(Roqme::RoqmeDebug::ContextType::BOOLEAN, "PersonBump", "false");
#else
			unsigned long long now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
			std::cout << now << " - PersonBump - " << input.getIs_bumped() << std::endl;
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

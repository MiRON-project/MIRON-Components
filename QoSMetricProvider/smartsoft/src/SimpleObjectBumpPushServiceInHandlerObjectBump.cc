 
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
	static bool first_execution = true;
	bool current_value = input.getIs_bumped();

	if(first_execution || (!first_execution && previous_value != current_value))
	{
		try
		{
			RoqmeDDSTopics::RoqmeBoolContext booleanContext;
			booleanContext.name("ObjectBump");
			booleanContext.value().push_back(input.getIs_bumped());

			boolean_dw.write(booleanContext);
#ifdef ROQME_DEBUG
			if(input.getIs_bumped())
				roqmeOut.roqmeDebug(Roqme::RoqmeDebug::ContextType::BOOLEAN, "ObjectBump", "true");
			else
				roqmeOut.roqmeDebug(Roqme::RoqmeDebug::ContextType::BOOLEAN, "ObjectBump", "false");
#else
			unsigned long long now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
			std::cout << now << " - ObjectBump - " << input.getIs_bumped() << std::endl;
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

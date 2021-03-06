 
#include "SimplePeoplePushServiceInHandlerPeopleInRoom.hh"
#include <iostream>
#include <chrono>

SimplePeoplePushServiceInHandlerPeopleInRoom::SimplePeoplePushServiceInHandlerPeopleInRoom(Smart::InputSubject<CommObjectRecognitionObjects::SimpleRecognitionState> *subject, const int &prescaleFactor)
:	SimplePeoplePushServiceInHandlerPeopleInRoomCore(subject, prescaleFactor)
{
	std::cout << "constructor SimplePeoplePushServiceInHandler\n";
}
SimplePeoplePushServiceInHandlerPeopleInRoom::~SimplePeoplePushServiceInHandlerPeopleInRoom() 
{
	std::cout << "destructor SimplePeoplePushServiceInHandlerPeopleInRoom\n";
}

void SimplePeoplePushServiceInHandlerPeopleInRoom::on_SimplePeoplePushServiceInPeopleInRoom(const CommObjectRecognitionObjects::SimpleRecognitionState &input)
{
	/*
	try
	{
		RoqmeDDSTopics::RoqmeBoolContext booleanContext;
		booleanContext.name("PeopleInRoom");
		booleanContext.value().push_back(input.getIs_visible());
		boolean_dw.write(booleanContext);
		unsigned long long now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		std::cout << now << " - PeopleInRoom - " << input.getIs_visible() << std::endl;
	}
	catch(Roqme::RoqmeDDSException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	*/
	
}

 
#include "SimplePeoplePushServiceInHandlerPeopleInRoom.hh"
#include <iostream>

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
	
	try
	{
		RoqmeDDSTopics::RoqmeBoolContext booleanContext;
		booleanContext.name("PeopleInRoom");
		booleanContext.value().push_back(input.getIs_visible());
		std::cout << "Publishing data context" << std::endl;
		boolean_dw.write(booleanContext);
	}
	catch(Roqme::RoqmeDDSException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}

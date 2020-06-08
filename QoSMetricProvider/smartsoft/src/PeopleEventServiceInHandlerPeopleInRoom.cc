 
#include "PeopleEventServiceInHandlerPeopleInRoom.hh"
#include <iostream>

PeopleEventServiceInHandlerPeopleInRoom::PeopleEventServiceInHandlerPeopleInRoom(Smart::InputSubject<Smart::EventInputType<CommObjectRecognitionObjects::CommObjectRecognitionEventResult>> *subject, const int &prescaleFactor)
:	PeopleEventServiceInHandlerPeopleInRoomCore(subject, prescaleFactor)
{
	std::cout << "constructor PeopleEventServiceInHandler\n";
}
PeopleEventServiceInHandlerPeopleInRoom::~PeopleEventServiceInHandlerPeopleInRoom() 
{
	std::cout << "destructor PeopleEventServiceInHandlerPeopleInRoom\n";
}

void PeopleEventServiceInHandlerPeopleInRoom::on_PeopleEventServiceInPeopleInRoom(const Smart::EventInputType<CommObjectRecognitionObjects::CommObjectRecognitionEventResult> &input)
{
	
	try
	{
		RoqmeDDSTopics::RoqmeEnumContext enumContext;
		enumContext.name("PeopleInRoom");
		enumContext.value().push_back(input.event.getState().to_string());
		std::cout << "Publishing data context" << std::endl;
		enum_dw.write(enumContext);
	}
	catch(Roqme::RoqmeDDSException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}

 
#include "ObjectEventBumpInHandlerObjectBump.hh"
#include <iostream>

ObjectEventBumpInHandlerObjectBump::ObjectEventBumpInHandlerObjectBump(Smart::InputSubject<Smart::EventInputType<CommObjectRecognitionObjects::CommObjectRecognitionEventBumpResult>> *subject, const int &prescaleFactor)
:	ObjectEventBumpInHandlerObjectBumpCore(subject, prescaleFactor)
{
	std::cout << "constructor ObjectEventBumpInHandler\n";
}
ObjectEventBumpInHandlerObjectBump::~ObjectEventBumpInHandlerObjectBump() 
{
	std::cout << "destructor ObjectEventBumpInHandlerObjectBump\n";
}

void ObjectEventBumpInHandlerObjectBump::on_ObjectEventBumpInObjectBump(const Smart::EventInputType<CommObjectRecognitionObjects::CommObjectRecognitionEventBumpResult> &input)
{
	
	try
	{
		RoqmeDDSTopics::RoqmeEnumContext enumContext;
		enumContext.name("ObjectBump");
		enumContext.value().push_back(input.event.getState().to_string());
		std::cout << "Publishing data context ObjectBump: " << input.event.getState().to_string() << 
			" | type: " << typeid(input.event.getState().to_string()).name() << std::endl;
		enum_dw.write(enumContext);
	}
	catch(Roqme::RoqmeDDSException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}

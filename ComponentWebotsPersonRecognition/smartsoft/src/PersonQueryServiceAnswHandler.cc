//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain
// The SmartSoft Toolchain has been developed by:
//  
// Service Robotics Research Center
// University of Applied Sciences Ulm
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// www.servicerobotik-ulm.de
//
// This file is generated once. Modify this file to your needs. 
// If you want the toolchain to re-generate this file, please 
// delete it before running the code generator.
//--------------------------------------------------------------------------
#include "PersonQueryServiceAnswHandler.hh"
#include "ComponentWebotsPersonRecognition.hh"

PersonQueryServiceAnswHandler::PersonQueryServiceAnswHandler(IQueryServer *server)
:	PersonQueryServiceAnswHandlerCore(server)
{
}

void PersonQueryServiceAnswHandler::on_update_from(const RecognitionTask* recognitionTask)
{
	COMP->mutex.acquire();
	_people = recognitionTask->getPeople();
	COMP->mutex.release();
}

void PersonQueryServiceAnswHandler::handleQuery(const Smart::QueryIdPtr &id, const CommObjectRecognitionObjects::CommPersonRecognitionId& request) 
{
	CommObjectRecognitionObjects::CommPerson answer;
	for (size_t i = 0; i < _people.getPeopleSize(); ++i)
	{
		auto person = _people.getPeopleElemAtPos(i);
		if (person.getId() == request.getId() || 
			person.getName() == request.getName())
		{
			this->server->answer(id, person);
			return;
		}
	}
	answer.setName("NIL");
	this->server->answer(id, answer);
}

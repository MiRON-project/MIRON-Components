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
#include "ObjectPlacementQueryServiceAnswHandler.hh"
#include "ComponentWebotsHRI.hh"

ObjectPlacementQueryServiceAnswHandler::ObjectPlacementQueryServiceAnswHandler(IQueryServer *server)
:	ObjectPlacementQueryServiceAnswHandlerCore(server)
{
	
}

void ObjectPlacementQueryServiceAnswHandler::on_update_from(const SpeechTask* speechTask)
{}

void ObjectPlacementQueryServiceAnswHandler::handleQuery(const Smart::QueryIdPtr &id, const DomainSpeech::CommObjectPlacementOutputMessage& request) 
{
	COMP->obj_place_msg = request;
	CommBasicObjects::CommBool answer;
	answer.setBoolValue(true);
	this->server->answer(id, answer);
}

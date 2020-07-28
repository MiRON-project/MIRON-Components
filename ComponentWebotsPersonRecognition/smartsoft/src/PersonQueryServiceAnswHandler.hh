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
#ifndef _PERSONQUERYSERVICEANSWHANDLER_USER_HH
#define _PERSONQUERYSERVICEANSWHANDLER_USER_HH
		
#include "PersonQueryServiceAnswHandlerCore.hh"
#include "RecognitionTask.hh"

class PersonQueryServiceAnswHandler : public PersonQueryServiceAnswHandlerCore
{

private:
	CommObjectRecognitionObjects::CommPeople _people;

protected:
	virtual void on_update_from(const RecognitionTask* recognitionTask);
public:
	PersonQueryServiceAnswHandler(IQueryServer *server);
	virtual ~PersonQueryServiceAnswHandler() = default;
	virtual void handleQuery(const QueryId &id, const CommObjectRecognitionObjects::CommPersonRecognitionId& request);
};
#endif

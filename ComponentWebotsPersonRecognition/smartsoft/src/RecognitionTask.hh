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
#ifndef _RECOGNITIONTASK_HH
#define _RECOGNITIONTASK_HH

#include "RecognitionTaskCore.hh"

#include <memory.h>
#include <jsoncpp/json/json.h>

#include "CommObjectRecognitionObjects/CommObjectDominantColor.hh"
#include "CommObjectRecognitionObjects/CommObjectRecognitionEnvironment.hh"
#include "CommObjectRecognitionObjects/CommPeople.hh"

#define COLOR_THRESHOLD 1e-2
#define DOMINANCE_THRESHOLD 1e-2

struct Person
{
	int id;
	std::string name;
	std::vector<CommObjectRecognitionObjects::CommObjectDominantColor> colors;
	bool unvisited = true;

	Person(){};
};

class RecognitionTask  : public RecognitionTaskCore
{
private:
	//! _people is the provided Json Database (json file)
	std::vector<Person> _people;
	
	//! _comm_people is the Query Database. It starts empty and is updated 
	//! from the environment 
	CommObjectRecognitionObjects::CommPeople _comm_people;
	
	SmartACE::SmartMutex mutex;

	int extractPeopleFromJson();
	void comparePeopleJson();
	bool checkColors(
		const Person& person,
		const CommObjectRecognitionObjects::
			CommObjectRecognitionObjectProperties& obj) const;
public:
	RecognitionTask(SmartACE::SmartComponent *comp);
	
	CommObjectRecognitionObjects::CommPeople getPeople() const 
		{return _comm_people; };

	virtual ~RecognitionTask();
	
	virtual int on_entry();
	virtual int on_execute();
	virtual int on_exit();
};

#endif

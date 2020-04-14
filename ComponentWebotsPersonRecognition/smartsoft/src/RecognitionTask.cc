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
#include "RecognitionTask.hh"
#include "ComponentWebotsPersonRecognition.hh"

#include <iostream>

RecognitionTask::RecognitionTask(SmartACE::SmartComponent *comp) 
:	RecognitionTaskCore(comp)
{
	std::cout << "constructor RecognitionTask\n";
	_comm_people.setIs_valid(false);
}
RecognitionTask::~RecognitionTask() 
{
	std::cout << "destructor RecognitionTask\n";
}



int RecognitionTask::on_entry()
{
	if (!COMP)
		return -1;
	
	if (COMP->getParameters().getRecognition_properties().getColor_base())
		return extractPeopleFromJson();

	return 0;
}
int RecognitionTask::on_execute()
{
	mutex.acquire();

	if (COMP->getParameters().getRecognition_properties().getColor_base())
		comparePeopleJson();


	mutex.release();
	return 0;
}
int RecognitionTask::on_exit()
{
	// use this method to clean-up resources which are initialized in on_entry() and needs to be freed before the on_execute() can be called again
	return 0;
}

int RecognitionTask::extractPeopleFromJson()
{
	Json::Value _config;
	std::ifstream file_input("people.json");
	if (!file_input.is_open())
	{
		std::cerr << "Can't open 'people.json' file." << std::endl;
		return -1;
	}

	Json::Reader reader;
	if (!reader.parse(file_input, _config))
	{
		std::cerr << "Invalid 'people.json' file." << std::endl;
		return -1;
	}

	if (!_config.isMember("people"))
	{
		std::cerr << "Missing or invalid 'name' key in 'configuration.json' file." << std::endl;
		return -1;
	}
	
	const Json::Value& people = _config["people"];
	for (int i = 0; i < people.size(); ++i)
	{
		Person _person;
		_person.id = people[i]["id"].asUInt();
		_person.name = people[i]["name"].asString();
		_person.unvisited = true;
		
		const Json::Value& colors = people[i]["color"];
		for (int j = 0; j < colors.size(); ++j)
		{
			CommObjectRecognitionObjects::CommObjectDominantColor color(
				{colors[j]["r"].asDouble(), colors[j]["g"].asDouble(),
				colors[j]["b"].asDouble(), colors[j]["dominance"].
				asDouble()});
			_person.colors.push_back(color);
		}
		_people.push_back(_person);
	}
}

void RecognitionTask::comparePeopleJson()
{
	CommObjectRecognitionObjects::CommObjectRecognitionEnvironment objs;
	Smart::StatusCode obj_status = objectsPushServiceInGetUpdate(objs);
	CommObjectRecognitionObjects::CommPeople comm_people;
	CommObjectRecognitionObjects::CommPerson comm_person;
	std::vector<CommObjectRecognitionObjects::CommPerson> people;

	if (obj_status != Smart::SMART_OK)
	{
		std::cout << "No Object for Recognition: " << obj_status 
		<< std::endl;
		return;
	}
	
	if (!objs.getIs_valid())
	{
		std::cout << "Not a valid object\n";
		return;
	}

	for (auto& obj : objs.getObjectsCopy())
	{
		if (obj.getObject_type() != "pedestrian")
			continue;

		for (auto& person : _people)
		{
			if (person.unvisited == true)
				if (checkColors(person, obj))
				{
					person.id = obj.getObject_id();
					person.unvisited = false;
					comm_person.setId(person.id);
					comm_person.setName(person.name);
					comm_person.setDimension(obj.getDimension());
					comm_person.setPose(obj.getPose());
					comm_person.setIs_valid(true);
					people.push_back(comm_person);
					break;
				}
				else
					continue;
			else
			{
				if (obj.getObject_id() != person.id)
					continue;
					
				else
				{
					comm_person.setId(person.id);
					comm_person.setName(person.name);
					comm_person.setDimension(obj.getDimension());
					comm_person.setPose(obj.getPose());
					comm_person.setIs_valid(true);
					people.push_back(comm_person);
					break;
				}
			}
		}
	}
	
	if (people.size() > 0)
		comm_people.setIs_valid(true);
	else
		comm_people.setIs_valid(false);
	comm_people.setPeople(people);
	_comm_people = comm_people;
	peoplePushServiceOutPut(comm_people);
}

bool RecognitionTask::checkColors(const Person& person,
	const CommObjectRecognitionObjects::CommObjectRecognitionObjectProperties& 
		obj) const
{
	if (person.colors.size() != obj.getObject_colorsSize())
		return false;

	for (size_t i = 0; i < obj.getObject_colorsSize(); ++i)
	{
		auto color = obj.getObject_colorsElemAtPos(i);
		if(abs(color.getR() - person.colors[i].getR()) >= COLOR_THRESHOLD ||
		abs(color.getB() - person.colors[i].getB()) >= COLOR_THRESHOLD ||
		abs(color.getG() - person.colors[i].getG()) >= COLOR_THRESHOLD ||
		abs(color.getDominance() - person.colors[i].getDominance()) >= 
			DOMINANCE_THRESHOLD)
			return false;
	}
	return true;
}
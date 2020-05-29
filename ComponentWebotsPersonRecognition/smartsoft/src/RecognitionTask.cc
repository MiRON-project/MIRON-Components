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

  person_bump_name_ = COMP->getParameters().getRecognition_properties().
    getPerson_bump_name();
  people_bump_threshold_ = COMP->getParameters().getRecognition_properties().
    getPeople_bump_threshold();
	wanted_person_name_ = COMP->getParameters().getRecognition_properties().
    getWanted_person_name();

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

	// People is the output for events and data
	std::vector<CommObjectRecognitionObjects::CommPerson> people;
	for (auto& obj : objs.getObjectsCopy())
	{
		if (obj.getObject_type() != "pedestrian")
			continue;
		
		bool found_in_json = false;
    
    // comm_person is a temporary object to build the People output
		CommObjectRecognitionObjects::CommPerson comm_person;
    comm_person.setDimension(obj.getDimension());
    comm_person.setPose(obj.getPose());
    comm_person.setId(obj.getObject_id());
    comm_person.setIs_valid(true);
		
		// Checking if person is in the provided Json Database
		for (auto& person : _people)
		{
			// if person was found before in Json Database, in this run, we just
			// need to compare the object's id with the person's id. Otherwise
			// we need to check colors
			if (person.unvisited)
			{
				// Person not found before in this run, but colors match. Thus found
        // for the first time
				if (checkColors(person, obj))
				{
          // we have a match
          found_in_json = true;

					// fix person's id in the provided json file for future search
					person.id = obj.getObject_id();
					person.unvisited = false;
          
          // complete the output's name
					comm_person.setName(person.name);
					people.push_back(comm_person);
					
          // updating the Query Database
          auto _comm_people_copy = _comm_people.getPeopleCopy();
          _comm_people_copy.push_back(comm_person);
          _comm_people.setPeople(_comm_people_copy);
					break;
				}
				// person not yet visited and colors don't match. Continue loop
				else
					continue;
			}
      
      // if person already visited before, we just need to compare its id
			else
			{
        // person's id does not match. Continue loop
				if (obj.getObject_id() != person.id)
					continue;

        // we have a match! 
        found_in_json = true;

        // complete the output's name
        comm_person.setName(person.name);
        people.push_back(comm_person);

        // update the Query Database with the new pose
        for (size_t i = 0; i < _comm_people.getPeopleSize(); ++i)
        {
          auto _comm_person = _comm_people.getPeopleElemAtPos(i);
          if (_comm_person.getId() == obj.getObject_id())
          {
            _comm_person.setDimension(obj.getDimension());
            _comm_person.setPose(obj.getPose());
            break;
          }
        }
        break;
			}
    }
      
    if (!found_in_json)
    {
      // complete the output's name with unknown
      comm_person.setName("unknown");
      people.push_back(comm_person);

      // updating the Query Database
      auto _comm_people_copy = _comm_people.getPeopleCopy();
      _comm_people_copy.push_back(comm_person);
      _comm_people.setPeople(_comm_people_copy);
    }  
	}
	
	CommObjectRecognitionObjects::CommObjectRecognitionEventState state;
  CommObjectRecognitionObjects::CommObjectRecognitionEventState wanted_person_state;
  wanted_person_state.setState(CommObjectRecognitionObjects::
        ObjectRecognitionState::INVISIBLE);
	std::vector<unsigned> ids;
	for (size_t i = 0; i < people.size(); ++i) {
    if (people[i].getName() == wanted_person_name_) {
      wanted_person_state.setState(CommObjectRecognitionObjects::
        ObjectRecognitionState::VISIBLE);
      wanted_person_state.setObject_id({(unsigned int) people[i].getId()});
    }
    ids.push_back(people[i].getId());
  }
	state.setObject_id(ids);
	
	if (people.size() > 0)
		state.setState(CommObjectRecognitionObjects::ObjectRecognitionState::VISIBLE);
	else
		state.setState(CommObjectRecognitionObjects::ObjectRecognitionState::INVISIBLE);
	
  peopleEventServiceOutPut(state);
  wantedPersonServiceOutPut(wanted_person_state);
  
  CommObjectRecognitionObjects::CommPeople people_out;
  people_out.setIs_valid(true);
  people_out.setPeople(people);
  checkBump(people_out);
  peoplePushServiceOutPut(people_out);
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

void RecognitionTask::checkBump(const CommObjectRecognitionObjects::CommPeople&
  people_out) {
  CommObjectRecognitionObjects::CommObjectRecognitionEventBumpState bump_state;
  CommBasicObjects::CommBaseState pose;
  Smart::StatusCode obj_status = baseStateServiceInGetUpdate(pose);
  bump_state.setState(CommObjectRecognitionObjects::ObjectBumpState::NOT_BUMP);
  std::vector<unsigned int> ids;
  
  for (auto& people : people_out.getPeopleCopy()) {
    if (person_bump_name_.empty() || person_bump_name_ == people.getName()){
      if(sqrt(pow(people.getPose().get_x(1) - pose.getBasePose().get_x(1), 2) +
        pow(people.getPose().get_y(1) - pose.getBasePose().get_y(1), 2)) <
        people_bump_threshold_) {
        ids.push_back(people.getId());
        bump_state.setState(CommObjectRecognitionObjects::ObjectBumpState::BUMP);
      }
    }
  }
  peopleEventBumpServiceOutPut(bump_state);
}
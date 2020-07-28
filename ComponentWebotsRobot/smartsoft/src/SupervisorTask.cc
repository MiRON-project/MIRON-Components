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
#include "SupervisorTask.hh"
#include "ComponentWebotsRobot.hh"

#include <iostream>

std::unordered_map<std::string, std::string> SupervisorTask::objects_names = {
	{"WOODENBOX","WoodenBox"}
};

SupervisorTask::SupervisorTask(SmartACE::SmartComponent *comp) 
:	SupervisorTaskCore(comp),
	object_offset({0,0,0})
{}
SupervisorTask::~SupervisorTask() 
{}


void SupervisorTask::on_ObjectPlacementPushServiceIn(const DomainSpeech::CommObjectPlacementOutputMessage &input)
{
  COMP->mRobotMutex.acquire();
	
	std::string name = objects_names[input.getObjectType()];
	if (name == "") {
		COMP->mRobotMutex.release();
		return;
	}

	std::vector<std::string> sizes;
	for (size_t i = 0; i < input.getObjectSizeSize(); ++i) {
		if (input.getObjectSizeElemAtPos(i) > object_max_size)	
			return;
		sizes.push_back(std::to_string(input.getObjectSizeElemAtPos(i)));
	}
	std::array<std::string, 3> robot_position = {
      std::to_string(COMP->_pose->get_base_position().get_x(1) + object_offset[0]),
      std::to_string(object_offset[1]),
      std::to_string(-COMP->_pose->get_base_position().get_y(1) + object_offset[2])
			};

	std::string obj = name + " {" + "translation " + robot_position[0] + " " +
		robot_position[1] + " " + robot_position[2] + " size ";
	
	for (auto& s : sizes)
		obj += s + " "; 
	obj += "mass " + std::to_string(input.getObjectMass()) + "}";
  webots::Node *root = COMP->_supervisor->getRoot();
  auto children = root->getField("children");
  children->importMFNodeFromString(-1, obj);

  COMP->mRobotMutex.release();
}

int SupervisorTask::on_entry()
{
  COMP->mRobotMutex.acquire();
	object_max_size = COMP->getGlobalState().getHri().
    getMax_size();
	auto offset = COMP->getGlobalState().getHri().getOffset();
	object_offset.clear();
	for (auto o : offset)
		object_offset.push_back(o);
  COMP->mRobotMutex.release();
	return 0;
}
int SupervisorTask::on_execute()
{
	return 0;
}
int SupervisorTask::on_exit()
{
	// use this method to clean-up resources which are initialized in on_entry() and needs to be freed before the on_execute() can be called again
	return 0;
}

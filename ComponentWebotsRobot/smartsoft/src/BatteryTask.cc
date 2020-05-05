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
#include "BatteryTask.hh"
#include "ComponentWebotsRobot.hh"
#include "CommBasicObjects/CommBatteryLevel.hh"
#include "CommBasicObjects/CommTimeStamp.hh"
#include "webots/nodes.h"

#include <iostream>

BatteryTask::BatteryTask(SmartACE::SmartComponent *comp) 
:	BatteryTaskCore(comp)
{
	std::cout << "constructor BatteryTask\n";
}
BatteryTask::~BatteryTask() 
{
	std::cout << "destructor BatteryTask\n";
}



int BatteryTask::on_entry()
{
	if (!COMP->_supervisor)
		return -1;

  	COMP->mRobotMutex.acquire();	
	
	computeWebotsTimestep();
	
	COMP->battery_out = false;
	
	custom_battery = COMP->getGlobalState().getBattery_properties().
		getCustom_battery();
	battery_level = COMP->getGlobalState().getBattery_properties().
		getBattery_level_init();
	battery_level_min = COMP->getGlobalState().getBattery_properties().
		getBattery_level_min();
	battery_level_max = COMP->getGlobalState().getBattery_properties().
		getBattery_level_max();
	motor_consumption = COMP->getGlobalState().getBattery_properties().
		getMotor_consumption();
	cpu_consumption = COMP->getGlobalState().getBattery_properties().
		getCpu_consumption();

	if (!custom_battery)
		COMP->_supervisor->batterySensorEnable(webotsTimeStep);
	else
		getCharges();
	
	last_sample_time = std::chrono::system_clock::now();
	
	COMP->mRobotMutex.release();

	return 0;
}
int BatteryTask::on_execute()
{
	COMP->mRobotMutex.acquire();

	CommBasicObjects::CommBatteryLevel bt_level;
	CommBasicObjects::CommTimeStamp timestamp;
	
	std::chrono::system_clock::time_point current_sample_time = 
		std::chrono::system_clock::now();
	
	timestamp.set(timepointToTimeval(current_sample_time));
	bt_level.setTimeStamp(timestamp);

	auto milliseconds = (double) std::chrono::duration_cast
		<std::chrono::milliseconds>(current_sample_time - last_sample_time).
		count();
	auto seconds = milliseconds / 1000.0;
	last_sample_time = current_sample_time;

	if(custom_battery)
		computeCustomConsumption(seconds);
	else
		battery_level = COMP->_supervisor->batterySensorGetValue();

	//std::cout << "Battery Level is: " << battery_level << std::endl;
	bt_level.setChargeLevel((int)battery_level);
	
	COMP->batteryPushServiceOut->put(bt_level);
	COMP->mRobotMutex.release();

	return 0;
}
int BatteryTask::on_exit()
{
	// use this method to clean-up resources which are initialized in on_entry() and needs to be freed before the on_execute() can be called again
	return 0;
}

timeval BatteryTask::timepointToTimeval(
	std::chrono::system_clock::time_point tp) const
{
	auto secs = std::chrono::time_point_cast<std::chrono::seconds>(tp);
    auto ms = std::chrono::time_point_cast<std::chrono::microseconds>(tp) -
		std::chrono::time_point_cast<std::chrono::microseconds>(secs);
    timeval t = timeval{secs.time_since_epoch().count(), 
		ms.count()};
	return t;
}

void BatteryTask::computeCustomConsumption(double seconds)
{
	double motor_energy = 0;
	for (auto motor : COMP->motors)
		motor_energy += abs(motor->getVelocity());

	auto robot_position = getRobotPosition();
	
	for (auto charger : chargers)
	{
		if (checkChargerRange(robot_position, charger))
			battery_level += charger->getField("battery")->getMFFloat(2) * 
				seconds;
	}

	battery_level -= seconds * motor_energy * motor_consumption;
	battery_level -= seconds * cpu_consumption;
	battery_level = std::max(battery_level_min, battery_level);
	battery_level = std::min(battery_level_max, battery_level);
	if(battery_level <= 0.0)
		COMP->battery_out = true;
}

void BatteryTask::getCharges()
{
	if (COMP->has_supervisor)
	{
		webots::Node* root = COMP->_supervisor->getRoot();
		auto children = root->getField("children");
		size_t number_of_nodes = children->getCount();
		for (size_t i = 0; i < number_of_nodes; ++i) 
		{
			auto node = children->getMFNode(i);
			if(node->getType()==WbNodeType::WB_NODE_CHARGER)
				chargers.push_back(node);
		}
	}
}

std::array<double, 3> BatteryTask::getRobotPosition() const
{
	if (COMP->_gps)
	{
		auto GPS_value = COMP->_gps->getValues();
		return {GPS_value[0], GPS_value[1], GPS_value[2]};
	}
	else
		return {0, 0, 0};
} 

bool BatteryTask::checkChargerRange(
	const std::array<double,3>& robot_position, webots::Node* charger) const
{
	auto charger_position = charger->getPosition();
  auto charger_enu_pos = nedToEnu(std::array<double,3>{{charger_position[0], 
    charger_position[1], charger_position[2]}});

	const double x2 = pow(robot_position[0] - charger_enu_pos[0], 2);
	const double y2 = pow(robot_position[1] - charger_enu_pos[1], 2);
	auto radius = charger->getField("radius")->getSFFloat();
	return (sqrt(x2 + y2) <= radius);
}

void BatteryTask::computeWebotsTimestep()
{
  // The WebotsTimestep is computed wrt the RobotTask
  webotsTimeStep = COMP->_supervisor->getBasicTimeStep();
  int coeff = 1000.0 / (webotsTimeStep * 
    COMP->connections.batteryTask.periodicActFreq);
  webotsTimeStep *= coeff;
}

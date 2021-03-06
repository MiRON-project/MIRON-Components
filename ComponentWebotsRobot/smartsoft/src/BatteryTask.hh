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
#ifndef _BATTERYTASK_HH
#define _BATTERYTASK_HH

#include "BatteryTaskCore.hh"

#include "webots/Motor.hpp"
#include "webots/Device.hpp"
#include "webots/Node.hpp"
#include <webots/GPS.hpp>

#include <chrono>

class BatteryTask  : public BatteryTaskCore
{
private:
	double battery_level;
	double battery_level_min;
	double battery_level_max;
	double motor_consumption;
	double cpu_consumption;
	bool custom_battery;
	bool charging;
	int webotsTimeStep;
	std::chrono::time_point<std::chrono::system_clock> last_sample_time;
	std::vector<webots::Node*> chargers;

	timeval timepointToTimeval(std::chrono::system_clock::time_point tp) const;
	void computeCustomConsumption(double seconds);
	void getCharges();
	bool checkChargerRange(const std::array<double, 3>& robot_position,
		webots::Node* charger) const;
	void computeWebotsTimestep();
public:
	BatteryTask(SmartACE::SmartComponent *comp);
	virtual ~BatteryTask();
	
	virtual int on_entry();
	virtual int on_execute();
	virtual int on_exit();
};

#endif

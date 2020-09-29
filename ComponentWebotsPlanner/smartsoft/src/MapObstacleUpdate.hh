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
#ifndef _MAPOBSTACLEUPDATE_HH
#define _MAPOBSTACLEUPDATE_HH

#include "MapObstacleUpdateCore.hh"
#include <Eigen/Geometry>

struct DynamicObject {
	CommObjectRecognitionObjects::CommObjectRecognitionObjectProperties property;
	Eigen::AlignedBox2d box;
	bool changed;
	
	DynamicObject() : changed(false) {}
};

class MapObstacleUpdate  : public MapObstacleUpdateCore
{
private:
	std::vector<DynamicObject> dynamic_objects_;
	virtual void on_ObjectsPushServiceIn(
		const CommObjectRecognitionObjects::CommObjectRecognitionEnvironment &input);
	void updateDynamicObstacles(
		const CommObjectRecognitionObjects::CommObjectRecognitionEnvironment& 
			objects);
	void updatePedestrianChecker();
	
public:
	MapObstacleUpdate(SmartACE::SmartComponent *comp);
	virtual ~MapObstacleUpdate();
	
	virtual int on_entry();
	virtual int on_execute();
	virtual int on_exit();
};

#endif
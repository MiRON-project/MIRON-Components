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
#ifndef _SUPERVISORTASK_HH
#define _SUPERVISORTASK_HH

#include "SupervisorTaskCore.hh"
#include <unordered_map>
#include <Eigen/Geometry>
#include <CommNavigationObjects/BoundingBoxes.hh>

class SupervisorTask  : public SupervisorTaskCore
{
	private:
		double object_max_size;
		std::vector<double> object_offset;
		std::vector<int> carried_obj_index;
		
		static std::unordered_map<std::string, std::string> objects_names;
		virtual void on_ObjectPlacementPushServiceIn(const DomainSpeech::CommObjectPlacementOutputMessage &input);
		virtual void on_ObjectDropPushServiceIn(const DomainSpeech::CommObjectDropOutputMessage &input);

		CommNavigationObjects::BoundingBoxes extractStaticObstacles();
	public:
		SupervisorTask(SmartACE::SmartComponent *comp);
		virtual ~SupervisorTask();
		
		virtual int on_entry();
		virtual int on_execute();
		virtual int on_exit();
};

#endif
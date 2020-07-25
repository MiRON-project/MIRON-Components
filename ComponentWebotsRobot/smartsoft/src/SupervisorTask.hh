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

class SupervisorTask  : public SupervisorTaskCore
{
	private:
		double object_max_size;
		double object_placement_height;
		static std::unordered_map<std::string, std::string> objects_names;
		virtual void on_ObjectPlacementPushServiceIn(const DomainSpeech::CommObjectPlacementOutputMessage &input);
	public:
		SupervisorTask(SmartACE::SmartComponent *comp);
		virtual ~SupervisorTask();
		
		virtual int on_entry();
		virtual int on_execute();
		virtual int on_exit();
};

#endif

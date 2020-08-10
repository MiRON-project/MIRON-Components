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
#ifndef _PLANNERWAYPOINTSQUERYSERVICEANSWHANDLER_USER_HH
#define _PLANNERWAYPOINTSQUERYSERVICEANSWHANDLER_USER_HH
		
#include "PlannerWaypointsQueryServiceAnswHandlerCore.hh"

class PlannerWaypointsQueryServiceAnswHandler : public PlannerWaypointsQueryServiceAnswHandlerCore
{
protected:
	virtual void on_update_from(const StaticGlobalPlanner* staticGlobalPlanner);
public:
	PlannerWaypointsQueryServiceAnswHandler(IQueryServer *server);
	virtual ~PlannerWaypointsQueryServiceAnswHandler() = default;
	virtual void handleQuery(const QueryId &id, const CommNavigationObjects::CommPlannerGoal& request);
};
#endif

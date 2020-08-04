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
#ifndef _STATICGLOBALPLANNER_HH
#define _STATICGLOBALPLANNER_HH

#include "StaticGlobalPlannerCore.hh"
#include <ompl/base/spaces/SE2StateSpace.h>
#include <ompl/base/spaces/RealVectorBounds.h>
#include <ompl/base/StateValidityChecker.h>
#include <ompl/geometric/SimpleSetup.h>
#include <ompl/base/MotionValidator.h>
#include "Eigen/Geometry"

class BoundingBoxValidityChecker : public ompl::base::StateValidityChecker
{
	std::vector<Eigen::AlignedBox2d> obstacles;
	Eigen::AlignedBox2d robot;
	
	public:
		BoundingBoxValidityChecker(const ompl::base::SpaceInformationPtr& si,
				const std::vector<Eigen::AlignedBox2d>& _obstacles,
				const Eigen::AlignedBox2d& _robot) :
			ompl::base::StateValidityChecker(si),
			obstacles(_obstacles),
			robot(_robot) {}

		virtual bool isValid(const ompl::base::State *state) const
		{
			const auto* xy = state->as<ompl::base::SE2StateSpace::StateType>();
			double x = xy->getX();
			double y = xy->getY();
			Eigen::Vector2d point(x, y);
			Eigen::AlignedBox2d translated_robot(robot);
			translated_robot.translate(point);
      for (auto& obstacle : obstacles) {
				obstacle.min()[1] << ", " << obstacle.max()[0] << ", " << 
				obstacle.max()[1] << "\n";
				if (obstacle.intersects(translated_robot)) {
					return false;
				}
			}
			return true;
		}	
};

class StaticGlobalPlanner  : public StaticGlobalPlannerCore
{
private:
	CommBasicObjects::CommBaseState robot_pose;
	std::vector<Eigen::AlignedBox2d> obstacles;
	bool obstacles_init;
	bool replan;
	CommNavigationObjects::CommPlannerGoal goal;
	Eigen::AlignedBox2d robot_footprint;
	CommNavigationObjects::BoundingBox sample_space;

	std::shared_ptr<ompl::base::SE2StateSpace> space;
	ompl::geometric::SimpleSetupPtr simple_setup_;
	ompl::base::StateValidityCheckerPtr validity_checker;
	ompl::base::MotionValidatorPtr motion_checker;
	
	void BaseStateServiceIn(const CommBasicObjects::CommBaseState &input);
	void ObstaclesServiceIn(const CommNavigationObjects::BoundingBoxes &input);
	void PlannerGoalServiceIn(const CommNavigationObjects::CommPlannerGoal &input);
public:
	StaticGlobalPlanner(SmartACE::SmartComponent *comp);
	virtual ~StaticGlobalPlanner();
	
	virtual int on_entry();
	virtual int on_execute();
	virtual int on_exit();
};

#endif

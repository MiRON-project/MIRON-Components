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
#include "StaticGlobalPlanner.hh"
#include "ComponentWebotsPlanner.hh"

#include <iostream>

StaticGlobalPlanner::StaticGlobalPlanner(SmartACE::SmartComponent *comp) :
    StaticGlobalPlannerCore(comp),
    replan(false),
    planned(false),
    obstacles_init(false)
{
  auto box = COMP->getGlobalState().getRobot().getFootprint();
  std::vector<double> v_box;
  for (auto &b : box)
      v_box.push_back(b);
  robot_footprint = Eigen::AlignedBox2d(
      Eigen::Vector2d(v_box[0], v_box[1]), Eigen::Vector2d(v_box[2], v_box[3]));
  space = std::make_shared<ompl::base::SE2StateSpace>();
  simple_setup_ = std::make_shared<ompl::geometric::SimpleSetup>(space);
}

StaticGlobalPlanner::~StaticGlobalPlanner()
{
}

void StaticGlobalPlanner::ObstaclesServiceIn(
    const CommNavigationObjects::BoundingBoxes &input)
{
  COMP->validity_checker_Mutex.acquire();
  if (COMP->validity_checker) {
      COMP->validity_checker_Mutex.release();
      return;
  }
  sample_space = input.getFloor();

  ompl::base::RealVectorBounds bounds(2);
  bounds.setLow(0, std::min(sample_space.getXmin(), sample_space.getXmax()));
  bounds.setLow(1, std::min(sample_space.getZmin(), sample_space.getZmax()));
  bounds.setHigh(0, std::max(sample_space.getXmax(), sample_space.getXmin()));
  bounds.setHigh(1, std::max(sample_space.getZmin(), sample_space.getZmax()));
  space->setBounds(bounds);

  auto boxes = input.getBoxesCopy();
  for (auto &box : boxes)
  {
    Eigen::Vector2d _min(
        std::min(box.getXmin(), box.getXmax()),
        std::min(box.getZmin(), box.getZmax()));
    Eigen::Vector2d _max(
        std::max(box.getXmin(), box.getXmax()),
        std::max(box.getZmin(), box.getZmax()));
    obstacles.push_back(Eigen::AlignedBox2d(_min, _max));
  }

  COMP->validity_checker = std::make_shared<BoundingBoxValidityChecker>(
    simple_setup_->getSpaceInformation(), obstacles, robot_footprint);
  simple_setup_->setStateValidityChecker(COMP->validity_checker);
  COMP->validity_checker_Mutex.release();
}

CommRobotinoObjects::CommPathNavigationGoal StaticGlobalPlanner::PlannerGoalServiceIn(
    const CommNavigationObjects::CommPlannerGoal &input)
{
  CommRobotinoObjects::CommPathNavigationGoal path_navigation_goal;
  if (input.getXGoalPoint() == goal.getXGoalPoint() &&
      input.getYGoalPoint() == goal.getYGoalPoint() && !replan) {
    return path_navigation_goal;
  }
  
  COMP->validity_checker_Mutex.acquire();
  if (COMP->validity_checker)
  {
    goal = input;
    ompl::base::ScopedState<ompl::base::SE2StateSpace> start(space);
    ompl::base::ScopedState<ompl::base::SE2StateSpace> end(space);
    start->setXY(robot_pose.get_base_position().get_x(1),
        -robot_pose.get_base_position().get_y(1));
    end->setXY(input.getXGoalPoint(), input.getYGoalPoint());
    simple_setup_->clear();
    simple_setup_->setStartAndGoalStates(start, end);
    
    int attempts_to_solve = 0;
    ompl::base::PlannerStatus solved;
    while (attempts_to_solve < 10) {
      solved = simple_setup_->solve(5.0);
      if (solved)
        break;
      attempts_to_solve++;
    }
    
    if (solved)
    {
      simple_setup_->simplifySolution();
      simple_setup_->getSolutionPath().print(std::cout);
      auto states = simple_setup_->getSolutionPath().getStates();

      std::vector<CommRobotinoObjects::CommPathNode> nodes;
      for (auto& state : states) {
          CommRobotinoObjects::CommPathNode node;
          const auto xy = state->as<ompl::base::SE2StateSpace::StateType>();
          node.setX(xy->getX());
          node.setY(xy->getY());
          nodes.push_back(node);
      }
      path.setNodes(nodes);
      path_navigation_goal.setPaths(path);
      path_navigation_goal.setGoal(robot_pose.get_base_position().get_x(1),
          -robot_pose.get_base_position().get_y(1), 0, input.getXGoalPoint(),
          input.getYGoalPoint(), states.size());
      planned = true;
      pathNavigationGoalServiceOutPut(path_navigation_goal);
    }
  }
  COMP->validity_checker_Mutex.release();
  return path_navigation_goal;
}

int StaticGlobalPlanner::on_entry()
{
  return 0;
}

int StaticGlobalPlanner::on_execute()
{
  COMP->mRobotMutex.acquire();
  CommNavigationObjects::BoundingBoxes objs;
  Smart::StatusCode obj_status = obstaclesServiceInGetUpdate(objs);
  if (obj_status == Smart::SMART_OK && !obstacles_init)
  {
    obstacles_init = true;
    ObstaclesServiceIn(objs);
  }
  
  Smart::StatusCode base_status = baseStateServiceInGetUpdate(robot_pose);
  if (base_status != Smart::SMART_OK)
  {
    COMP->mRobotMutex.release();
    return 0;
  }

  CommNavigationObjects::DistanceToGoal dtg;
  if (planned) {
    dtg.setL1(std::abs(goal.getXGoalPoint() - 
      robot_pose.get_base_position().get_x(1)) + std::abs(goal.getYGoalPoint() -
      robot_pose.get_base_position().get_y(1)));
    dtg.setL2(std::sqrt(
      std::pow(goal.getXGoalPoint() - robot_pose.get_base_position().get_x(1), 2) + 
      std::pow(goal.getYGoalPoint() - robot_pose.get_base_position().get_y(1), 2))); 
  }
  else {
    dtg.setL1(-1);
    dtg.setL2(-1);
  }
  distanceToGoalServiceOutPut(dtg);
  COMP->mRobotMutex.release();
  return 0;
}
int StaticGlobalPlanner::on_exit()
{
    // use this method to clean-up resources which are initialized in on_entry() and needs to be freed before the on_execute() can be called again
    return 0;
}

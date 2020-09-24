#pragma once

// std
#include <vector>

// ompl
#include <ompl/base/StateValidityChecker.h>
#include <ompl/base/spaces/SE2StateSpace.h>

// eigen
#include <Eigen/Geometry>

class BoundingBoxValidityChecker : public ompl::base::StateValidityChecker
{
  std::vector<Eigen::AlignedBox2d> obstacles;
  Eigen::AlignedBox2d robot;

public:
  std::vector<std::pair<int, Eigen::AlignedBox2d>> dynamic_obstacles;
  
  BoundingBoxValidityChecker(const ompl::base::SpaceInformationPtr &si,
    const std::vector<Eigen::AlignedBox2d> &_obstacles,
    const Eigen::AlignedBox2d &_robot);

  virtual bool isValid(const ompl::base::State *state) const;
};
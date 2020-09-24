#include <BoundingBoxValidityChecker.hh>

BoundingBoxValidityChecker::BoundingBoxValidityChecker(
  const ompl::base::SpaceInformationPtr &si,
  const std::vector<Eigen::AlignedBox2d> &_obstacles,
  const Eigen::AlignedBox2d &_robot) :
    ompl::base::StateValidityChecker(si),
    obstacles(_obstacles),
    robot(_robot) {}

bool BoundingBoxValidityChecker::isValid(const ompl::base::State *state) const
{
  const auto *xy = state->as<ompl::base::SE2StateSpace::StateType>();
  double x = xy->getX();
  double y = xy->getY();
  Eigen::Vector2d point(x, y);
  Eigen::AlignedBox2d translated_robot(robot);
  translated_robot.translate(point);
  for (auto &obstacle : obstacles)
  {
    if (obstacle.intersects(translated_robot))
    {
      return false;
    }
  }
  for (auto &obstacle : dynamic_obstacles)
  {
    if (obstacle.second.intersects(translated_robot))
    {
      return false;
    }
  }
  return true;
}
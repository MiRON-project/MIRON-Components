#ifndef _CAMERARECOGNITIONUTILS_HH
#define _CAMERARECOGNITIONUTILS_HH

#include <CommBasicObjects/CommPose3d.hh>

#include <cmath>
#include <array>

#include "Eigen/Geometry"
#include "webots/Node.hpp"

struct Quaternion {
    Quaternion();
    Quaternion(double w, double x, double y, double z) :
        w(w), x(x), y(y), z(z){};
    double w, x, y, z;
};

struct AngleAxis {
    AngleAxis();
    AngleAxis(double x, double y, double z, double angle) :
        x(x), y(y), z(z), angle(angle){};
    double x, y, z, angle;
};

struct EulerAngles {
    double roll, pitch, yaw;
};

EulerAngles toEulerAngles(Quaternion q); 

// NED Convention (X to the right, Y straight up, Z axis toward viewer)
EulerAngles toEulerAngles(const AngleAxis& q); 

Eigen::Affine3d rollPitchYawToAffine(const double& yaw, const double& pitch, 
        const double& roll);

Eigen::Affine3d pose3dToAffine3d(const CommBasicObjects::CommPose3d& pose);

CommBasicObjects::CommPose3d affine3dToPose3d(const Eigen::Affine3d& pose);

Eigen::Affine3d webotsNodeToAffine3d(webots::Node* node);
Eigen::Affine3d webotsNodeToAffine3dGlobal(webots::Node* node);

std::array<double, 3> nedToEnu(const std::array<double, 3> xyz);
void nedToEnu(CommBasicObjects::CommPose3d& position);
void nedToEnu(EulerAngles& angles);

#endif
#include "Utils.hh"

EulerAngles toEulerAngles(Quaternion q) 
{
    EulerAngles angles;

    // roll (x-axis rotation)
    double sinr_cosp = 2 * (q.w * q.x + q.y * q.z);
    double cosr_cosp = 1 - 2 * (q.x * q.x + q.y * q.y);
    angles.roll = std::atan2(sinr_cosp, cosr_cosp);

    // pitch (y-axis rotation)
    double sinp = 2 * (q.w * q.y - q.z * q.x);
    if (std::abs(sinp) >= 1)
        angles.pitch = std::copysign(M_PI / 2, sinp); // use 90 degrees if out of range
    else
        angles.pitch = std::asin(sinp);

    // yaw (z-axis rotation)
    double siny_cosp = 2 * (q.w * q.z + q.x * q.y);
    double cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z);
    angles.yaw = std::atan2(siny_cosp, cosy_cosp);

    return angles;
}

EulerAngles toEulerAngles(const AngleAxis& xyza) 
{
    EulerAngles angles;
    double s = sin(xyza.angle);
	double c = cos(xyza.angle);
	double t = 1 - c;
	
    if ((xyza.x * xyza.y * t + xyza.z * s) > 0.998) 
    { // north pole singularity detected
		angles.yaw = 2 * atan2(xyza.x * sin(xyza.angle / 2), 
            cos(xyza.angle / 2));
		angles.pitch = M_PI_2;
		angles.roll = 0;
		return angles;
	}

	if ((xyza.x * xyza.y * t + xyza.z * s) < -0.998) 
    { // south pole singularity detected
		angles.yaw = -2 * atan2(xyza.x * sin(xyza.angle / 2),
            cos(xyza.angle / 2));
		angles.pitch = - M_PI_2;
		angles.roll = 0;
		return angles;
	}

	angles.yaw = atan2(xyza.y * s - xyza.x * xyza.z * t, 
        1 - (xyza.y * xyza.y + xyza.z * xyza.z) * t);
	angles.pitch = asin(xyza.x * xyza.y * t + xyza.z * s) ;
	angles.roll = atan2(xyza.x * s - xyza.y * xyza.z * t, 
        1 - (xyza.x * xyza.x + xyza.z * xyza.z) * t);
    return angles;
}

// NED Convention YZX
Eigen::Affine3d rollPitchYawToAffine(const double& yaw, const double& pitch, 
        const double& roll)
{
    return Eigen::Affine3d(Eigen::AngleAxisd(yaw, Eigen::Vector3d::UnitY()) * 
        Eigen::AngleAxisd(pitch, Eigen::Vector3d::UnitZ()) * 
        Eigen::AngleAxisd(roll, Eigen::Vector3d::UnitX()));
}

Eigen::Affine3d pose3dToAffine3d(const CommBasicObjects::CommPose3d& pose)
{
    Eigen::Affine3d R = Eigen::Affine3d(rollPitchYawToAffine(
        pose.get_azimuth(), pose.get_elevation(), pose.get_roll()));
    Eigen::Affine3d T(Eigen::Translation3d(Eigen::Vector3d(
        pose.get_x(), pose.get_y(), pose.get_z())));
    T = T * R;
    return T;
}

// NED Convention YZX
CommBasicObjects::CommPose3d affine3dToPose3d(const Eigen::Affine3d& pose)
{
    CommBasicObjects::CommPose3d pose3d;
    Eigen::Vector3d rpy = pose.linear().eulerAngles(1, 2, 0);
    Eigen::Vector3d position = pose.translation();
    pose3d.set_x(position.x());
    pose3d.set_y(position.y());
    pose3d.set_z(position.z());
    pose3d.set_roll(rpy.x());
    pose3d.set_elevation(rpy.y());
    pose3d.set_azimuth(rpy.z());
    return pose3d;
}

Eigen::Affine3d webotsNodeToAffine3d(webots::Node* node)
{
    auto xyz = node->getField("translation")->getSFVec3f();
    auto angle_axis = node->getField("rotation")->getSFRotation();
    
    if (!xyz)
        return Eigen::Affine3d::Identity();
    
    if (!angle_axis)
        return Eigen::Affine3d::Identity();

    Eigen::Affine3d T = (Eigen::Affine3d) Eigen::AngleAxisd(angle_axis[3], 
        Eigen::Vector3d(angle_axis[0], angle_axis[1], angle_axis[2]));
    T = Eigen::Translation3d(Eigen::Vector3d(
        xyz[0] * 1000, xyz[1] * 1000, xyz[2] * 1000)) * T;
    return T;
}

Eigen::Affine3d webotsNodeToAffine3dGlobal(webots::Node* node)
{
    auto position = node->getPosition();
    auto rotation_matrix = node->getOrientation();
    Eigen::Matrix3d m;
    m << rotation_matrix[0], rotation_matrix[1], rotation_matrix[2],
         rotation_matrix[3], rotation_matrix[4], rotation_matrix[5],
         rotation_matrix[6], rotation_matrix[7], rotation_matrix[8];
    Eigen::Affine3d T;
    T.linear() = m;
    T.translation() = Eigen::Vector3d(position[0] * 1000, 
        position[1] * 1000, position[2] * 1000);
    return T;
}

std::array<double, 3> nedToEnu(const std::array<double, 3> xyz)
{
    return {xyz[0], -xyz[2], xyz[1]};
}

void nedToEnu(CommBasicObjects::CommPose3d& position)
{
    auto temp = position;
    position.set_y(-temp.get_z());
    position.set_z(temp.get_y());
}

void nedToEnu(EulerAngles& angles)
{
    EulerAngles temp = angles;
    angles.pitch = -temp.yaw;
    angles.yaw = temp.pitch;
}
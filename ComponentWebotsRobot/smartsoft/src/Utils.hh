#ifndef _CAMERARECOGNITIONUTILS_HH
#define _CAMERARECOGNITIONUTILS_HH

#include <cmath>
#include <array>

struct Quaternion {
    Quaternion();
    Quaternion(double w, double x, double y, double z) :
        w(w), x(x), y(y), z(z){};
    double w, x, y, z;
};

struct EulerAngles {
    double roll, pitch, yaw;
};

EulerAngles ToEulerAngles(Quaternion q); 

std::array<double, 3> nedToEnu(const std::array<double, 3> xyz);

#endif
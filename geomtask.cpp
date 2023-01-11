#define _USE_MATH_DEFINES
#include "geomtask.h"

Point3d Circle3d::eval(double t) const 
    {
    return Point3d {r*std::cos(t), r*std::sin(t), 0};
    }  
Point3d Circle3d::evalDerivative(double t) const
    {
    return Point3d {-r*std::sin(t), r*std::cos(t), 0};
    }
Point3d Ellipse3d::eval(double t) const
    {
    return Point3d {rx * std::cos(t), ry * std::sin(t), 0};
    }
Point3d Ellipse3d::evalDerivative(double t) const
    {
    return Point3d {-rx * std::sin(t), ry * std::cos(t), 0};
    };
Point3d Helix3d::eval(double t) const
    {
    return Point3d {r * std::cos(t), r * std::sin(t), t * step / M_PI / 2. };
    }
Point3d Helix3d::evalDerivative(double t) const
    {
    return Point3d {-r * std::sin(t), r * std::cos(t + M_PI_2), step / M_PI / 2.};
    }


void run()
    {
    }

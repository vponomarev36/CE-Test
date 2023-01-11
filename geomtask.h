#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>


class Point3d
    {
    public: double p[3];
    };

class Curve3d
    {
    public:
        // Point3d center; //always zero in this example
        //evaluate point by parameter
        virtual Point3d eval(double t) const = 0;
        //evaluate the 1st derivative by parameter, not normalized
        virtual Point3d evalDerivative(double t) const = 0;
    };

class Circle3d :public Curve3d
    {
    public:
    double r; 
        Circle3d(double r1) : r(r1) {};
        Point3d eval(double t) const override;
        Point3d evalDerivative(double t) const override;
    };

class Ellipse3d :public Curve3d
    {
    public:
        double rx, ry;
        Ellipse3d(double r1, double r2) : rx(r1), ry(r2) {};
        Point3d eval(double t) const override;
        Point3d evalDerivative(double t) const override;
    };

class Helix3d :public Curve3d
    {
    public:
    double r;
    double step;
    Helix3d(double r1, double s) : r(r1), step(s) {}
    Point3d eval(double t) const override;
    Point3d evalDerivative(double t) const override;
    }; 
#pragma once

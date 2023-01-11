#define _USE_MATH_DEFINES
#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>
#include <ctime>
#include <format>
#include <set>
#include "geomtask.h"

int main()
    {
    //container for the curves
    std::vector< std::shared_ptr<Curve3d>> geomvect;
    //random population
    std::srand(std::time(nullptr));
    for (unsigned i = 0; i < 10; ++i)
        {
        auto curvetype = std::rand() % 3;
        switch (curvetype)
            {
                case 0: {
                auto r = ((unsigned) std::rand()) / (double) RAND_MAX;//interval 0 .. 1
                geomvect.push_back(std::make_shared <Circle3d>(r));
                break;
                }
                case 1: {
                auto rx = ((unsigned) std::rand()) / (double)RAND_MAX;
                auto ry = ((unsigned) std::rand()) / (double) RAND_MAX;
                geomvect.push_back(std::make_shared <Ellipse3d>(rx, ry));
                break;
                }
                case 2: {
                auto rx = ((unsigned) std::rand()) / (double) RAND_MAX;
                auto step = ((unsigned) std::rand()) / (double) RAND_MAX;
                geomvect.push_back(std::make_shared <Helix3d>(rx, step));
                break;
                }
            }
        }
    //Print coordinates of points and derivatives at PI/4
    for (auto& geom : geomvect)
        {
        auto pt = geom->eval(M_PI_4);
        auto ptderiv = geom->evalDerivative(M_PI_4);
        if (dynamic_cast<Ellipse3d*>(geom.get()) != nullptr)
            std::cout << "Ellipse ";
        else if (dynamic_cast<Helix3d*>(geom.get()) != nullptr)
            std::cout << "Helix ";
        else
            std::cout << "Circle ";

        std::cout << std::format("point(pi/4) = ({:.5f},{:.5f},{:.5f}), derivative = ({:.5f},{:.5f},{:.5f})", pt.p[0], pt.p[1], pt.p[2], ptderiv.p[0], ptderiv.p[1], ptderiv.p[2]) << std::endl;
        }
    //Populate a second container with references to circles
    
    auto CircleLess = [](std::shared_ptr<Circle3d> _left, std::shared_ptr<Circle3d> _right)
        {
        return _left->r < _right->r;
        };
    std::set< std::shared_ptr<Circle3d>, decltype(CircleLess)> circles; // sorted by radius
    for (auto geom : geomvect)
        {     
         auto circle = dynamic_pointer_cast<Circle3d>(geom);
        if (circle != nullptr)
            circles.emplace(circle);
        }

    //Compute the total sum of radii of all curves in the second container.
    double sum=0;
    for (const auto& circle : circles)
        sum += circle->r;
    //
    std::cout << std::format("total sum of radii = {:.5f}", sum) << std::endl;

    }
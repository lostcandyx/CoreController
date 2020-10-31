#ifndef _EQUATIONSOLVER_H_
#define _EQUATIONSOLVER_H_

#include "Specifications.h"
#include "Hexagon.h"
#include "Matrix.h"
#include "quartic.h"
#include <iostream>

class EquationSolver
{
private:
    Point3D Coordinate;
    AngleSet Servo; 

    Hexagon Actuator;
    Hexagon Platform;

    bool IsActuatorReady;
    bool IsPlatformReady;

public:
    EquationSolver();
    ~EquationSolver();

    void SetCoordinate(double x,double y,double z);
    void SetCoordinate(Point3D c);
    AngleSet GetServo();

    void SetActuator(Hexagon input);
    void SetPlatform(Hexagon input);

    Hexagon GetActuator();
    Hexagon GetPlatform();

    void ServoPrint();
    void ServoPrintInDegree();

    bool Process();
};



#endif
#include "demo.h"

int main(int argc, char const *argv[])
{
    const Point3D Origin(0,0,0);
    const Hexagon Platform(Origin,asin(0.5*ROD_DISTANCE/PLATFORM_RADIUS),PLATFORM_RADIUS);

    Point3D Center;
    Hexagon Actuator;
    
    EquationSolver *server = new EquationSolver();
    
    server -> SetPlatform(Platform);
    double X,Y,Z;
    for (int i = 0;i<10;i++)
    {
        scanf("%lf %lf %lf",&X,&Y,&Z);
        Center = Point3D(X,Y,Z);
        Actuator = Hexagon(Center,asin(0.5*ROD_DISTANCE/ACTUATOR_RADIUS),ACTUATOR_RADIUS);
        server -> SetActuator(Actuator);
        server->Process();
        server->ServoPrint();
    }
    
    return 0;
}

/*
g++ -o demo ./src/demo.cpp -I ".\include\" -I ".\src\"
*/
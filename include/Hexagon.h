#ifndef _HEXAGON_H_
#define _HEXAGON_H_

#include "Matrix.h"

class Hexagon
{
private:
    Point3D Center;
    Matrix3D Vertex[6];
    double Radius;
    double Angle;
public:
    Hexagon(Point3D center,double a,double r);
    Hexagon(double x,double y,double z,double a,double r);
    Hexagon();
    ~Hexagon();

    void ComputeVertex();
    Matrix3D GetVertex(int index);
    Point3D GetVertexPoint(int index);
    Point3D GetCenter();
};

#endif

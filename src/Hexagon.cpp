#include "Hexagon.h"

Hexagon::Hexagon(double x, double y, double z, double a, double r)
{
    Center.X = x;
    Center.Y = y;
    Center.Z = z;
    Radius = r;
    Angle = a;

    ComputeVertex();
}

Hexagon::Hexagon(Point3D x, double a, double r)
{
    Center = x;
    Radius = r;
    Angle = a;

    ComputeVertex();
}

Hexagon::Hexagon()
{
    Center.X = 0;
    Center.Y = 0;
    Center.Z = 0;
    Radius = 0;
    Angle = 0;

    ComputeVertex();
}

Hexagon::~Hexagon()
{   
}

void Hexagon::ComputeVertex()
{
    Matrix3D Posture;
    Posture.SetOnlyMove(Center);
    Matrix3D Radius_Move,Angle_1,Angle_2,Angle_POSI,Angle_NEGA;
    Radius_Move.SetOnlyMove(Point3D(Radius,0,0));

    Angle_POSI.SetOnlyRotate(Point3D(0,0,Angle));
    Angle_NEGA.SetOnlyRotate(Point3D(0,0,-Angle));

    Angle_1.SetOnlyRotate(Point3D(0,0,Angle));
    Angle_2.SetOnlyRotate(Point3D(0,0,-Angle));
    Vertex[0] = Posture*Angle_1*Radius_Move*Angle_NEGA;
    Vertex[1] = Posture*Angle_2*Radius_Move*Angle_POSI;

    Angle_1.SetOnlyRotate(Point3D(0,0,-PI*2/3+Angle));
    Angle_2.SetOnlyRotate(Point3D(0,0,-PI*2/3-Angle));
    Vertex[2] = Posture*Angle_1*Radius_Move*Angle_NEGA;
    Vertex[3] = Posture*Angle_2*Radius_Move*Angle_POSI;

    Angle_1.SetOnlyRotate(Point3D(0,0,PI*2/3+Angle));
    Angle_2.SetOnlyRotate(Point3D(0,0,PI*2/3-Angle));
    Vertex[4] = Posture*Angle_1*Radius_Move*Angle_NEGA;
    Vertex[5] = Posture*Angle_2*Radius_Move*Angle_POSI;
}

Matrix3D Hexagon::GetVertex(int index)
{
    if (index>=0&&index<=5)
        return Vertex[index];
    else
        return Matrix3D();
}

Point3D Hexagon::GetVertexPoint(int index)
{
    return Point3D(GetVertex(index).m[Matrix3D::m03],GetVertex(index).m[Matrix3D::m13],GetVertex(index).m[Matrix3D::m23]);
}

Point3D Hexagon::GetCenter()
{
    return Center;
}
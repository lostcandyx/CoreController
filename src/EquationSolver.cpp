#include "EquationSolver.h"

EquationSolver::EquationSolver()
{
    Coordinate.X = 0;
    Coordinate.Y = 0;
    Coordinate.Z = 0;

    bool IsActuatorReady = false;
    bool IsPlatformReady = false;
}

EquationSolver::~EquationSolver()
{
}

void EquationSolver::SetCoordinate(double x, double y, double z)
{
    Coordinate.X = x;
    Coordinate.Y = y;
    Coordinate.Z = z;

    if (!Process())
        std::cout << "Compute Error" << std::endl;
}

void EquationSolver::SetCoordinate(Point3D c)
{
    Coordinate = c;

    if (!Process())
        std::cout << "Compute Error" << std::endl;
}

AngleSet EquationSolver::GetServo()
{
    return Servo;
}

bool EquationSolver::Process()
{
    double L1 = ROD_A_LENGTH;
    double L2 = ROD_B_LENGTH;
    double P_11, P_12, P_13, P_14, P_21, P_22, P_23, P_24;
    double P_31, P_32, P_33, P_34;
    double P3_1, P3_2, P3_3;

    for (int i = 0; i < 6; i++)
    {
        Matrix3D P1 = (Platform.GetVertex(i));
        Matrix3D P3 = (Actuator.GetVertex(i));

        P_11 = P1.m[Matrix3D::m00];
        P_12 = P1.m[Matrix3D::m01];
        P_13 = P1.m[Matrix3D::m02];
        P_14 = P1.m[Matrix3D::m03];
        P_21 = P1.m[Matrix3D::m10];
        P_22 = P1.m[Matrix3D::m11];
        P_23 = P1.m[Matrix3D::m12];
        P_24 = P1.m[Matrix3D::m13];
        P_31 = P1.m[Matrix3D::m20];
        P_32 = P1.m[Matrix3D::m21];
        P_33 = P1.m[Matrix3D::m22];
        P_34 = P1.m[Matrix3D::m23];
        P3_1 = P3.m[Matrix3D::m03];
        P3_2 = P3.m[Matrix3D::m13];
        P3_3 = P3.m[Matrix3D::m23];

        double a, b, c, d, e, z;
        z = 1;
        a = 2 * L1 * P_21 * P_24 * pow(z, 4) + 2 * L1 * P_11 * P_14 * pow(z, 4) - 2 * L1 * P3_2 * P_21 * pow(z, 4) - 2 * L1 * P3_1 * P_11 * pow(z, 4) + 2 * P3_2 * P_24 * pow(z, 4) + 2 * P3_1 * P_14 * pow(z, 4) + pow(L2, 2) * pow(z, 4) - pow(L1, 2) * pow(P_21, 2) * pow(z, 4) - pow(L1, 2) * pow(P_11, 2) * pow(z, 4) - pow(P_24, 2) * pow(z, 4) - pow(P_14, 2) * pow(z, 4) - pow(P3_3, 2) * pow(z, 4) - pow(P3_2, 2) * pow(z, 4) - pow(P3_1, 2) * pow(z, 4);
        b = -4 * L1 * P3_3;
        b = b / a;
        c = 4 * P3_2 * P_24 * pow(z, 2) + 4 * P3_1 * P_14 * pow(z, 2) + 2 * pow(L1, 2) * pow(P_21, 2) * pow(z, 2) + 2 * pow(L1, 2) * pow(P_11, 2) * pow(z, 2) - 2 * pow(P_24, 2) * pow(z, 2) - 2 * pow(P_14, 2) * pow(z, 2) - 2 * pow(P3_3, 2) * pow(z, 2) - 2 * pow(P3_2, 2) * pow(z, 2) - 2 * pow(P3_1, 2) * pow(z, 2) - 4 * pow(L1, 2) * pow(z, 2) + 2 * pow(L2, 2) * pow(z, 2);
        c = c / a;
        d = -4 * L1 * P3_3;
        d = d / a;
        e = -2 * L1 * P_21 * P_24 - 2 * L1 * P_11 * P_14 + 2 * L1 * P3_2 * P_21 + 2 * L1 * P3_1 * P_11 + 2 * P3_2 * P_24 + 2 * P3_1 * P_14 - pow(L1, 2) * pow(P_21, 2) - pow(L1, 2) * pow(P_11, 2) - pow(P_24, 2) - pow(P_14, 2) - pow(P3_3, 2) - pow(P3_2, 2) - pow(P3_1, 2) + pow(L2, 2);
        e = e / a;

        std::complex<double> *s = solve_quartic(b, c, d, e);
        //std::cout<<s[0]<<' '<<s[1]<<' '<<s[2]<<' '<<s[3]<<std::endl;
        int NumOfReal = 0;
        double RealSolution[4] = {-1, -1, -1, -1};
        for (int k = 0; k < 4; k++)
        {
            if (s[k].imag() == 0)
            {
                RealSolution[NumOfReal] = s[k].real();
                NumOfReal++;
            }
        }
        
        double max = atan(RealSolution[0]);
        if (NumOfReal == 0)
        {
            return false;
        }
        else if (NumOfReal == 1)
        {
            Servo.a[i] = 2*max;
        }
        else
        {
            for (int k = 1; k < NumOfReal; k++)
            {
                double wait = atan(RealSolution[k]);
                if (wait > max)
                    max = wait;
            }
            Servo.a[i] = 2*max;     
        }
    }
    return true;
}

void EquationSolver::SetActuator(Hexagon input)
{
    Actuator = input;
    Coordinate = Actuator.GetCenter();
    IsActuatorReady = true;
}

void EquationSolver::SetPlatform(Hexagon input)
{
    Platform = input;
    IsPlatformReady = true;
}

Hexagon EquationSolver::GetActuator()
{
    return Actuator;
}

Hexagon EquationSolver::GetPlatform()
{
    return Platform;
}

void EquationSolver::ServoPrint()
{
    printf("[ %.3lf , %.3lf , %.3lf , ",Servo.a[0],Servo.a[1],Servo.a[2]);
    printf("%.3lf , %.3lf , %.3lf ]\n",Servo.a[3],Servo.a[4],Servo.a[5]);
}

void EquationSolver::ServoPrintInDegree()
{
    printf("[ %.2lf , %.2lf , %.2lf , ",Servo.a[0]*180.0/PI,Servo.a[1]*180.0/PI,Servo.a[2]*180.0/PI);
    printf("%.2lf , %.2lf , %.2lf ]\n",Servo.a[3]*180.0/PI,Servo.a[4]*180.0/PI,Servo.a[5]*180.0/PI);
}
#include "Matrix.h"

Point2D::Point2D()
{
	X = 0;
	Y = 0;
}

Point2D::Point2D(double x, double y)
{
	X = x;
	Y = y;
}

Point2D::Point2D(const Point2D &point)
{
	X = point.X;
	Y = point.Y;
}

Point2D::~Point2D()
{
}

double Point2D::Distance(Point2D &pt1, Point2D &pt2)
{
	double x = pt1.X - pt2.X;
	double y = pt1.Y - pt2.Y;
	return sqrt(x * x + y * y);
}

Point2D &Point2D::operator=(Point2D &point)
{
	X = point.X;
	Y = point.Y;
	return *this;
}

Point2D &Point2D::operator+=(Point2D &point)
{
	X += point.X;
	Y += point.Y;
	return *this;
}

Point2D &Point2D::operator-=(Point2D &point)
{
	X -= point.X;
	Y -= point.Y;
	return *this;
}

Point2D &Point2D::operator+=(double value)
{
	X += value;
	Y += value;
	return *this;
}

Point2D &Point2D::operator-=(double value)
{
	X -= value;
	Y -= value;
	return *this;
}

Point2D &Point2D::operator*=(double value)
{
	X *= value;
	Y *= value;
	return *this;
}

Point2D &Point2D::operator/=(double value)
{
	X /= value;
	Y /= value;
	return *this;
}

Point2D Point2D::operator+(Point2D &point)
{
	return Point2D(X + point.X, Y + point.Y);
}

Point2D Point2D::operator-(Point2D &point)
{
	return Point2D(X - point.X, Y - point.Y);
}

Point2D Point2D::operator+(double value)
{
	return Point2D(X + value, Y + value);
}

Point2D Point2D::operator-(double value)
{
	return Point2D(X - value, Y - value);
}

Point2D Point2D::operator*(double value)
{
	return Point2D(X * value, Y * value);
}

Point2D Point2D::operator/(double value)
{
	return Point2D(X / value, Y / value);
}

Point3D::Point3D()
{
	X = 0;
	Y = 0;
	Z = 0;
}

Point3D::Point3D(double x, double y, double z)
{
	X = x;
	Y = y;
	Z = z;
}

Point3D::Point3D(const Point3D &point)
{
	X = point.X;
	Y = point.Y;
	Z = point.Z;
}

Point3D::~Point3D()
{
}

double Point3D::Distance(Point3D &pt1, Point3D &pt2)
{
	double x = pt1.X - pt2.X;
	double y = pt1.Y - pt2.Y;
	double z = pt1.Z - pt2.Z;
	return sqrt(x * x + y * y + z * z);
}

Point3D &Point3D::operator=(const Point3D &point)
{
	X = point.X;
	Y = point.Y;
	Z = point.Z;
	return *this;
}

Point3D &Point3D::operator+=(Point3D &point)
{
	X += point.X;
	Y += point.Y;
	Z += point.Z;
	return *this;
}

Point3D &Point3D::operator-=(Point3D &point)
{
	X -= point.X;
	Y -= point.Y;
	Z -= point.Z;
	return *this;
}

Point3D &Point3D::operator+=(double value)
{
	X += value;
	Y += value;
	Z += value;
	return *this;
}

Point3D &Point3D::operator-=(double value)
{
	X -= value;
	Y -= value;
	Z -= value;
	return *this;
}

Point3D &Point3D::operator*=(double value)
{
	X *= value;
	Y *= value;
	Z *= value;
	return *this;
}

Point3D &Point3D::operator/=(double value)
{
	X /= value;
	Y /= value;
	Z /= value;
	return *this;
}

Point3D Point3D::operator+(Point3D &point)
{
	return Point3D(X + point.X, Y + point.Y, Z + point.Z);
}

Point3D Point3D::operator-(Point3D &point)
{
	return Point3D(X - point.X, Y - point.Y, Z - point.Z);
}

Point3D Point3D::operator+(double value)
{
	return Point3D(X + value, Y + value, Z + value);
}

Point3D Point3D::operator-(double value)
{
	return Point3D(X - value, Y - value, Z - value);
}

Point3D Point3D::operator*(double value)
{
	return Point3D(X * value, Y * value, Z * value);
}

Point3D Point3D::operator/(double value)
{
	return Point3D(X / value, Y / value, Z / value);
}

void Point3D::Print()
{
	printf("[ %.3lf , %.3lf , %.3lf ] \n",X,Y,Z);
}

Matrix3D::Matrix3D()
{
	Identity();
}

Matrix3D::Matrix3D(const Matrix3D &mat)
{
	*this = mat;
}

Matrix3D::~Matrix3D()
{
}

void Matrix3D::Identity()
{
	m[m00] = 1; m[m01] = 0; m[m02] = 0; m[m03] = 0;
	m[m10] = 0; m[m11] = 1; m[m12] = 0; m[m13] = 0;
	m[m20] = 0; m[m21] = 0; m[m22] = 1; m[m23] = 0;
	m[m30] = 0; m[m31] = 0; m[m32] = 0; m[m33] = 1;
}

bool Matrix3D::Inverse()
{
	Matrix3D src, dst, tmp;
	double det;

    /* transpose matrix */
    for (int i = 0; i < 4; i++)
    {
        src.m[i] = m[i*4];
        src.m[i + 4] = m[i*4 + 1];
        src.m[i + 8] = m[i*4 + 2];
        src.m[i + 12] = m[i*4 + 3];
    }

    /* calculate pairs for first 8 elements (cofactors) */
    tmp.m[0] = src.m[10] * src.m[15];
    tmp.m[1] = src.m[11] * src.m[14];
    tmp.m[2] = src.m[9] * src.m[15];
    tmp.m[3] = src.m[11] * src.m[13];
    tmp.m[4] = src.m[9] * src.m[14];
    tmp.m[5] = src.m[10] * src.m[13];
    tmp.m[6] = src.m[8] * src.m[15];
    tmp.m[7] = src.m[11] * src.m[12];
    tmp.m[8] = src.m[8] * src.m[14];
    tmp.m[9] = src.m[10] * src.m[12];
    tmp.m[10] = src.m[8] * src.m[13];
    tmp.m[11] = src.m[9] * src.m[12];
    /* calculate first 8 elements (cofactors) */
    dst.m[0] = (tmp.m[0]*src.m[5] + tmp.m[3]*src.m[6] + tmp.m[4]*src.m[7]) - (tmp.m[1]*src.m[5] + tmp.m[2]*src.m[6] + tmp.m[5]*src.m[7]);
    dst.m[1] = (tmp.m[1]*src.m[4] + tmp.m[6]*src.m[6] + tmp.m[9]*src.m[7]) - (tmp.m[0]*src.m[4] + tmp.m[7]*src.m[6] + tmp.m[8]*src.m[7]);
    dst.m[2] = (tmp.m[2]*src.m[4] + tmp.m[7]*src.m[5] + tmp.m[10]*src.m[7]) - (tmp.m[3]*src.m[4] + tmp.m[6]*src.m[5] + tmp.m[11]*src.m[7]);
    dst.m[3] = (tmp.m[5]*src.m[4] + tmp.m[8]*src.m[5] + tmp.m[11]*src.m[6]) - (tmp.m[4]*src.m[4] + tmp.m[9]*src.m[5] + tmp.m[10]*src.m[6]);
    dst.m[4] = (tmp.m[1]*src.m[1] + tmp.m[2]*src.m[2] + tmp.m[5]*src.m[3]) - (tmp.m[0]*src.m[1] + tmp.m[3]*src.m[2] + tmp.m[4]*src.m[3]);
    dst.m[5] = (tmp.m[0]*src.m[0] + tmp.m[7]*src.m[2] + tmp.m[8]*src.m[3]) - (tmp.m[1]*src.m[0] + tmp.m[6]*src.m[2] + tmp.m[9]*src.m[3]);
    dst.m[6] = (tmp.m[3]*src.m[0] + tmp.m[6]*src.m[1] + tmp.m[11]*src.m[3]) - (tmp.m[2]*src.m[0] + tmp.m[7]*src.m[1] + tmp.m[10]*src.m[3]);
    dst.m[7] = (tmp.m[4]*src.m[0] + tmp.m[9]*src.m[1] + tmp.m[10]*src.m[2]) - (tmp.m[5]*src.m[0] + tmp.m[8]*src.m[1] + tmp.m[11]*src.m[2]);
    /* calculate pairs for second 8 elements (cofactors) */
    tmp.m[0] = src.m[2]*src.m[7];
    tmp.m[1] = src.m[3]*src.m[6];
    tmp.m[2] = src.m[1]*src.m[7];
    tmp.m[3] = src.m[3]*src.m[5];
    tmp.m[4] = src.m[1]*src.m[6];
    tmp.m[5] = src.m[2]*src.m[5];
    //Streaming SIMD Extensions - Inverse of 4x4 Matrix 8
    tmp.m[6] = src.m[0]*src.m[7];
    tmp.m[7] = src.m[3]*src.m[4];
    tmp.m[8] = src.m[0]*src.m[6];
    tmp.m[9] = src.m[2]*src.m[4];
    tmp.m[10] = src.m[0]*src.m[5];
    tmp.m[11] = src.m[1]*src.m[4];
    /* calculate second 8 elements (cofactors) */
    dst.m[8] = (tmp.m[0]*src.m[13] + tmp.m[3]*src.m[14] + tmp.m[4]*src.m[15]) - (tmp.m[1]*src.m[13] + tmp.m[2]*src.m[14] + tmp.m[5]*src.m[15]);
    dst.m[9] = (tmp.m[1]*src.m[12] + tmp.m[6]*src.m[14] + tmp.m[9]*src.m[15]) - (tmp.m[0]*src.m[12] + tmp.m[7]*src.m[14] + tmp.m[8]*src.m[15]);
    dst.m[10] = (tmp.m[2]*src.m[12] + tmp.m[7]*src.m[13] + tmp.m[10]*src.m[15]) - (tmp.m[3]*src.m[12] + tmp.m[6]*src.m[13] + tmp.m[11]*src.m[15]);
    dst.m[11] = (tmp.m[5]*src.m[12] + tmp.m[8]*src.m[13] + tmp.m[11]*src.m[14]) - (tmp.m[4]*src.m[12] + tmp.m[9]*src.m[13] + tmp.m[10]*src.m[14]);
    dst.m[12] = (tmp.m[2]*src.m[10] + tmp.m[5]*src.m[11] + tmp.m[1]*src.m[9]) - (tmp.m[4]*src.m[11] + tmp.m[0]*src.m[9] + tmp.m[3]*src.m[10]);
    dst.m[13] = (tmp.m[8]*src.m[11] + tmp.m[0]*src.m[8] + tmp.m[7]*src.m[10]) - (tmp.m[6]*src.m[10] + tmp.m[9]*src.m[11] + tmp.m[1]*src.m[8]);
    dst.m[14] = (tmp.m[6]*src.m[9] + tmp.m[11]*src.m[11] + tmp.m[3]*src.m[8]) - (tmp.m[10]*src.m[11] + tmp.m[2]*src.m[8] + tmp.m[7]*src.m[9]);
    dst.m[15] = (tmp.m[10]*src.m[10] + tmp.m[4]*src.m[8] + tmp.m[9]*src.m[9]) - (tmp.m[8]*src.m[9] + tmp.m[11]*src.m[10] + tmp.m[5]*src.m[8]);
    /* calculate determinant */
    det = src.m[0]*dst.m[0] + src.m[1]*dst.m[1] + src.m[2]*dst.m[2] + src.m[3]*dst.m[3];
    /* calculate matrix inverse */
    if (det == 0)
    {
        det = 0;
        return false;
    }
    else
    {
        det = 1 / det;
    }

    for (int i = 0; i < MAXNUM_ELEMENT; i++)
        m[i] = dst.m[i] * det;

    return true;
}

/*
void Matrix3D::Rotate(double angle, Vector3D axis)
{
	double rad = angle;
	double C = cos(rad);
	double S = sin(rad);
	Matrix3D mat;

	mat.m[m00] = C + axis.X * axis.X * (1 - C);
	mat.m[m01] = axis.X * axis.Y * (1 - C) - axis.Z * S;
	mat.m[m02] = axis.X * axis.Z * (1 - C) + axis.Y * S;
	mat.m[m10] = axis.X * axis.Y * (1 - C) + axis.Z * S;
	mat.m[m11] = C + axis.Y * axis.Y * (1 - C);
	mat.m[m12] = axis.Y * axis.Z * (1 - C) - axis.X * S;
	mat.m[m20] = axis.X * axis.Z * (1 - C) - axis.Y * S;
	mat.m[m21] = axis.Y * axis.Z * (1 - C) + axis.X * S;
	mat.m[m22] = C + axis.Z * axis.Z * (1 - C);

	*this *= mat;
}
*/

Point3D Matrix3D::Transform(Point3D point)
{
	Point3D result;
	result.X = m[m00]*point.X + m[m01]*point.Y + m[m02]*point.Z + m[m03];
	result.Y = m[m10]*point.X + m[m11]*point.Y + m[m12]*point.Z + m[m13];
	result.Z = m[m20]*point.X + m[m21]*point.Y + m[m22]*point.Z + m[m23];

    return result;
}

void Matrix3D::SetTransform(Point3D point, Point3D angle)
{
	double Cx = cos(angle.X);
	double Cy = cos(angle.Y);
	double Cz = cos(angle.Z);
	double Sx = sin(angle.X);
	double Sy = sin(angle.Y);
	double Sz = sin(angle.Z);
	
	Identity();
	m[0] = Cz * Cy;
    m[1] = Cz * Sy * Sx - Sz * Cx;
    m[2] = Cz * Sy * Cx + Sz * Sx;
	m[3] = point.X;
    m[4] = Sz * Cy;
    m[5] = Sz * Sy * Sx + Cz * Cx;
    m[6] = Sz * Sy * Cx - Cz * Sx;
    m[7] = point.Y;
    m[8] = -Sy;
    m[9] = Cy * Sx;
    m[10] = Cy * Cx;
    m[11] = point.Z;
}

void Matrix3D::SetOnlyMove(Point3D point)
{
	Identity();
	m[3] = point.X;
    m[7] = point.Y;
    m[11] = point.Z;
}

void Matrix3D::SetOnlyRotate(Point3D angle)
{
	double Cx = cos(angle.X);
	double Cy = cos(angle.Y);
	double Cz = cos(angle.Z);
	double Sx = sin(angle.X);
	double Sy = sin(angle.Y);
	double Sz = sin(angle.Z);
	
	Identity();
	m[0] = Cz * Cy;
    m[1] = Cz * Sy * Sx - Sz * Cx;
    m[2] = Cz * Sy * Cx + Sz * Sx;
    m[4] = Sz * Cy;
    m[5] = Sz * Sy * Sx + Cz * Cx;
    m[6] = Sz * Sy * Cx - Cz * Sx;
    m[8] = -Sy;
    m[9] = Cy * Sx;
    m[10] = Cy * Cx;
}

Matrix3D & Matrix3D::operator = (const Matrix3D &mat)
{
	for (int i = 0; i < MAXNUM_ELEMENT; i++)
        m[i] = mat.m[i];
	return *this;
}

Matrix3D & Matrix3D::operator *= (const Matrix3D &mat)
{
	Matrix3D tmp = *this * mat;
	*this = tmp;
	return *this;
}

Matrix3D Matrix3D::operator * (const Matrix3D &mat)
{
	Matrix3D result;

    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int c = 0; c < 4; c++)
            {
				result.m[j*4+i] += m[j*4+c] * mat.m[c*4+i];
            }
        }
    }

	result.m[m00] = result.m[m00] - 1;
	result.m[m11] = result.m[m11] - 1;
	result.m[m22] = result.m[m22] - 1;
	result.m[m33] = result.m[m33] - 1;

	return result;
}

void Matrix3D::Print()
{
	printf("| %.3lf , %.3lf , %.3lf , %.3lf | \n",m[m00],m[m01],m[m02],m[m03]);
	printf("| %.3lf , %.3lf , %.3lf , %.3lf | \n",m[m10],m[m11],m[m12],m[m13]);
	printf("| %.3lf , %.3lf , %.3lf , %.3lf | \n",m[m20],m[m21],m[m22],m[m23]);
	printf("| %.3lf , %.3lf , %.3lf , %.3lf | \n",m[m30],m[m31],m[m32],m[m33]);
}
#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <math.h>
#include <stdio.h>
struct Anglex6
{
    double a[6];
};
typedef Anglex6 AngleSet;

class Point2D
{
  private:
  protected:
  public:
	double X;
	double Y;

	Point2D();
	Point2D(double x, double y);
	Point2D(const Point2D &point);
	~Point2D();

	static double Distance(Point2D &pt1, Point2D &pt2);

	Point2D &operator=(Point2D &point);
	Point2D &operator+=(Point2D &point);
	Point2D &operator-=(Point2D &point);
	Point2D &operator+=(double value);
	Point2D &operator-=(double value);
	Point2D &operator*=(double value);
	Point2D &operator/=(double value);
	Point2D operator+(Point2D &point);
	Point2D operator-(Point2D &point);
	Point2D operator+(double value);
	Point2D operator-(double value);
	Point2D operator*(double value);
	Point2D operator/(double value);
};

class Point3D
{
  private:
  protected:
  public:
	double X;
	double Y;
	double Z;

	Point3D();
	Point3D(double x, double y, double z);
	Point3D(const Point3D &point);
	~Point3D();

	static double Distance(Point3D &pt1, Point3D &pt2);

	Point3D &operator=(const Point3D &point);
	Point3D &operator+=(Point3D &point);
	Point3D &operator-=(Point3D &point);
	Point3D &operator+=(double value);
	Point3D &operator-=(double value);
	Point3D &operator*=(double value);
	Point3D &operator/=(double value);
	Point3D operator+(Point3D &point);
	Point3D operator-(Point3D &point);
	Point3D operator+(double value);
	Point3D operator-(double value);
	Point3D operator*(double value);
	Point3D operator/(double value);

	void Print();
};

class Matrix3D
{
public:
	enum
	{
		m00 = 0,
		m01,
		m02,
		m03,
		m10,
		m11,
		m12,
		m13,
		m20,
		m21,
		m22,
		m23,
		m30,
		m31,
		m32,
		m33,
		MAXNUM_ELEMENT
	};

private:
protected:
public:
	double m[MAXNUM_ELEMENT]; // Element

	Matrix3D();
	Matrix3D(const Matrix3D &mat);
	~Matrix3D();

	void Identity();
	bool Inverse();
	//void Rotate(double angle, Vector3D axis);
	Point3D Transform(Point3D point);
	void SetTransform(Point3D point, Point3D angle);
	void SetOnlyMove(Point3D point);
	void SetOnlyRotate(Point3D angle);
	Matrix3D &operator=(const Matrix3D &mat);
	Matrix3D &operator*=(const Matrix3D &mat);
	Matrix3D operator*(const Matrix3D &mat);

	void Print();
};


#endif
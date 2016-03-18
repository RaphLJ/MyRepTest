#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include "point.h"

using namespace std;

point::point()
{
	x = 0;
	y = 0;
	z = 0;
	h = 0;
	vx = 0;
	vy = 0;
	vz = 0;
	ax = 0;
	ay = 0;
	az = 0;
}

point::point(double dx, double dy, double dz)
{
	x = dx;
	y = dy;
	z = dz;
}

point::point(double dax, double day, double daz, double dh)
{
	x = 0;
	y = 0;
	z = 0;
	h = dh;
	vx = 0;
	vy = 0;
	vz = 0;
	ax = dax;
	ay = day;
	az = day;
}

double point::getX()
{
	return x;
}

double point::getY()
{
	return y;
}

double point::getZ()
{
	return z;
}

double point::getAx()
{
	return ax;
}

double point::getAy()
{
	return ay;
}

double point::getAz()
{
	return az;
}

double point::getH()
{
	return h;
}


#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include "point.h"

using namespace std;

class point
{
public:
	point();
	point(double dax, double day, double daz, double dh);
	point(double dx, double dy, double dz);
	double getX();
	double getY();
	double getZ();
	double getAx();
	double getAy();
	double getAz();
	double getH();

private:
	//coordonnées
	double x;
	double y;
	double z;
	//hauteur
	double h;
	//vitesse
	double vx;
	double vy;
	double vz;
	//accélération
	double ax;
	double ay;
	double az;

};

#endif


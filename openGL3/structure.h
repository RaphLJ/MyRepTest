#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include "fichiers.h"
#include "point.h"

void afficherParcours(vector<point> vPoints);
void repereXY(int taille);
void deplacement(int time, vector<point> vPoints);

#endif


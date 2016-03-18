#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "point.h"
#include "fichiers.h"
#include "structure.h"
#include "cameraGL.h"
#include <iostream>


#define PI 3.1415926535

using namespace std;

vector<point> vPoints;
bool autoriserAnim = false;
GLfloat xRotated, yRotated, zRotated;
double camX = 5.0, camY = 4.0, camZ = 3.0, cibleX = 0.0, cibleY = 0.0, cibleZ = 0.0;
double vitesseZoom = 0.1;
double vitesseRotation = 0.01;
double vitesseTranslation = 0.5;

int mouseButton;
int oldX, newX, oldY, newY;
bool rotaetAxixX = false;
double rotateAngle = 0.0;
double depth;

//variables sphère - déplacement
double sphX = 0, sphY = 0, sphZ = 0;
double time = 0, oldTime = 0;
bool go = false;//on enclenche le déplacement
bool pause = false;

void processSpecialKeys(int key, int x, int y);
void processNormalKeys(unsigned char key, int x, int y);//peut-être à changer. https://www.opengl.org/discussion_boards/showthread.php/183072-Cube-using-OpenGL-and-rotating-it-using-mouse-events
void mouseEvent(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void checkState(int state, int x, int y);
void Draw();
void Reshape(int x, int y);
void animation();
int numeroPoint;
int main(int argc, char *argv[])
{
	cout << "start..." << endl;

	cout << camX << " " << camY << " " << camZ << " " << cibleX << " " << cibleY << " " << cibleZ << endl;

	
	loadData(vPoints, "08154728.txt");
	/*for (double i = 0.0; i < 50.0; i += 0.01)
	{
		vPoints.push_back(point(i, 0, 5.0 * cos(i)));
	}*/

	//démarrage OpenGL
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	int WindowName = glutCreateWindow("Wally 01");
	//glutFullScreen();	//Optionnel

	glutSpecialFunc(processSpecialKeys);
	glutKeyboardFunc(processNormalKeys);
	glutMouseFunc(mouseEvent);
	glutMotionFunc(mouseMotion);
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Draw);
	glutIdleFunc(animation);

	//liste points du circuit
	cout << "Affiche main : " << vPoints[0].getAx();
	/*cout << "Entrer le numéro du point dont vous souhaitez obtenir les informations: ";
	cin >> numeroPoint;*/
	
	
	glutMainLoop();

	return 0;
}

void processNormalKeys(unsigned char key, int x, int y)
{
	double dx, dy;

	if (key == 27)
	{
		exit(0);
	}
	else if (key == 90 || key == 122)//z haut
	{
		camZ += vitesseTranslation;
		cibleZ += vitesseTranslation;
	}
	else if (key == 83 || key == 115)//s bas
	{
		camZ -= vitesseTranslation;
		cibleZ -= vitesseTranslation;
	}
	else if (key == 81 || key == 113)//q gauche
	{
		dx = vitesseTranslation * cos(atan((cibleY - camY) / (cibleX - camX)) + PI / 2);
		dy = vitesseTranslation * sin(atan((cibleY - camY) / (cibleX - camX)) + PI / 2);

		cout << dx << " " << dy << endl;

		camX -= dx;
		cibleX -= dx;

		camY -= dy;
		cibleY -= dy;
	}
	else if (key == 68 || key == 100)//d droite
	{
		dx = vitesseTranslation * cos(atan((cibleY - camY) / (cibleX - camX)) + PI / 2);
		dy = vitesseTranslation * sin(atan((cibleY - camY) / (cibleX - camX)) + PI / 2);

		camX += dx;
		cibleX += dx;

		camY += dy;
		cibleY += dy;
	}
	else if (key == 79 || key == 111)//o afficher sphère
	{
		if (go)
		{
			go = false;
		}
		else
		{
			go = true;
			sphX = vPoints.at(0).getX();
			sphY = vPoints.at(0).getY();
			sphZ = vPoints.at(0).getZ();
		}
	}
	else if (key == 80 || key == 112)//p pause
	{
		if (pause)
			pause = false;
		else
			pause = true;
	}

	cout << camX << " " << camY << " " << camZ << " " << cibleX << " " << cibleY << " " << cibleZ << endl;

}


void processSpecialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
	{
		std::cout << "zoom in" << endl;
		autoriserAnim = true;
		if (1)
		{
			camX -= vitesseZoom*(camX - cibleX);
			camY -= vitesseZoom*(camY - cibleY);
			camZ -= vitesseZoom*(camZ - cibleZ);
		}
		break;
	}

	case GLUT_KEY_DOWN:
	{
		std::cout << "zoom out" << endl;
		autoriserAnim = true;
		camX += vitesseZoom*(camX - cibleX);
		camY += vitesseZoom*(camY - cibleY);
		camZ += vitesseZoom*(camZ - cibleZ);
		break;
	}

	}
	cout << camX << " " << camY << " " << camZ << " " << cibleX << " " << cibleY << " " << cibleZ << endl;
}

void checkState(int state, int x, int y)
{
	switch (state) {
	case GLUT_UP:
		//cout<<" UP"<<endl;
		break;
	case GLUT_DOWN:
		//cout<<" DOWN"<<endl;
		break;
	};
}

void mouseEvent(int button, int state, int x, int y)
{
	mouseButton = button;
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			oldX = x;
			oldY = y;
		}
		checkState(state, x, y);
		autoriserAnim = true;
		break;
	case GLUT_RIGHT_BUTTON:
		//cout<<"RIGHT";
		checkState(state, x, y);
		autoriserAnim = true;
		break;
	case GLUT_MIDDLE_BUTTON:
		//cout<<"MIDDLE";
		checkState(state, x, y);
		autoriserAnim = true;
		break;
	case 3: //zoom in !!!! Attention ça pourrait changer
		camX -= vitesseZoom*(camX - cibleX);
		camY -= vitesseZoom*(camY - cibleY);
		camZ -= vitesseZoom*(camZ - cibleZ);
		checkState(state, x, y);
		autoriserAnim = true;
		break;
	case 4: //zoom out !!! Attention ça pourrait changer
		camX += vitesseZoom*(camX - cibleX);
		camY += vitesseZoom*(camY - cibleY);
		camZ += vitesseZoom*(camZ - cibleZ);
		checkState(state, x, y);
		autoriserAnim = true;
		break;
	}
}

void mouseMotion(int x, int y)
{
	if (mouseButton == GLUT_LEFT_BUTTON)
	{
		//rajouter fonctions rotation autour d'un point
	}

	autoriserAnim = true;
}



void Draw()
{
	glMatrixMode(GL_MODELVIEW);

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	//translation selon z (temporaire)
	glTranslatef(0.0, 0.0, 0.0);

	//rotation selon les trois axes
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	glRotatef(zRotated, 0.0, 0.0, 1.0);

	/*if (rotaetAxixX == true)
	glRotatef(rotateAngle, 1.0, 0.0, 0.0);
	else
	glRotatef(rotateAngle, 0.0, 1.0, 0.0);*/

	glMatrixMode(GL_MODELVIEW);

	//(pos. cam), (pos. cible), (vect. vert.)
	gluLookAt(camX, camY, camZ, cibleX, cibleY, cibleZ, 0, 0, 1);

	//affichage repère 3D
	glBegin(GL_LINES);
	glColor3d(255, 0, 0);
	glVertex3i(0, 0, 0); glVertex3i(0, 1, 0);
	glColor3d(0, 255, 0);
	glVertex3i(0, 0, 0); glVertex3i(1, 0, 0);
	glColor3d(0, 0, 255);
	glVertex3i(0, 0, 0); glVertex3i(0, 0, 1);
	glColor3d(255, 255, 255);
	glEnd();

	//affichage grille XY
	repereXY(20);

	afficherParcours(vPoints);

	//sphère
	if (go)
	{
		double tailleSphere = 1;
		glTranslatef(sphX, sphY, sphZ);
		glColor3d(255, 0, 0);
		glutSolidSphere(tailleSphere, tailleSphere * 20, tailleSphere * 20);
		glTranslatef(-sphX, -sphY, -sphZ);
	}

	glutSwapBuffers();
}

void Reshape(int x, int y)
{
	//Peut prendre 3 paramètres ==> GL_PROJECTION,GL_TEXTURE,GL_MODELVIEW ou même GL_COLOR
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//angle de vue: 70, 
	gluPerspective(70.0, (GLdouble)x / (GLdouble)y, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, x, y);  //Use the whole window for rendering
}


void animation()
{
	if (autoriserAnim == true)
	{
		autoriserAnim = false;
	}
	Draw();
}

void motion(vector<point> vPoints, double t, point point)
{

}

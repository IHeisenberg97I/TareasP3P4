#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <cmath>
#include "Ball.h"
#include "Sticks.h"

#define PI 3.1415926535
#define PI2 3.1415926535*2
using namespace std;

void changeViewPort(int w, int h)
{
	glViewport(0, 0, w, h);
}

int frame, time, timebase, oldTime;
char* s;
Ball ball(2.0f);
Sticks Player1(-5, 0, 5);
Sticks Player2(5, 0, 5);
bool Up = false, Down = false; //Flechas
bool W = false, S = false; //Letras

float dt;
float x_pos, y_pos;
float x_vel, y_vel;

void Input(int key, int y, int x) //Detecta los inputs
{
	switch (key)
	{
	case GLUT_KEY_UP:
		Up = true;
		break;
	case GLUT_KEY_DOWN:
		Down = true;
		break;
	}
}

//Flechas 
void InpRelease(int key, int y, int x)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		Up = false;
		break;
	case GLUT_KEY_DOWN:
		Down = false;
		break;
	}
}

//Presionar Tecla
void InputK(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		W = true;
		break;
	case 's':
		S = true;
		break;
	}
}

//Soltar las teclas
void InpReleaseK(unsigned char key, int y, int x)
{
	switch (key)
	{
	case 'w' :
		W = false;
		break;
	case 's':
		S = false;
		break;
	}
}

void OnStart() //Solo se llama al principio
{
	Player1.SetLimitY(2);
	Player2.SetLimitY(2);
	ball.LimitBall(6, 4);
}

/*void updateData() 
{
	ball->update(dt);
}*/

void render()
{
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(0, 1.0f, -10, //pos
		0, 0.0f, 0, //target
		0.0f, 1.0f, 0.0f);

	time = glutGet(GLUT_ELAPSED_TIME);
	dt = (time - oldTime) / 1000.0f;
	
	if (Up) Player1.Move(1, dt);
	if (Down) Player1.Move(-1, dt);
	if (W) Player2.Move(1, dt);
	if (S) Player2.Move(-1, dt);
	Player1.Draw();
	Player2.Draw();

	ball.update(dt);
	ball.draw();

	oldTime = time;
	glutSwapBuffers();
}

void changeSize(int w, int h)
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* argv[]) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	//glutInitWindowSize(1366, 768);
	glutInitWindowSize(1200, 800);
	glutCreateWindow("Pong de las tutorias estas jaja");
	//myInitialization();
	OnStart();
	// register callbacks
	glutDisplayFunc(render);
	glutReshapeFunc(changeSize);
	glutIdleFunc(render);
	//Teclas glut
	glutSpecialUpFunc(InpRelease);
	glutSpecialFunc(Input);
	//Teclas normales
	glutKeyboardFunc(InputK);
	glutKeyboardUpFunc(InpReleaseK);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();
}
#include "Sticks.h"
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

Sticks::Sticks() //Variables fijo
{
	x = 0;
	y = 0;
	scale = 5;
}

Sticks::Sticks(float _x, float _y, float _scale)  //Variables cambian
{
	x = _x;
	y = _y;
	scale = _scale;
}

void Sticks::Draw() //Dibuja
{
	glPushMatrix(); 
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 0, 0);
	glTranslatef(x, y, 0);
	glScalef(1, scale, 1);
	glBegin(GL_QUADS);
		glVertex3f(0.5f, 0.5f, 0);
		glVertex3f(-0.5f, 0.5f, 0);
		glVertex3f(-0.5f, -0.5f, 0);
		glVertex3f(0.5f, -0.5f, 0);
	glEnd();
	glPopMatrix();
}

void Sticks::Move(int Direction, float dt)
{
	float Increase = speed * dt;
	if (Direction > 0) //Arriba 
	{
		if (y + Increase < LimitY)
		{
			y += Increase;
		}
	}
	if (Direction < 0) //Abajo
	{
		if (y - Increase > -LimitY) //Checa que se cumpla el limite
		{
			y -= Increase;
		}
	}
}

void Sticks::SetLimitY(float NewLimit) //Pone Limite
{
	LimitY = NewLimit;
}

Sticks::~Sticks()
{

}

#include "Ball.h"
#include <GL/freeglut.h>
#include <cmath>
#include <iostream>

#define PI 3.1415926535
#define PI2 3.1415926535*2



Ball::Ball()
{
	setSize(1);
}

Ball::Ball(float size)
{
	setSize(size);
	setPos(0, 0, 0);
}

void Ball::draw() 
{
	glPushMatrix();
	glTranslatef(m_x, m_y, 0.0f);
	glScalef(0.2f, 0.2f, 0.2f);
	glBegin(GL_POLYGON);
	float x, y;
	glColor3f(1.0f, 1.0f, 0.9f);
	for (float x_val = -PI; x_val < PI; x_val += PI2 / 30) 
	{
		x = cos(x_val);
		y = sin(x_val);
		glVertex2f((x), (y));
	}
	glEnd();
	glPopMatrix();
}

void Ball::setPos(float x, float y, float z) 
{
	this->m_x = x;
	this->m_y = y;
	this->m_z = z;
}
void Ball::setSize(float z) 
{
	this->m_size = z;
}

void Ball::Reset()
{
	m_x = 0;
	m_y = 0;
}

void Ball::LimitBall(float x, float y)
{
	Limitm_x = x;
	Limitm_y = y;
}

void Ball::update(float dt)
{
	float IncreaseX = 1 * dt;

	float IncreaseY = 1 * dt;

	//Si va derecha
	if (Right)
	{
		//Si no se sale sigue moviendose
		if (m_x + IncreaseX < Limitm_x)
		{
			m_x += IncreaseX;
		}
		//Reinicia
		else 
		{
			Reset();
		}
	}
	else //Rebota
	{
		if (m_x - IncreaseX > -Limitm_x)
		{
			m_x -= IncreaseX;
		}
		//Reinicia
		else
		{
			Reset();
		}
	}

	//Si va arriba
	if (Up)
	{
		//Si no se sale sigue moviendose
		if (m_y + IncreaseY < Limitm_y)
		{
			m_y += IncreaseY;
		}
		//Cambia hacia abajo
		else
		{
			Up = false;
		} 
	}
	else //Regresa la bolita
	{
		if (m_y - IncreaseY > -Limitm_y)
		{
			m_y -= IncreaseY;
		}
		//Cambia haci aarriba
		else
		{
			Up = true;
		}
	}
}

Ball::~Ball()
{

}


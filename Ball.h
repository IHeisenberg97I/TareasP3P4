#pragma once
class Ball 
{
public:

	Ball();
	Ball(float);
	void draw();
	void update(float dt);
	void setPos(float, float, float);
	void setSize(float);
	void Reset();
	void LimitBall(float x, float y);
	virtual~Ball();

private:
	float m_size;
	float m_x, m_y, m_z;
	float colorR, colorG, colorB;
	float Limitm_x;
	float Limitm_y;
	bool Up = true;
	bool Right = true;
};

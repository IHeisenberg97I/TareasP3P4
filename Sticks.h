#pragma once
class Sticks
{
public: Sticks();
	  Sticks(float x, float y, float scale);
	  void Draw();

	  void Move(int Direction, float dt);

	  void SetLimitY(float NewLimit);

	  virtual ~Sticks();

private: 

	float x, y;
	float speed = 5;
	float scale;
	float LimitY = 1;
};


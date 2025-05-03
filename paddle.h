#pragma once
#include "raylib.h"

class Paddle {
protected:
	void LimitMovement();

public:
	Paddle();
	float x, y;
	float width, height;
	int speed;
	void Draw();
	void Reset();
	void Update();
	Rectangle GetRect();
	float GetWidth();
	float GetHeight();
	void ShrinkPaddle();

};
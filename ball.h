#pragma once
#include "raylib.h"
#include <string>

class Ball {
public:
	Ball();
	float x, y;
	int paddleSpeed;
	Vector2 speed;
	int ball_speed;
	float radius;
	bool inMotion = false;
	bool lifeLost = false;
	int topOfScreenHit = 0;
	int GetTopOfScreenhit();
	Vector2 GetSpeed();
	void SetSpeed(std::string axis, Vector2 newSpeed);	
	void IncreaseSpeed();
	void Draw();
	void Reset();
	void Update();
	void ReverseYAxis();
	void ReverseXAxis();
};
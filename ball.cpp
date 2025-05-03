#include "ball.h"

Ball::Ball() {
	radius = 10;

	x = (float)GetScreenWidth() / 2;
	y = (float)GetScreenHeight() - 41;
	speed.x = 0;
	speed.y = 0;
}

void Ball::Draw()
{	
	DrawCircle(x, y, radius, WHITE);	
}

void Ball::Reset() 
{
	inMotion = false;
	lifeLost = false;
	topOfScreenHit = 0;
	x = (float)GetScreenWidth() / 2;
	y = (float)GetScreenHeight() - 41;
	speed.x = 0;
	speed.y = 0;
	Draw();
}

void Ball::Update()
{
	x += speed.x;
	y += speed.y;

	if (y - radius <= 0) {
		ReverseYAxis();		
		topOfScreenHit++;		
	}
	if (x + radius >= GetScreenWidth()) {
		if (speed.x > 0) {
			ReverseXAxis();
		}
	}
		
	if (x - radius <= 0) {
		if (speed.x < 0) {
			ReverseXAxis();
		}
	}

	if (y + radius >= GetScreenHeight()) 
	{
		//if (speed.y > 0) {
		//	ReverseYAxis();
		//}
		lifeLost = true;
	}

	if (!inMotion) {
		if (IsKeyDown(KEY_LEFT)) {
			x = x - paddleSpeed;
		}
		if (IsKeyDown(KEY_RIGHT)) {
			x = x + paddleSpeed;
		}
		if (IsKeyDown(KEY_SPACE)) {
			inMotion = true;
			if (GetRandomValue(0, 1) == 0) {
				speed.x = 7;
			}
			else {
				speed.x = -7;
			}
			speed.y = -7;
		}
	}


}

int Ball::GetTopOfScreenhit()
{
	return topOfScreenHit;
}

Vector2 Ball::GetSpeed() {
	return speed;
}

void Ball::SetSpeed(std::string axis, Vector2 newSpeed)
{	
	if (axis.find("x") > -1) {
		speed.x = newSpeed.x;
	}
	if (axis.find("y") > -1) {
		speed.y = newSpeed.y;
	}
	
}

void Ball::IncreaseSpeed()
{
	float speedIncrease = 1;
	
	if (speed.x < 0) {
		speed.x -= speedIncrease;
	}
	else {
		speed.x += speedIncrease;
	}
	if (speed.y < 0) {
		speed.y -= speedIncrease;
	}
	else {
		speed.y += speedIncrease;
	}
	
}


void Ball::ReverseYAxis()
{
	speed.y *= -1;
}

void Ball::ReverseXAxis()
{
	speed.x *= -1;
}



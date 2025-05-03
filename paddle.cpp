#include "paddle.h"
#include <iostream>

Paddle::Paddle() {
	width = 90;
	height = 20;
	x = (float)GetScreenWidth() / 2 - width / 2;
	y = (float)GetScreenHeight() - height - 10;
}

void Paddle::LimitMovement()
{
	if (x <= 0) {
		x = 0;
	}

	if (x + width >= GetScreenWidth()) {
		x = GetScreenWidth() - width;
	}

}

void Paddle::Draw()
{
	DrawRectangle(x, y, width, height, WHITE);
}

void Paddle::Reset()
{
	width = 90;
	height = 20;
	x = (float)GetScreenWidth() / 2 - width / 2;
	y = (float)GetScreenHeight() - height - 10;
	Draw();
}



void Paddle::Update()
{
	if (IsKeyDown(KEY_LEFT)) {
		x = x - speed;
	}
	if (IsKeyDown(KEY_RIGHT)) {
		x = x + speed;
	}

	LimitMovement();
}

Rectangle Paddle::GetRect()
{
	return { x, y, width, height };
}

float Paddle::GetWidth() {
	return width;
}

float Paddle::GetHeight() {
	return height;
}

void Paddle::ShrinkPaddle()
{
	width = width / 2;
	Draw();
}

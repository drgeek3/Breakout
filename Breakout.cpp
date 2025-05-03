#include <iostream>
#include <raylib.h>
#include <vector>
#include "game.h"
#include "ball.h"



int main()
{
	const int screenWidth = 1280;
	const int screenHeight = 720;
	InitWindow(screenWidth, screenHeight, "Breakout");
	SetTargetFPS(60);

	Game game;

	while (!WindowShouldClose()) {
		BeginDrawing();

		game.Update();

		ClearBackground(BLACK);

		game.Draw();

		EndDrawing();
	}

	CloseWindow();
	return 0;
}


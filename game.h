#pragma once
#include "block.h"
#include "ball.h"
#include "paddle.h"
#include <vector>

class Game {
public:
	Game();
	~Game();
	void Draw();
	void Update();

private:
	int lives = 3;
	std::vector<Block> CreateBlocks();
	std::vector<Block> blocks;
	void InitGame();
	void CheckForCollisions();
	Ball ball;
	Paddle player;
	bool fourIncrease = false;
	bool twelveIncrease = false;
	bool orangeIncrease = false;
	bool redIncrease = false;
	int hitCount;
	bool paddleShrunk = false;
	void Levelup();
	void LoseLife();
	void ResetGame();
};



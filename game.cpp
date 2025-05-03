#include "game.h"
#include <iostream>

Game::Game()
{
	InitGame();
}

Game::~Game(){}

std::vector<Block> Game::CreateBlocks() {
	std::vector<Block> blocks;

	float x, y;
	float width, height;
	std::string colorDef;

	x = 0;
	y = (720 / 4) + 75;
	width = 87;
	height = 20;

	for (int row = 0; row < 8; row++) {
		if (row > 0) {
			y -= 25;
			x = 0;
		}
		for (int column = 0; column < 14; column++) {			
						
			if (row == 0 || row == 1) {
				colorDef = "YELLOW";
			}
			else if (row == 2 || row == 3) {
				colorDef = "GREEN";
			}
			else if (row == 4 || row == 5) {
				colorDef = "ORANGE";
			}
			else if (row == 6 || row == 7) {
				colorDef = "RED";
			}
			
			if (column > 0) { x += 92; }
			blocks.push_back(Block(colorDef, width, height, { x, y }));
		}
	}
	return blocks;
}


void Game::Draw() 
{
	for (auto& block : blocks) {
		block.Draw();
	}
	ball.Draw();
	player.Draw();
}

void Game::InitGame() 
{
	lives = 3;
	hitCount = 0;
	//set paddle speed
	int speed = 20;
	player.speed = speed;
	ball.paddleSpeed = speed;
	
	blocks = CreateBlocks();
}

void Game::Update()
{
	ball.Update();
	player.Update();
	CheckForCollisions();
	
	if (ball.GetTopOfScreenhit() == 1 && !paddleShrunk) {
		player.ShrinkPaddle();
		paddleShrunk = true;
	}

	if (ball.lifeLost) {
		LoseLife();
	}

	if (blocks.size() == 0) {

		Levelup();
	}

}

void Game::CheckForCollisions()
{
	if (ball.inMotion) {
		//ball to paddle
		if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radius, Rectangle{ player.x,player.y,player.width,player.height })) {
			Vector2 ballSpeed = ball.GetSpeed();
			if (ball.x < player.x + player.GetWidth()/2) {
				if (ballSpeed.x > 0) {
					ball.ReverseXAxis();
				}				
			}
			else if (ball.x > player.x + player.GetWidth()/2) {
				if (ballSpeed.x < 0) {
					ball.ReverseXAxis();
				}				
			}
			ball.ReverseYAxis();


		}
	}
	//ball to blocks
	auto it = blocks.begin();	
	while (it != blocks.end()) {
		if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, it->GetRect())) {
			hitCount++;			
			std::string rowColor = it->GetColor();
			if ((rowColor == "ORANGE" && !orangeIncrease) || (rowColor == "RED" && !redIncrease)) {
				if (rowColor == "ORANGE") { orangeIncrease = true; }
				if (rowColor == "RED") { redIncrease = true; }
				ball.IncreaseSpeed();
			}
			Vector2 ballSpeed = ball.GetSpeed();			
			if (hitCount == 4 || hitCount == 12) {
				ball.IncreaseSpeed();
			}

			Vector2 tempPosition = it->GetVariables();	
			
			if ((ball.x<tempPosition.x || ball.x > tempPosition.x + it->GetWidth()) && (ball.y < tempPosition.y + it->GetHeight() && ball.y > tempPosition.y)) {
				ball.ReverseXAxis();
			}
			else if ((ball.x<tempPosition.x || ball.x > tempPosition.x + it->GetWidth()) && (ball.y > tempPosition.y + it->GetHeight() || ball.y < tempPosition.y )){
				ball.ReverseYAxis();
				ball.ReverseXAxis();
			}
			else {
				ball.ReverseYAxis();
			}
			it = blocks.erase(it);						
		}
		else {
			++it;
		}
	}



}

void Game::Levelup()
{
	if (ball.y > (720 / 4) + 90) {
		blocks = CreateBlocks();
	}
}

void Game::LoseLife()
{
	lives--;
	if (lives > 0) {
		fourIncrease = false;
		twelveIncrease = false;
		orangeIncrease = false;
		redIncrease = false;
		ball.Reset();
		player.Reset();
	}
	else {
		if (IsKeyDown(KEY_SPACE)) {
			ResetGame();
		}
	}
	
}

void Game::ResetGame()
{
	lives = 3;
	fourIncrease = false;
	twelveIncrease = false;
	orangeIncrease = false;
	redIncrease = false;	
	ball.Reset();
	player.Reset();
	InitGame();
}



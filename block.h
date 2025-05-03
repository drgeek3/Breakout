#pragma once
#include <raylib.h>
#include <string>

class Block {
public: 
	Block(std::string inColor, float width, float height, Vector2 position);
	Color color;
	std::string colorDef;
	Vector2 position;
	float width;
	float height;
	void Draw();
	Rectangle GetRect();
	Vector2 GetVariables();
	float GetWidth();
	float GetHeight();
	std::string GetColor();
};

#include "block.h"



Block::Block(std::string inColor, float width, float height, Vector2 position)
{
	colorDef = inColor;
	this->position = position;
	this->width = width;
	this->height = height;

	if (colorDef == "YELLOW") {
		color = YELLOW;
	}
	else if (colorDef == "GREEN") {
		color = GREEN;
	}
	else if (colorDef == "ORANGE") {
		color = ORANGE;
	}
	else if (colorDef == "RED") {
		color = RED;
	}

}

void Block::Draw()
{
	DrawRectangle(position.x, position.y, width, height, color);
}

Rectangle Block::GetRect()
{
	return { position.x, position.y, width, height };
}

Vector2 Block::GetVariables()
{
	return position;
}

float Block::GetWidth() {
	return width;
}

float Block::GetHeight() {
	return height;
}

std::string Block::GetColor() {
	return colorDef;
}

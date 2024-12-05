#pragma once
#include <raylib.h>
#include <iostream>
#include <memory>


class Paddle
{
public:

	Paddle(int vely, int posy, int posx, int width, int height)
	{
		paddle = std::make_unique<Rectangle>();
		velY = vely;
		posY = posy;
		posX = posx;
		paddle->width = width;
		paddle->height = height;
		paddle->x = posX;
		paddle->y = posY;
	}

	Paddle()
	{
		velY = 5;
		posY = 270;
		posX = 50;
		paddle->width = 10;
		paddle->height = 100;
		paddle->x = posX;
		paddle->y = posY;
	}


	void movePaddle(const int screenHeight)
	{
		if ((posY < screenHeight - paddle->height) || posY>0)
		{
			posY += dir * velY;
			paddle->y = posY;
		}
	}

	std::pair<int, int> getPos(int screenWidth)
	{
		int pX{ 0 };
		if (posX > screenWidth / 2)
		{
			pX = posX;
		}
		else
		{
			pX = posX + paddle->width;
		}
		std::pair<int, int> pair = std::make_pair(pX, posY);
		return pair;
	}

	int getHeight()
	{
		return paddle->height;
	}

	void drawPaddle(Color color)
	{
		DrawRectangleRec(*paddle, color);
	}

	void setDirection(int dir)
	{
		this->dir = dir;
	}

private:
	std::unique_ptr<Rectangle> paddle;
	int velY;
	int posY;
	int posX;
	int dir{ 0 };

};
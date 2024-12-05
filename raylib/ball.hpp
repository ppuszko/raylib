#pragma once
#include <raylib.h>
#include "paddle.hpp"
#include <thread>

class Ball
{
public:

	Ball(int x, int y, int velX, int velY, float radius)
	{
		position.x = x;
		position.y = y;
		velocity.x = velX;
		velocity.y = velY;
		this->radius = radius;
		isInGame = true;
	}

	Ball()
	{
		position.x = 400;
		position.y = 315;
		velocity.x = 5;
		velocity.y = 5;
		this->radius = 10;
		isInGame = true;
	}

	void changePos(int screenHeight, int screenWidth)
	{
		position.y += velocity.y;
		position.x += velocity.x;

		if ((position.y <= radius/2) || position.y >= screenWidth - radius/2)
		{
			velocity.y *= -1;
		}
		if ((position.x <= radius/2) || (position.x >= screenWidth - radius/2))
		{
			isInGame = false;
		}
		printPosition();
	}

	void checkCollision(Paddle &leftPaddle, Paddle &rightPaddle, int screenWidth)
	{
		int paddlePosY = rightPaddle.getPos(screenWidth).second;
		int paddlePosX = rightPaddle.getPos(screenWidth).first;
		int paddleHeight = rightPaddle.getHeight();

		//right paddle collision check
		if ((position.x - radius / 2 >= paddlePosX) && (position.y >= paddlePosY && position.y <= paddlePosY + paddleHeight))
		{
			velocity.x *= -1;
		}

		paddlePosY = leftPaddle.getPos(screenWidth).second;
		paddlePosX = leftPaddle.getPos(screenWidth).first;
		paddleHeight = rightPaddle.getHeight();

		//left paddle collision check
		if ((position.x - radius / 2 <= paddlePosX) && (position.y >= paddlePosY && position.y <= paddlePosY + paddleHeight))
		{
			velocity.x *= -1;
		}

	}

	void drawBall(Color color)
	{
		DrawCircleV(position, radius, color);
	}

	int getVelocityX()
	{
		return velocity.x;
	}
	int getIsInGame()
	{
		return isInGame;
	}

	void resetBall(int screenWidth, int screenHeight)
	{
		position.x = screenWidth / 2;
		position.y = screenHeight / 2;
	}

	void printPosition()
	{
		std::cout << "pos X: " << position.x << "pos Y: " << position.y << std::endl;
		
	}

private:
	Vector2 position;
	Vector2 velocity;
	float radius;
	bool isInGame;
};
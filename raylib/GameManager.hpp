#pragma once
#include "paddle.hpp"
#include "ball.hpp"
#include <string>

class GameManager
{
	
public:
	GameManager(int paddleVelocity,
		int paddleWidth, int paddleHeight, 
		int ballVelX, int ballVelY, 
		float ballRadius, int screenWidth, 
		int screenHeight, int paddleOffset, Color color = MAGENTA)
		:
		leftPaddle(paddleVelocity, (screenHeight / 2) - paddleHeight / 2, paddleOffset, paddleWidth, paddleHeight),
		rightPaddle(paddleVelocity, (screenHeight / 2) - paddleHeight / 2, screenWidth - paddleOffset - paddleWidth, paddleWidth, paddleHeight),
		ball(screenWidth / 2, screenHeight / 2, ballVelX, ballVelY, ballRadius),
		score(0, 0), col(color), scrWidth(screenWidth), scrHeight(screenHeight)  { }

	void initWindow()
	{
		InitWindow(scrWidth, scrHeight, "pong");
	}

	void handleInput()
	{
		if (IsKeyDown(KEY_W) && leftPaddle.getPos(scrHeight).second > 0) leftPaddle.setDirection(-1);
		else if (IsKeyDown(KEY_S) && leftPaddle.getPos(scrHeight).second < scrHeight - leftPaddle.getHeight()) leftPaddle.setDirection(1);
		else leftPaddle.setDirection(0);
		
		if (IsKeyDown(KEY_UP) && rightPaddle.getPos(scrHeight).second > 0) rightPaddle.setDirection(-1);
		else if (IsKeyDown(KEY_DOWN) && rightPaddle.getPos(scrHeight).second < scrHeight - rightPaddle.getHeight()) rightPaddle.setDirection(1);
		else rightPaddle.setDirection(0);
	}



	void initializeGame()
	{
		SetTargetFPS(60);
		while (!WindowShouldClose())
		{
			if (score.first < 3 && score.second < 3)
			{
				drawScore();
				handleInput();
				BeginDrawing();
				ClearBackground(BLACK);

				leftPaddle.drawPaddle(col);
				rightPaddle.drawPaddle(col);

				leftPaddle.movePaddle(scrHeight);
				rightPaddle.movePaddle(scrHeight);

				ball.drawBall(col);
				ball.changePos(scrHeight);
				ball.checkCollision(leftPaddle, rightPaddle, scrWidth);

				trackScore();

				
			}
			else{
				ClearBackground(BLACK);
				drawScore();
				DrawText(TextFormat("%s Game Over!"), scrWidth / 2 - MeasureText("%s Game Over!", 50), scrHeight / 9, 50, col);
			
			}
			EndDrawing();
		}
		CloseWindow();
	}

	void drawScore()
	{
		DrawText(TextFormat(std::to_string(score.first).c_str()), scrWidth/2 - MeasureText("   ", 50) * 2, scrHeight / 10, 50, col);
		DrawText(TextFormat(" - "), scrWidth / 2 - MeasureText("   ", 50), scrHeight / 10, 50, col);
		DrawText(TextFormat(std::to_string(score.first).c_str()), scrWidth/2 + MeasureText("   ", 50) * 2, scrHeight / 10, 50, col);
	
	}

	//void gameLoop()
	//{
	//	while (!WindowShouldClose())
	//	{
	//		initializeGame();
	//		
	//	}
	//
	//}

	void trackScore()
	{
		if (ball.getIsInGame() == false)
		{
			if (ball.getVelocityX() < 0)
			{
				score.second += 1;
			}
			else if(ball.getVelocityX() > 0)
			{
				score.first += 1;
			}
			ball.resetBall(scrWidth, scrHeight);
		}
	}

	
private:
	Paddle leftPaddle;
	Paddle rightPaddle;
	Ball ball;
	std::pair<int, int> score;
	Color col;
	int scrWidth;
	int scrHeight;

};
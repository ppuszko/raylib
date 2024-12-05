#include <raylib.h>
#include <iostream>
#include "GameManager.hpp"

int main()
{
	//define window size
	const int SCREEN_WIDTH{ 800 };
	const int SCREEN_HEIGHT{ 640 };

	GameManager gameMan(7, 10, 100, 4, 4, 10.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 50);

    std::cout<< gameMan.ball.getVelocityX();

	SetTargetFPS(60);
	gameMan.initWindow();
	gameMan.gameLoop();


	//const std::string name{ "Pong" };

	//InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "pong");

	////left paddle
	//Rectangle leftPaddle{ 50, SCREEN_HEIGHT/2 - 60, 10, 100};

	////right paddle
	//Rectangle rightPaddle{ SCREEN_WIDTH - 60, SCREEN_HEIGHT/2 - 60, 10, 100};

	////paddle speed
	//int paddleSpeed{ 7 };


	////ball configuration
	//Vector2 ballPosition{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	//Vector2 ballSpeed{ 4.0f, 4.0f };
	//float ballRadius{10.0f};

	//SetTargetFPS(60);

	//while (!WindowShouldClose())
	//{
	//	if (IsKeyDown(KEY_W) && leftPaddle.y > 0) leftPaddle.y -= paddleSpeed;
	//	if (IsKeyDown(KEY_S) && leftPaddle.y < SCREEN_HEIGHT - leftPaddle.height) leftPaddle.y += paddleSpeed;
	//	if (IsKeyDown(KEY_UP) && rightPaddle.y > 0) rightPaddle.y -= paddleSpeed;
	//	if (IsKeyDown(KEY_DOWN) && rightPaddle.y < SCREEN_HEIGHT - rightPaddle.height) rightPaddle.y += paddleSpeed;

	//	ballPosition.x += ballSpeed.x;
	//	ballPosition.y += ballSpeed.y;

	//	BeginDrawing();
	//	ClearBackground(BLACK);

	//	DrawRectangleRec(leftPaddle, MAGENTA);
	//	DrawRectangleRec(rightPaddle, MAGENTA);
	//	DrawCircleV(ballPosition, ballRadius, MAGENTA);

	//	if (ballPosition.y >= SCREEN_HEIGHT - ballRadius || ballPosition.y <= 0 + ballRadius) ballSpeed.y = -ballSpeed.y;
	//	if (CheckCollisionCircleRec(ballPosition, ballRadius, leftPaddle)
	//		|| CheckCollisionCircleRec(ballPosition, ballRadius, rightPaddle))
	//	{
	//		ballSpeed.x = -ballSpeed.x;
	//	}

	//	if (ballPosition.x <= ballRadius || ballPosition.x >= SCREEN_WIDTH - ballRadius)
	//	{
	//		DrawText(name.c_str(), 350, 20, 50, MAGENTA);
	//	}
	//	
	//	EndDrawing();
	//}

	//CloseWindow();
	//std::cout << "game over! \n";
}


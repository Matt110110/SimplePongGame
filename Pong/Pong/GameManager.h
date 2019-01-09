#pragma once
#include "Ball.h"
#include "Paddle.h"
#include <iostream>
#include <time.h>
#include <conio.h>

class GameManager
{
private:
	int _width, _height, _score1, _score2;
	char _up1, _down1, _up2, _down2;
	bool _quit;
	Ball * _b;
	Paddle * _p1;
	Paddle * _p2;
public:
	void ScoreUp(Paddle * p);
	GameManager(int width, int height);
	GameManager();
	~GameManager();
};


#include "pch.h"
#include "GameManager.h"


void GameManager::ScoreUp(Paddle * p)
{
	if (p == _p1)
		_score1++;
	else if (p == _p2)
		_score2++;
	_b->Reset();
	_p1->Reset();
	_p2->Reset();
}

GameManager::GameManager(int width, int height)
{
	std::srand(time(NULL));
	_quit = false;
	_up1 = 'w';
	_up2 = 'i';
	_down1 = 's';
	_down2 = 'k';
	_score1 = _score2 = 0;
	_width = width;
	_height = height;
	_b = new Ball(width / 2, height / 2);
	_p1 = new Paddle(1, height / 2 - 3);
	_p2 = new Paddle(width - 2, height / 2 - 3);
}

GameManager::GameManager()
{
	delete _b, _p1, _p2;
}


GameManager::~GameManager()
{
}

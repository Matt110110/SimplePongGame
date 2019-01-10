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

void GameManager::Draw()
{
	system("cls"); // Windows only
	
	// Top border of the wall
	for (int i = 0; i < _width + 2; i++)
	{
		std::cout << "\xB2";
	}
	std::cout << std::endl;

	// Side walls
	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			int ballX = _b->getX();
			int ballY = _b->getY();
			int player1X = _p1->getX();
			int player2X = _p2->getX();
			int player1Y = _p1->getY();
			int player2Y = _p2->getY();
			
			// Prints the left side wall
			if (j == 0)
			{
				std::cout << "\xB2";
			}

			if (ballX == j && ballY == i)
			{
				std::cout << "O"; // Ball
			}
			else if ((player1X == j && player1Y == i) || (player1X == j && player1Y + 1 == i) || (player1X == j && player1Y + 2 == i) || (player1X == j && player1Y + 3 == i))
			{
				std::cout << "\xDB"; // Player 1
			}
			else if ((player2X == j && player2Y == i) || (player2X == j && player2Y + 1 == i) || (player2X == j && player2Y + 2 == i) || (player2X == j && player2Y + 3 == i))
			{
				std::cout << "\xDB"; // Player 2
			}
			else
			{
				std::cout << " ";
			}
			// Prints the right side wall
			if (j ==  _width - 1)
			{
				std::cout << "\xB2";
			}
		}
		std::cout << std::endl;
	}
	// Bottom border of the wall
	for (int i = 0; i < _width + 2; i++)
	{
		std::cout << "\xB2";
	}
	std::cout << std::endl;
	std::cout << "Score 1 : " << _score1 << "\tScore 2 : " << _score2 << std::endl;
}

/*
Function to move the ball
*/
void GameManager::Input()
{
	_b->Move();

	int ballX = _b->getX();
	int ballY = _b->getY();
	int player1X = _p1->getX();
	int player2X = _p2->getX();
	int player1Y = _p1->getY();
	int player2Y = _p2->getY();

	if (_kbhit()) // To get the character repeatedly
	{
		char current = _getch();
		if (current == _up1)
		{
			if (player1Y > 0)
			{
				_p1->moveUp();
			}
		}
		if (current == _up2)
		{
			if (player2Y > 0)
			{
				_p2->moveUp();
			}
		}
		if (current == _down1)
		{
			if (player1Y + 4 < _height)
			{
				_p1->moveDown();
			}
		}
		if (current == _down2)
		{
			if (player2Y + 4 < _height)
			{
				_p2->moveDown();
			}
		}

		if (_b->getDirection() == eDir::STOP)
		{
			_b->RandomDirection();
		}

		if (current == 'q')
		{
			_quit = true;
		}
	}
}

void GameManager::Logic()
{
	int ballX = _b->getX();
	int ballY = _b->getY();
	int player1X = _p1->getX();
	int player2X = _p2->getX();
	int player1Y = _p1->getY();
	int player2Y = _p2->getY();

	// Left paddle
	for (int i = 0; i < 4; i++)
	{
		if (ballX == player1X + 1)
		{
			if (ballY == player1Y + i)
			{
				_b->ChangeDirection((eDir)((std::rand() % 3) + 4));
			}
		}
	}

	// Right paddle
	for (int i = 0; i < 4; i++)
	{
		if (ballX == player2X - 1)
		{
			if (ballY == player2Y + i)
			{
				_b->ChangeDirection((eDir)((std::rand() % 3) + 1));
			}
		}
	}

	// Bottom wall
	if (ballY == _height - 1)
	{
		_b->ChangeDirection(_b->getDirection() == eDir::DOWNRIGHT ? eDir::UPRIGHT : eDir::UPLEFT);
	}

	// Top wall
	if (ballY == 0)
	{
		_b->ChangeDirection(_b->getDirection() == eDir::UPRIGHT ? eDir::DOWNRIGHT : eDir::DOWNLEFT);
	}

	// Right wall
	if (ballX == _width - 1)
	{
		ScoreUp(_p1);
	}
	// Left wall
	if (ballX == 0)
	{
		ScoreUp(_p2);
	}
}

void GameManager::Run()
{
	while (!_quit)
	{
		Draw();
		Input();
		Logic();
	}
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

#include "pch.h"
#include "Ball.h"
#include <stdlib.h>


Ball::Ball()
{
}

Ball::Ball(int posX, int posY)
{
	_originalX = _x = posX;
	_originalY = _y = posY;
	_direction = eDir::STOP;
}

void Ball::Reset()
{
	_x = _originalX;
	_y = _originalY;
	_direction = eDir::STOP;
}

void Ball::RandomDirection()
{
	_direction = (eDir)((rand() % 6) + 1);
}

void Ball::ChangeDirection(eDir d)
{
	_direction = d;
}

inline int Ball::getX()
{
	return _x;
}

inline int Ball::getY()
{
	return _y;
}

inline eDir Ball::getDirection()
{
	return _direction;
}


Ball::~Ball()
{
}

#include "pch.h"
#include "Ball.h"
#include <iostream>


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
	_direction = (eDir)((std::rand() % 6) + 1);
}

void Ball::ChangeDirection(eDir d)
{
	_direction = d;
}

void Ball::Move()
{
	switch (_direction)
	{
	case eDir::STOP:
		break;
	case eDir::LEFT:
		_x--;
		break;
	case eDir::UPLEFT:
		_x--;
		_y--;
		break;
	case eDir::DOWNLEFT:
		_x--;
		_y++;
		break;
	case eDir::RIGHT:
		_x++;
		break;
	case eDir::UPRIGHT:
		_x++;
		_y--;
		break;
	case eDir::DOWNRIGHT:
		_x++;
		_y++;
		break;
	default:
		break;
	}
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

std::ostream & operator<<(std::ostream & o, Ball b)
{
	o << "Ball [ " << b._x << " , " << b._y << " ] [ " << (int)b._direction << " ]" << std::endl;
	return o;
}

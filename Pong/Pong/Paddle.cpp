#include "pch.h"
#include "Paddle.h"


void Paddle::Reset()
{
	_x = _originalX;
	_y = _originalY;
}

int Paddle::getX()
{
	return _x;
}

int Paddle::getY()
{
	return _y;
}

void Paddle::moveUp()
{
	_y--;
}

void Paddle::moveDown()
{
	_y++;
}

Paddle::Paddle()
{
	_x = _y = 0;
}

Paddle::Paddle(int posX, int posY) : Paddle()
{
	_originalX = _x = posX;
	_originalY = _y = posY;
}


Paddle::~Paddle()
{
}

std::ostream & operator<<(std::ostream & o, Paddle p)
{
	o << "Paddle [ " << p.getX() << " , " << p.getY() << " ]";
	return o;
}

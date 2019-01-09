#pragma once
#include <iostream>
/*
* All private variables start with underscore (_)
* Don't use Using namespace std in class files.
*/
enum class eDir // Since this is a enumeration class use eDir::<value> to access the value
{
	STOP = 0,
	LEFT = 1,
	UPLEFT = 2,
	DOWNLEFT = 3,
	RIGHT = 4,
	UPRIGHT = 5,
	DOWNRIGHT = 6
};

class Ball
{
private:
	int _x, _y, _originalX, _originalY;
	eDir _direction;
public:
	// Constructors
	Ball();
	Ball(int posX, int posY);

	// Void functions
	void Reset();
	void RandomDirection();
	void ChangeDirection(eDir d);
	void Move();

	friend std::ostream & operator << (std::ostream & o, Ball b);

	// Getters
	inline int getX();
	inline int getY();
	inline eDir getDirection();

	// Destructors
	~Ball();
};



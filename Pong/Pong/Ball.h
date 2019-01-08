#pragma once
/*
* All private variables start with underscore (_)
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

	// Getters
	inline int getX();
	inline int getY();
	inline eDir getDirection();
	~Ball();
};



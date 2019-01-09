#pragma once
#include <iostream>

class Paddle
{
private:
	int _x, _y, _originalX, _originalY;

public:
	// Inline void functions
	void Reset();
	void moveUp();
	void moveDown();

	// Getter functons
	int getX();
	int getY();
	
	// declaring the << operator
	friend std::ostream & operator << (std::ostream & o, Paddle p);
	// Constructors and destructors
	Paddle();
	Paddle(int posX, int posY);
	~Paddle();
};


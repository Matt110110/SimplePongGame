// Pong.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Ball.h"
#include "Paddle.h"
#include "GameManager.h"
#include <iostream>
using namespace std;

int main()
{
	/*Ball b(0, 0);
	cout << b << endl;
	b.RandomDirection();
	cout << b << endl;
	b.Move();
	cout << b << endl;
	b.RandomDirection();
	b.Move();
	cout << b << endl;
	b.RandomDirection();
	b.Move();
	cout << b << endl;*/

	//Paddle p1(0, 0);
	//Paddle p2(10, 0);
	//cout << p1 << endl;
	//cout << p2 << endl;
	//p1.moveUp();
	////p1.Reset();
	//p2.moveDown();
	//cout << p1 << endl;
	//cout << p2 << endl;

	GameManager g(40, 20);
	g.Run();

	getchar(); // Added to hold the console instead of going straight to return 0
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

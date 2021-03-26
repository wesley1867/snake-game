#pragma once
#include <string>
#include <thread>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
using namespace std;
class snakegame
{
private:
	const int FieldWidth = 60;
	const int FieldHeight = 25;
	int sx, sy, fx, fy, score, dir;
	int Sbodx[100], Sbody[100];
public:
	void Smove();
	void Input();
	void Logic();
	void Draw_Field();
	bool gameOver = 0;
	void gameset();
	void die();
	void Cfruit();
};


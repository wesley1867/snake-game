#include "snakegame.h"

//game setup
void snakegame::gameset() { 
	sx = FieldWidth / 2; sy = FieldHeight / 2; 
	fx = rand() % (FieldWidth - 2); fy = rand() % (FieldHeight - 2); score = 0; 
}
//move snake body
void snakegame::Smove() {
	Sbodx[0] = sx;
	Sbody[0] = sy;
	for (int i = 0; i < score; i++) {
		int x, y;
		x = Sbodx[i];
		y = Sbody[i];
		Sbodx[i] = Sbodx[0];
		Sbody[i] = Sbody[0];
		Sbodx[0] = x;
		Sbody[0] = y;
	}
}

// Draw Field
void snakegame::Draw_Field() {	
	cout << "Score: " << score << endl;
	for (int h = 0; h < FieldHeight; h++)
	{
		cout << "#";
		for (int w = 0; w < FieldWidth - 2; w++)
		{
			if (h == 0 || h == FieldHeight - 1) cout << '#'; // # as boundary
			else if (h == sy && w == sx) cout << 'O'; // O as snake head
			else if (h == fy && w == fx) cout << '@'; // @ as fruit
			else {
				bool Body = false;
				for (int i = 0; i < score; i++) {
					if (w == Sbodx[i] && h == Sbody[i]) {
						cout << 'o';
						Body = true;
						break;
					}
				}
				if (!Body) cout << ' ';
			}
		}
		cout << "#\n";
	}
};
//game logic
void snakegame::Logic() {
	switch (dir)
	{
	case 1:
		sy--;
		this_thread::sleep_for(50ms);
		break;
	case 2:
		sy++;
		this_thread::sleep_for(50ms);
		break;
	case 3:
		sx--;
		this_thread::sleep_for(10ms);
		break;
	case 4:
		sx++;
		this_thread::sleep_for(10ms);
		break;
	default:
		break;
	}
	Cfruit();
	die();
}
// create food
void snakegame::Cfruit() {
	if (sx == fx && sy == fy) {
		score += 1;
		fx = rand() % (FieldWidth - 2) + 1;
		fy = rand() % (FieldHeight - 2) + 1;
	}
}
// test if the snake is die
void snakegame::die() {
	if (sx < 0 || sx > FieldWidth - 3 || sy < 1 || sy >FieldHeight - 2) gameOver = 1;
	for (int i = 0; i < score; i++) {
		if (Sbodx[i] == sx && Sbody[i] == sy) gameOver = true;
	}
}
// input direction of the snake by user
void snakegame::Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			dir = 1;
			break;
		case 's':
			dir = 2;
			break;
		case 'a':
			dir = 3;
			break;
		case 'd':
			dir = 4;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}
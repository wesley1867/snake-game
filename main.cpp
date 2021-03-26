#include "snakegame.h"

int main() {
	srand(time(0));
	snakegame a;
	a.gameset();
	while (a.gameOver == 0)
	{
	// Draw Field
	a.Draw_Field();
	// input direction by user
	a.Input();
	//move snake body
	a.Smove();
	// game logic
	a.Logic();
	// Clear Screen
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
	}
	return 0;
}
#pragma once

#include "Board.h"
#include "Figure.h"
#include "Bomb.h"
#include "Menu.h"
enum { ESC = 27 };//escape
enum { RAND = 7 };

class TheGame
{
	Menu menu;
	Board GameBoard;
public:
	TheGame() {}; //ctor
	void resetBoard()
	{
		GameBoard.initBoard();
	}
	Figure& createFigure(int numOfPlayer, int* serialNum);
	void RunGame();
	void clearKeyBoardBuffer()const;
	bool MoveFigure(Board& board, Figure& f, int serialNum, char direction); // קוראת לפונקציות תזוזה לפי המקשים
	bool MoveFigure(Board& board, Bomb& f, int serialNum, char direction); // קוראת לפונקציות תזוזה לפי המקשים
	bool WinCheck(int NumPlayer)const;
	void HideCursor();
	int Rand();
};
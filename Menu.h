#pragma once
#include "Board.h"
enum MenuKeys { START = '1', PAUSE1 = '2', INSTRUCTIO_KEYS = '8', EXIT = '9' };

class Menu 
{
public:
	void StartNewGame(char key_char, int& y1, int& y2, Board& GameBoard);
	void ShowInstructions()const;
	void ContinuePausedGame(char key_char, Board& GameBoard);
	void ExitGame()const;
	void printMenu()const;
};

#include "TheGame.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>
char LeftPlayerKeys[10] = { 'a','A','d','D','s','S','w','W','x','X' };
char RightPlayerKeys[10] = { 'j','J','l','L','k','K','i','I','m','M' };

void TheGame::RunGame()
{
	char key_char = 0;
	int y1 = Y1;
	int y2 = Y2;
	int counter1 = 0, counter2 = 0;
	int serialNum1 = -1;
	int serialNum2 = -1;
	menu.printMenu();
	while (key_char != EXIT)
	{
		HideCursor();
		if (key_char == START || _kbhit())
		{
			if (key_char != START && key_char!=INSTRUCTIO_KEYS && key_char != ESC)
			{
				key_char = _getch();
			}
			if (key_char == INSTRUCTIO_KEYS)
			{
				menu.ShowInstructions();
			}
			else if (key_char == START)
			{
				serialNum1 = Rand();
				Figure f1 = createFigure(LEFT_PLAYER, &serialNum1);
				serialNum2 = Rand();
				Figure f2 = createFigure(RIGHT_PLAYER, &serialNum2);
				
				if (serialNum1 == 7)
				{
					Bomb f1(LEFT_PLAYER);
				}
				if (serialNum2 == 7)
				{
					Bomb f2(RIGHT_PLAYER);
				}

				
				while (key_char != EXIT && WinCheck(LEFT_PLAYER) == false && WinCheck(RIGHT_PLAYER) == false)
				{
					clearKeyBoardBuffer();
					
					f1.print(this->GameBoard);
					Sleep(100);
					
					
					f2.print(this->GameBoard);
					Sleep(100);
					

					++y1;
					++y2;

					if (_kbhit())
					{
						key_char = _getch();
						if (key_char == INSTRUCTIO_KEYS)
						{
							gotoxy(0, ROWS + 7);
							menu.ShowInstructions();
						}
						else if (key_char == ESC)
						{
							menu.ContinuePausedGame(key_char, this->GameBoard);
							menu.printMenu();
						}
						else
						{
							clearKeyBoardBuffer();
							for (int i = 0; i < 10; i++)
							{
								if (LeftPlayerKeys[i] == key_char)
								{
									if (MoveFigure(this->GameBoard, f1, serialNum1, key_char) == false)
									{
										y1 = 1;
										GameBoard.DeleteRow(LEFT_PLAYER);
									}
									else
									{
										f1.print(this->GameBoard);
									}
									break;
								}
								if (RightPlayerKeys[i] == key_char)
								{
									if (MoveFigure(this->GameBoard, f2, serialNum2, key_char) == false)
									{
										y2 = 1;
										GameBoard.DeleteRow(RIGHT_PLAYER);

									}
									else
									{
										f2.print(this->GameBoard);
									}
									break;

								}
							}
						}
					}
					clearKeyBoardBuffer();
					if (f1.update(this->GameBoard, serialNum1, DOWN) == false ||y1 > ROWS )
					{
						y1 = 1;
						GameBoard.DeleteRow(LEFT_PLAYER);
						f1 = createFigure(LEFT_PLAYER, &serialNum1);
					}

					if (y2 > ROWS || f2.update(this->GameBoard, serialNum2, DOWN) == false)
					{
						y2 = 1;
						GameBoard.DeleteRow(RIGHT_PLAYER);
						f2 = createFigure(RIGHT_PLAYER, &serialNum2);
					}
				}

			}
			if (key_char == EXIT)
			{
				menu.ExitGame();
			}
			if (WinCheck(LEFT_PLAYER) == true || WinCheck(RIGHT_PLAYER) == true)
			{
				menu.StartNewGame(key_char, y1, y2, this->GameBoard);
					
			}
		}
	} 



}
int TheGame:: Rand()
{
	int randFigure = rand() % RAND; //0-7
	return randFigure;
}

bool TheGame::MoveFigure(Board& board, Figure& f, int serialNum, char direction) // קוראת לפונקציות תזוזה לפי המקשים
{
	if (direction == 'A' || direction == 'a' || direction == 'j' || direction == 'J')
	{
		
		return f.update(board, serialNum,LEFT);
		
	}
	else if (direction == 'D' || direction == 'd' || direction == 'L' || direction == 'l')
	{
		return f.update(board, serialNum,RIGHT);
	}
	else if (direction == 'K' || direction == 'k' || direction == 'S' || direction == 's')
	{
		return f.update(board, serialNum,CLOCKWISE);
	}
	else if (direction == 'I' || direction == 'i' || direction == 'W' || direction == 'w')
	{
		return f.update(board, serialNum, COUNTERCLOCKWISE);
	}
	else //if(direction == ' ' || direction == 'X' || direction == 'x' || direction == 'M' || direction == 'm')
	{
		
		return f.update(board, serialNum,DOWN);
	}
}
bool TheGame::MoveFigure(Board& board, Bomb& f, int serialNum, char direction) // קוראת לפונקציות תזוזה לפי המקשים
{
	if (direction == 'A' || direction == 'a' || direction == 'j' || direction == 'J')
	{
		return f.update(board, serialNum, LEFT);
	}
	else if (direction == 'D' || direction == 'd' || direction == 'L' || direction == 'l')
	{
		return f.update(board, serialNum, RIGHT);
	}
	else if (direction == 'K' || direction == 'k' || direction == 'S' || direction == 's')
	{
		return f.update(board, serialNum, CLOCKWISE);
	}
	else if (direction == 'I' || direction == 'i' || direction == 'W' || direction == 'w')
	{
		return f.update(board, serialNum, COUNTERCLOCKWISE);
	}
	else //if(direction == ' ' || direction == 'X' || direction == 'x' || direction == 'M' || direction == 'm')
	{

		return f.update(board, serialNum, DOWN);
	}
}

Figure& TheGame::createFigure(int numOfPlayer, int* serialNum)
{
	switch (*serialNum)
	{
	case 0:
	{
		Figure line(LINE, numOfPlayer);

		*serialNum = LINE;

		return line;


		break;

	}
	case 1:
	{
		Figure L1(L, numOfPlayer);
		*serialNum = L;
		return L1;
		break;
	}
	case 2:
	{
		Figure RL1(RL, numOfPlayer);
		*serialNum = RL;
		return RL1;
		break;
	}
	case 3:
	{
		Figure Square1(SQUARE, numOfPlayer);
		*serialNum = SQUARE;
		return Square1;

		break;
	}
	case 4:
	{
		Figure RZ1(RZ, numOfPlayer);
		*serialNum = RZ;
		return RZ1;

		break;
	}
	case 5:
	{
		Figure Z1(Z, numOfPlayer);
		*serialNum = Z;

		return Z1;

		break;
	}
	case 6:
	{
		Figure Plus1(PLUS, numOfPlayer);
		*serialNum = PLUS;
		return Plus1;
		break;
	}
	}
}


void TheGame::clearKeyBoardBuffer()const
{
	char junk;
	while (_kbhit())
	{
		junk = _getch();
	}
}
bool TheGame::WinCheck(int NumPlayer)const
{
	bool IsLoser = false;
	if (NumPlayer == LEFT_PLAYER)
	{
		if (this->GameBoard.IsFull4(1, NumPlayer) == true)
			IsLoser = true;
		if (IsLoser == true)
		{
			gotoxy(4, 14);
			cout << "Player2 is the WINNER!";
		}
	}
	else
	{
		if (this->GameBoard.IsFull4(1, NumPlayer) == true)
			IsLoser = true;
		if (IsLoser == true)
		{
			gotoxy(4, 14);
			cout << "Player1 is the WINNER!";
		}
	}
	return IsLoser;
}
void TheGame::HideCursor()
{
	HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CURSOR;
	CURSOR.dwSize = 1;
	CURSOR.bVisible = FALSE;
	SetConsoleCursorInfo(myconsole, &CURSOR);

}





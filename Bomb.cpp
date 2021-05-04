#include "Bomb.h"
#include <iostream>
using namespace std;


void Bomb::initBomb(int x, int y)
{
	bomb.SetPoint(x, y, true, '$');
}
bool Bomb::update(Board& board,int serialNum, int dir)
{
	switch (dir)
	{
	case BombDirections::DropBomb:
	{
		if (board.isValidPoint(bomb.getX(), bomb.gety() + 1))
		{
			board.turnToBusyPoint(bomb.getX(), bomb.gety(), bomb.getChar());
		}
		else
		{
			explodeBomb(board);
		}
		break;
	}
	case BombDirections::LeftBomb:
	{
		if (board.isValidPoint(bomb.getX() - 1, bomb.gety()))
		{
			board.turnToBusyPoint(bomb.getX() - 1, bomb.gety(), bomb.getChar());
		}
		else
		{
			explodeBomb(board);
		}
		break;
	}
	case BombDirections::RightBomb:
	{
		if (board.isValidPoint(bomb.getX() + 1, bomb.gety()))
		{
			board.turnToBusyPoint(bomb.getX() + 1, bomb.gety(), bomb.getChar());
		}
		else
		{
			explodeBomb(board);
		}
		break;
	}
	}
	return true;
}

void Bomb::explodeBomb(Board& board)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			
			if (board.isValidPointForBomb(bomb.getX() - 4 + i, bomb.gety() - 4 + j))
			{
				board.turnToFreePoint(bomb.getX() - 4 + i, bomb.gety() - 4 + j);
			}
			
		}
	}
}
void Bomb::print(Board& board)
{
	board.turnToBusyPoint(bomb.getX(), bomb.gety(), bomb.getChar());
}
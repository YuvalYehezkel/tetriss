#pragma once
#include "Figure.h"
#include "Board.h"
#include "general.h"
enum BombDirections { DropBomb = 1, LeftBomb = 2, RightBomb = 3 };

class Bomb: public general 
{
	Point bomb;
public:
	Bomb() {};
	Bomb(int playerNum) {
		if (playerNum == LEFT_PLAYER)
		{
			initBomb(X1, Y1);
		}
		else if (playerNum == RIGHT_PLAYER)
		{
			initBomb(X2, Y2);
		}
	}
	void initBomb(int x, int y);
	bool update(Board& board, int serialNum, int dir);
	void explodeBomb(Board& board);
	void print(Board& board);
};
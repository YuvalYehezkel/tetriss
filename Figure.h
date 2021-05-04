#pragma once
#include "Board.h"
#include "general.h"
#include <iostream>
enum SHAPES { LINE = 0, L = 1, RL = 2, SQUARE = 3, Z = 4, RZ = 5, PLUS = 6, BOMB = 7};//RT=reversed T=  *
																	 //=          *** 
enum startValue { X1 = 5, Y1 = 1, X2 = 18, Y2 = 1 };
enum dir { LEFT = 1, RIGHT = 2, DOWN = 3, CLOCKWISE = 4, COUNTERCLOCKWISE = 5 };
class Figure:public general
{
	enum { SIZE = 4 };
	Point FigureBody[SIZE];
	int RotateNum = 0;
public:
	//// empty ctor
	Figure()
	{

	}
	Figure(int serialNum, int playerNum)
	{
		if (playerNum == LEFT_PLAYER)
		{
			initFigureBySerialNum(serialNum, X1, Y1);
		}
		else if (playerNum == RIGHT_PLAYER)
		{
			initFigureBySerialNum(serialNum, X2, Y2);
		}


	};
	void setRotateNum(int num)
	{
		RotateNum = num;
	}
	int getRotateNum()const
	{
		return RotateNum;
	}

	void initFigureBySerialNum(int serialNum, int x, int y);
	void print(Board& board);
	bool update(Board& board, int serialNum, int dir);
	bool updateFigureDrop(Board& board, int serialNum);
	bool updateFigureLeft(Board& board, int serialNum);
	bool updateFigureRight(Board& board, int serialNum);
	bool updateFigureRotateClockWise(Board& board, int serialNum);
	bool updateFigureRotateCounterClockWise(Board& board, int serialNum);

};

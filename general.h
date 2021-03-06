#pragma once
#include "Point.h"
#include "Board.h"

class general {
	enum { SIZE = 4 };
	Point FigureBody[SIZE];
public:
	virtual bool update(Board& board, int serialNum, int dir) = 0;
	
	virtual void print(Board& board) = 0;
	
};

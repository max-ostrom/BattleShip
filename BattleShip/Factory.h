#pragma once
#include"UnionHeader.h"
class IFactory
{
public:
	virtual Ship* createShip(char field[10][10]) = 0;
};


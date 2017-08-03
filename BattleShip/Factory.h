#pragma once
#include"UnionHeader.h"
class IFactory
{
public:
	virtual IShip* createShip(char field[10][10]) = 0;
	virtual ~IFactory() {}
};


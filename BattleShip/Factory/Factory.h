#pragma once
#include "..\UnionHeader.h"
class IFactory
{
public:
	virtual Ship* createShip(char field[FIELDSIZE][FIELDSIZE]) = 0;
	virtual ~IFactory() {};
};


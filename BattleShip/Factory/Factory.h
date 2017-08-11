#pragma once
#include "..\UnionHeader.h"

#include <memory>
class IFactory
{
public:
	virtual std::shared_ptr<Ship>  createShip(char field[FIELDSIZE][FIELDSIZE]) = 0;
	virtual ~IFactory() {};
};


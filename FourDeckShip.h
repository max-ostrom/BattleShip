#pragma once
#include "SingleDeckShip.h"
class FourDeckShip :
	public Ship
{
public:
	FourDeckShip(char field[10][10]);
	int GetShipSize() override;
	~FourDeckShip();
};


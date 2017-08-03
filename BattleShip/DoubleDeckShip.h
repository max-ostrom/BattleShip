#pragma once
#include "SingleDeckShip.h"
class DoubleDeckShip :
	public IShip
{
public:
	DoubleDeckShip(char field[10][10]);
	virtual int getShipSize() override;
	~DoubleDeckShip();
};


#pragma once
#include "SingleDeckShip.h"
class ThreeDeckShip :
	public IShip
{
public:
	ThreeDeckShip(char field[10][10]);
	virtual int getShipSize() override;
	~ThreeDeckShip();
};


#pragma once
#include "SingleDeckShip.h"
class ThreeDeckShip :
	public Ship
{
public:
	ThreeDeckShip(char field[10][10]);
	virtual int GetShipSize() override;
	~ThreeDeckShip();
};

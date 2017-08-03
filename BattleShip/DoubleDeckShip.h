#pragma once
#include "SingleDeckShip.h"
class DoubleDeckShip :
	public Ship
{
public:
	DoubleDeckShip(char field[10][10]);
	virtual int getShipSize()const  override;
};


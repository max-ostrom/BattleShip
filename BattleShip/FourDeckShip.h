#pragma once
#include "SingleDeckShip.h"
class FourDeckShip :
	public IShip
{
public:
	FourDeckShip(char field[10][10]);
	virtual int getShipSize() override;
	~FourDeckShip();

	
};


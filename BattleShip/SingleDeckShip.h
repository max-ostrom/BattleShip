#pragma once

#include "Ship.h"


#include <ctime>
#include <iostream>
using namespace std;
class SingleDeckShip :
	public IShip
{
public:
	SingleDeckShip(char field[10][10]);
	virtual int getShipSize() override;
	
	~SingleDeckShip();
};


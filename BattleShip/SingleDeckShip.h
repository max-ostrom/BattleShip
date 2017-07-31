#pragma once

#include "Ship.h"
#include <ctime>
#include <iostream>
using namespace std;
class SingleDeckShip :
	public Ship
{
public:
	SingleDeckShip(char field[10][10]);
	virtual int GetShipSize() override;
	
	~SingleDeckShip();
};

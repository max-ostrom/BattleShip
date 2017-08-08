#pragma once

#include "Ship.h"

#include <ctime>
#include <iostream>

using namespace std;

class SingleDeckShip :
	public Ship
{
public:
	SingleDeckShip(char field[FIELDSIZE][FIELDSIZE]);
	virtual const int& getShipSize()const override;
private:
	virtual bool isCellFreeHorizontal(const char field[FIELDSIZE][FIELDSIZE], const int m, const int n)const override;
	virtual bool isCellFreeVertical(const char field[FIELDSIZE][FIELDSIZE], const int m, const int n)const override;
	const int SHIPSIZE = 1;
};


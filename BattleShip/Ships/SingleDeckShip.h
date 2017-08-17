#ifndef SingleDeckShip_H
#define SingleDeckShip_H

#include "Ship.h"

#include <ctime>
#include <iostream>

using namespace std;

class SingleDeckShip :
	public Ship
{
public:
	SingleDeckShip(char field[FIELD_SIZE][FIELD_SIZE]);
	virtual const int& getShipSize()const override;
private:
	virtual bool isCellFreeHorizontal(const char field[FIELD_SIZE][FIELD_SIZE], const int m, const int n)const override;
	virtual bool isCellFreeVertical(const char field[FIELD_SIZE][FIELD_SIZE], const int m, const int n)const override;
	const int SHIP_SIZE_ = 1;
};

#endif
#ifndef DoubleDeckShip_H
#define DoubleDeckShip_H

#include "SingleDeckShip.h"

class DoubleDeckShip :
	public Ship
{
public:
	DoubleDeckShip(char field[FIELD_SIZE][FIELD_SIZE]);
	virtual const int& getShipSize()const  override;
private:
	virtual bool isCellFreeHorizontal(const char field[FIELD_SIZE][FIELD_SIZE], const int m, const int n)const override;
	virtual bool isCellFreeVertical(const char field[FIELD_SIZE][FIELD_SIZE], const int m, const int n)const override;
	const int SHIP_SIZE_ = 2;
};
#endif

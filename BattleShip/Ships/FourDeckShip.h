#ifndef FourDeckShip_H
#define FourDeckShip_H

#include "SingleDeckShip.h"

class FourDeckShip :
	public Ship
{
public:
	FourDeckShip(char field[FIELDSIZE][FIELDSIZE]);
	virtual const int& getShipSize()const  override;
private:
	virtual bool isCellFreeHorizontal(const char field[FIELDSIZE][FIELDSIZE], const int m, const int n)const override;
	virtual bool isCellFreeVertical(const char field[FIELDSIZE][FIELDSIZE], const int m, const int n)const override;
	const int SHIPSIZE_ = 4;
	
};
#endif

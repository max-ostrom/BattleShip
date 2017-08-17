#ifndef ThreeDeckShip_H
#define ThreeDeckShip_H

#include "SingleDeckShip.h"
class ThreeDeckShip :
	public Ship
{
public:
	ThreeDeckShip(char field[FIELDSIZE][FIELDSIZE]);
	virtual const int& getShipSize()const  override;
private:
	virtual bool isCellFreeHorizontal(const char field[FIELDSIZE][FIELDSIZE], const int m, const int n)const override;
	virtual bool isCellFreeVertical(const char field[FIELDSIZE][FIELDSIZE], const int m, const int n)const override;
	const int SHIPSIZE_ = 3;
};
#endif

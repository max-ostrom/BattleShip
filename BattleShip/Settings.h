#ifndef Settings_H
#define Settings_H

#include "IShipSettings.h"

class Settings :
	public IShipSettings
{
public:
	
	const int getThreeDeckShipCounter() const override;
	const int getDoubleDeckShipCounter() const override;
	const int getSingleDeckShipCounter() const override;
private:
	
	const int THREEDECKSHIPCOUNTER_ = 2;
	const int DOUBLEDECKSHIPCOUNTER_ = 3;
	const int SINGLEDECKSHIPCOUNTER_ = 4;
};
#endif

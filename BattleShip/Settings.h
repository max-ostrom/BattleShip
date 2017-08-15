#pragma once
#include "IShipSettings.h"
#include "IFieldSettings.h"
class Settings :
	public IShipSettings
{
public:
	
	const int getThreeDeckShipCounter() const override;
	const int getDoubleDeckShipCounter() const override;
	const int getSingleDeckShipCounter() const override;
private:
	
	const int ThreeDeckShipCounter = 2;
	const int DoubleDeckShipCounter = 3;
	const int SingleDeckShipCounter = 4;
};


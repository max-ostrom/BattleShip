#pragma once
#include "IShipSettings.h"
#include "IFieldSettings.h"
class Settings :
	public IShipSettings,public IFieldSettings
{
public:
	const int getFieldSize()const override;
	const int getThreeDeckShipCounter() const override;
	const int getDoubleDeckShipCounter() const override;
	const int getSingleDeckShipCounter() const override;
private:
	const int FIELDSIZE = 10;
	const int ThreeDeckShipCounter = 2;
	const int DoubleDeckShipCounter = 3;
	const int SingleDeckShipCounter = 4;
};


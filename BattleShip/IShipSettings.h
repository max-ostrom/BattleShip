#pragma once
class IShipSettings
{
public:

	virtual const int getThreeDeckShipCounter() const = 0;
	virtual const int getDoubleDeckShipCounter() const = 0;
	virtual const int getSingleThreeDeckShipCounter() const = 0;
	virtual ~IShipSettings()
	{
	}
};


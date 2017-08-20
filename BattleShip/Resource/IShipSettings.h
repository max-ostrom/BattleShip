#ifndef IShipSettings_H
#define IShipSettings_H

class IShipSettings
{
public:

	virtual const int getThreeDeckShipCounter() const = 0;
	virtual const int getDoubleDeckShipCounter() const = 0;
	virtual const int getSingleDeckShipCounter() const = 0;
	virtual ~IShipSettings()
	{
	}
};
#endif

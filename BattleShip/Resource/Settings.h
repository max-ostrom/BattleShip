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

    const int THREEDECK_SHIP_COUNTER_ = 2;
    const int DOUBLEDECK_SHIP_COUNTER_ = 3;
    const int SINGLEDECK_SHIP_COUNTER_ = 4;
};
#endif

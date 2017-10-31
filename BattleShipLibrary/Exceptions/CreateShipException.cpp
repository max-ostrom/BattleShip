#include "CreateShipException.h"


CreateShipException::CreateShipException(const std::string ShipType)
{
    shipType_ = ShipType;
}

char const * CreateShipException::what() const
{
    std::string returnString = "Can not create";
    returnString.append(shipType_);
    returnString.append(" ship");
    return returnString.c_str();
}

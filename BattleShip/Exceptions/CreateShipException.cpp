#include "CreateShipException.h"


char const * CreateShipException::what() const
{
    return "Can not create ship";
}

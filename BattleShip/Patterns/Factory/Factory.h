#ifndef Factory_H
#define Factory_H

#include "..\..\Resource\UnionHeader.h"

#include <new>
#include <memory>

class IFactory
{
public:
    virtual std::shared_ptr<Ship>
        createShip(char field[STANDART_FIELD][STANDART_FIELD]) = 0;
    virtual ~IFactory() {};
};
#endif

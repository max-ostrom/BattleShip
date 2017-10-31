#ifndef Factory_H
#define Factory_H

#include "..\..\Resource\UnionHeader.h"
#include "..\..\Exceptions\CreateShipException.h"
#include <new>
#include <memory>
namespace BattleShip
{
    class IFactory
    {
    public:
        virtual std::shared_ptr<Ship>
            createShip(char field[STANDART_FIELD][STANDART_FIELD]) = 0;
        virtual ~IFactory() {};
    };
}
#endif

#ifndef IPlayer_H
#define IPlayer_H

#include <vector>
#include <memory>

#include "..\Ships\Ship.h"
#include "IField.h"
#include "..\..\BattleShipLibrary\Patterns\Observer\Observable.h"
namespace BattleShip
{
    class IPlayer :
        public IField
    {
    public:
        virtual bool isEndOfGame() const = 0;
        virtual bool isShipAlive(std::shared_ptr<Ship> Ship_) = 0;
        virtual std::vector<std::shared_ptr<Ship>>& getShips() = 0;
        virtual const std::vector<std::shared_ptr<Ship>>& getShips() const = 0;
        virtual ~IPlayer() {}
        virtual bool operator==(const IPlayer& p)const = 0;
    };
}
#endif

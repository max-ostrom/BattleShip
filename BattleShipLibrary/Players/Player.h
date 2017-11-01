#ifndef Player_H
#define Player_H

#include <iostream>
#include <vector>

#include "..\Patterns\Factory\Factory.h"
#include "..\Patterns\Factory\FactoryDoubleShip.h"
#include "..\Patterns\Factory\FactoryFourShip.h"
#include "..\Patterns\Factory\FactorySingleShip.h"
#include "..\Patterns\Factory\FactoryThreeShip.h"

#include "..\Resource\Settings.h"
#include "..\Resource\UnionHeader.h"
#include "IPlayer.h"
#include "PlayerHelper.h"
// must have class PlayerHelper !!!!
namespace BattleShip
{
    class Player :
        public IPlayer
    {
    public:
        std::vector<std::shared_ptr<Ship>>& getShips() override;
        const std::vector<std::shared_ptr<Ship>>& getShips() const override;
        Player(list<shared_ptr<IFactory>> Factories);
        virtual ~Player();
        void setField(const int i, const int j) override;
        void setEnemyField(const int i, const  int j, IField* p) override;
        bool isShipAlive(shared_ptr<Ship> Ship_) override;
        bool isEndOfGame() const override;

        char getField(const int i, const int j) const override;
        char getEnemyField(const int i, const int j) const override;
        bool operator==(const IPlayer& p)const override;
        void fillCellsAroundShip(shared_ptr<Ship> Ship_);
    private:
        std::vector<std::shared_ptr<Ship>> YourShips_;

        char yourField_[STANDART_FIELD][STANDART_FIELD];
        char enemyField_[STANDART_FIELD][STANDART_FIELD];

        void addShip(shared_ptr<IFactory> factory);
    };
}
#endif
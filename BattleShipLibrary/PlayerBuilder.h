#pragma once
#include "IBuilder.h"
#include "Patterns\Factory\Factory.h"
#include "Resource\IShipSettings.h"
namespace BattleShip 
{
    class PlayerBuilder :
        public IBuilder
    {
    public:
        PlayerBuilder() {}
        virtual void setSettings() override;
        virtual void setFactories() override;
        virtual std::shared_ptr<IPlayer> biuld() override;
    private:
        std::list<std::shared_ptr<IFactory>> Factories;
        shared_ptr<IShipSettings> settings;
    };
}

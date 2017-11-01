#pragma once
#include "Players\IPlayer.h"
namespace BattleShip 
{
    
    class IBuilder
    {
    public:
        virtual void setSettings() = 0;
        virtual void setFactories() = 0;
        virtual std::shared_ptr<IPlayer> biuld() = 0;
        virtual ~IBuilder() {}
    };
}

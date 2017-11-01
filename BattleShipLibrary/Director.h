
#pragma once
#include "Players\IPlayer.h"
#include "IBuilder.h"
namespace BattleShip 
{
    class Director
    {
    public:
        std::shared_ptr<IPlayer> createPlayer(IBuilder& builder)
        {
            builder.setSettings();
            builder.setFactories();
            return builder.biuld();
        }
    };
}

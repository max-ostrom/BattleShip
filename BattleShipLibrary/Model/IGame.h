#ifndef IGame_H
#define IGame_H

#include"../Players/IPlayer.h"
namespace BattleShip
{
    class IGame
    {
    public:
        virtual IPlayer& getUser() = 0;
        virtual IPlayer& getComputer() = 0;
        virtual const IPlayer& getUser() const = 0;
        virtual const IPlayer& getComputer() const = 0;
        virtual ~IGame()
        {
        }
    };
}
#endif

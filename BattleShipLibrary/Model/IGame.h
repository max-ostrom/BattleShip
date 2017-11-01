#ifndef IGame_H
#define IGame_H

#include"../Players/IPlayer.h"
namespace BattleShip
{
    class IGame
    {
    public:
        virtual shared_ptr<IPlayer> getUser() = 0;
        virtual shared_ptr<IPlayer> getComputer() = 0;
        virtual const shared_ptr<IPlayer> getUser() const = 0;
        virtual const shared_ptr<IPlayer> getComputer() const = 0;
        virtual ~IGame()
        {
        }
    };
}
#endif

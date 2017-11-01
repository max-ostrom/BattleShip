#ifndef Game_H
#define Game_H

#include "../Players/Player.h"
#include "ITime.h"
#include "IGame.h"
namespace BattleShip 
{
    class GameModel final :
        public IGame
    {
    public:
        shared_ptr<IPlayer> getUser() override;
        shared_ptr<IPlayer> getComputer() override;
        const shared_ptr<IPlayer> getUser() const override;
        const shared_ptr<IPlayer> getComputer() const override;
        GameModel(shared_ptr<IPlayer> you, shared_ptr<IPlayer> computer);
    private:
        shared_ptr<IPlayer> You_;
        shared_ptr<IPlayer> Computer_;
    };
}
#endif

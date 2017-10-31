#ifndef Game_H
#define Game_H

#include "../../BattleShipLibrary/Players/Player.h"
#include "ITime.h"
#include "IGame.h"

class GameModel final :
    public IGame
{
public:
    IPlayer& getUser() override;
    IPlayer& getComputer() override;
    const IPlayer& getUser() const override;
    const IPlayer& getComputer() const override;
    GameModel(IPlayer& you, IPlayer& computer);
private:
    IPlayer& You_;
    IPlayer& Computer_;
};
#endif

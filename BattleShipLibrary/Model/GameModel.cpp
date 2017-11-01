#include "GameModel.h"
namespace BattleShip
{
    shared_ptr<IPlayer> GameModel::getUser()
    {
        return You_;
    }
    shared_ptr<IPlayer> GameModel::getComputer()
    {
        return Computer_;
    }
    const shared_ptr<IPlayer> GameModel::getUser() const
    {
        return You_;
    }
    const shared_ptr<IPlayer> GameModel::getComputer() const
    {
        return Computer_;
    }
    GameModel::GameModel(shared_ptr<IPlayer> you, shared_ptr<IPlayer> computer)
        : You_(you), Computer_(computer)
    {

    }
}




#include "GameModel.h"

IPlayer& GameModel::getUser()
{
    return You_;
}
IPlayer& GameModel::getComputer()
{
    return Computer_;
}
const IPlayer & GameModel::getUser() const
{
    return You_;
}
const IPlayer & GameModel::getComputer() const
{
    return Computer_;
}
GameModel::GameModel(IPlayer& you, IPlayer& computer)
    : You_(you), Computer_(computer)
{

}





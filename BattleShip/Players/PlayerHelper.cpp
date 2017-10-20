#include "PlayerHelper.h"

#include<memory>

#include"..\Command\UnionCommand.h"

using namespace std;

PlayerHelper::PlayerHelper(IField& field, shared_ptr<Ship> ship)
    : Field_(field), Ship_(ship)
{
    Ship_->destroy();

    commands_.push_back(shared_ptr<Command>(new FillLeftTopConnorCellCommand(*this)));
    commands_.push_back(shared_ptr<Command>(new FillLeftBottomConnorCellCommand(*this)));
    commands_.push_back(shared_ptr<Command>(new FillRightTopConnorCellCommand(*this)));
    commands_.push_back(shared_ptr<Command>(new FillRightBottomConnorCellCommand(*this)));

    commands_.push_back(shared_ptr<Command>(new FillLeftSideCellCommand(*this)));
    commands_.push_back(shared_ptr<Command>(new FillRightSideCellCommand(*this)));
    commands_.push_back(shared_ptr<Command>(new FillBottomSideCellCommand(*this)));
    commands_.push_back(shared_ptr<Command>(new FillTopSideCellCommand(*this)));

    commands_.push_back(shared_ptr<Command>(new FillStandartCellCommand(*this)));

    for (shared_ptr<Command> item : commands_)
    {
        if (item->tryExecute())
        {
            item->execute();
            break;
        }
    }
}




shared_ptr<Ship> PlayerHelper::getShip()
{
    return Ship_;
}

shared_ptr<Ship> PlayerHelper::getShip() const
{
    return Ship_;
}

IField & PlayerHelper::getPlayer()
{
    return Field_;
}

IField & PlayerHelper::getPlayer() const
{
    return Field_;
}

PlayerHelper::~PlayerHelper()
{
}

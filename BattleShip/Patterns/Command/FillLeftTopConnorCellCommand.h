#ifndef FillLeftTopConnorCellCommand_H
#define FillLeftTopConnorCellCommand_H

#include "Command.h"

class FillLeftTopConnorCellCommand : public Command
{
public:
    FillLeftTopConnorCellCommand(PlayerHelper& p) : PlayerHelper_(p) {}
    void execute() override
    {
        mutex_.lock();
        try {
            for (int i = 0; i < PlayerHelper_.getShip()->getShipSize() + 1; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    if (PlayerHelper_.getShip()->getX().get()[0] -
                        PlayerHelper_.getShip()->getX()
                        .get()[PlayerHelper_.getShip()->getShipSize() - 1] != 0)
                    {
                        PlayerHelper_.getPlayer().setField(i, j);
                    }
                    else
                    {
                        PlayerHelper_.getPlayer().setField(j, i);
                    }
                }
            }

        }
        catch (exception)
        {
            throw ExecuteCommandException();
            mutex_.unlock();
        }
        mutex_.unlock();
    }
    bool tryExecute() override
    {
        return PlayerHelper_.getShip()->getX().get()[0] == 0 && PlayerHelper_.getShip()->getY().get()[0] == 0;
    }
private:
    PlayerHelper& PlayerHelper_;
};
#endif
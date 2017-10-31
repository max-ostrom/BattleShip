#ifndef FillTopSideCellCommand_H
#define FillTopSideCellCommand_H

#include "Command.h"

class FillTopSideCellCommand : public Command
{
public:
    FillTopSideCellCommand(PlayerHelper& p) : PlayerHelper_(p) {}
    void execute() override
    {
        mutex_.lock();
        try {
            if (PlayerHelper_.getShip()->getX().get()[0] -
                PlayerHelper_.getShip()->getX()
                .get()[PlayerHelper_.getShip()->getShipSize() - 1] != 0)
            {
                for (int i = PlayerHelper_.getShip()->getX().get()[0];
                    i < PlayerHelper_.getShip()->getX().get()[0]
                    + PlayerHelper_.getShip()->getShipSize() + 1; i++)
                {
                    for (int j = PlayerHelper_.getShip()->getY().get()[0] - 1;
                        j < PlayerHelper_.getShip()->getY().get()[0] + 2; j++)
                    {

                        PlayerHelper_.getPlayer().setField(i, j);


                    }
                }
            }
            else
            {
                for (int i = PlayerHelper_.getShip()->getX().get()[0];
                    i < PlayerHelper_.getShip()->getX().get()[0] + 2; i++)
                {
                    for (int j = PlayerHelper_.getShip()->getY().get()[0] - 1;
                        j < PlayerHelper_.getShip()->getY().get()[0]
                        + PlayerHelper_.getShip()->getShipSize() + 1;
                        j++)
                    {
                        PlayerHelper_.getPlayer().setField(i, j);
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
        return PlayerHelper_.getShip()->getX().get()[0] == 0;
    }
private:
    PlayerHelper& PlayerHelper_;
};
#endif
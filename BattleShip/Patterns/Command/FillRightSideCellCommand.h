#ifndef FillRightSideCellCommand_H
#define FillRightSideCellCommand_H

#include "Command.h"

class FillRightSideCellCommand : public Command
{
public:
    FillRightSideCellCommand(PlayerHelper& p) : PlayerHelper_(p) {}
    void execute() override
    {
        try {
            if (PlayerHelper_.getShip()->getX().get()[0] -
                PlayerHelper_.getShip()->getX()
                .get()[PlayerHelper_.getShip()->getShipSize() - 1] != 0)
            {
                for (int i = PlayerHelper_.getShip()->getX().get()[0] - 1;
                    i < PlayerHelper_.getShip()->getX().get()[0]
                    + PlayerHelper_.getShip()->getShipSize() + 1;
                    i++)
                {
                    for (int j = PlayerHelper_.getShip()->getY().get()[0] - 1;
                        j < PlayerHelper_.getShip()->getY().get()[0] + 1; j++)
                    {

                        PlayerHelper_.getPlayer().setField(i, j);

                    }
                }
            }
            else
            {
                for (int i = PlayerHelper_.getShip()->getX().get()[0] - 1;
                    i < PlayerHelper_.getShip()->getX().get()[0] + 2; i++)
                {
                    for (int j = PlayerHelper_.getShip()->getY().get()[0] - 1;
                        j < PlayerHelper_.getShip()->getY().get()[0]
                        + PlayerHelper_.getShip()->getShipSize(); j++)
                    {

                        PlayerHelper_.getPlayer().setField(i, j);

                    }
                }
            }
        }
        catch (exception)
        {
            throw ExecuteCommandException();
        }
    }
    bool tryExecute() override {
        return PlayerHelper_.getShip()->getY().get()[PlayerHelper_.getShip()->getShipSize() - 1]
            == STANDART_FIELD - 1;
    }
private:
    PlayerHelper& PlayerHelper_;
};
#endif
#ifndef FillRightBottomConnorCellCommand_H
#define FillRightBottomConnorCellCommand_H

#include "../PlayerHelper.h"
#include "Command.h"

class FillRightBottomConnorCellCommand : public Command
{
public:
	FillRightBottomConnorCellCommand(PlayerHelper& p) : PlayerHelper_(p) {}
	void execute() override
	{
		for (int i = PlayerHelper_.getShip()->getX().get()[0] - 1;
			i < PlayerHelper_.getShip()->getX().get()[0] + PlayerHelper_.getShip()->getShipSize() + 1; i++)
		{
			for (int j = PlayerHelper_.getShip()->getY().get()[0] - 1;
				j < PlayerHelper_.getShip()->getY().get()[0] + 1; j++)
			{
				if (PlayerHelper_.getShip()->getX().get()[0] -
					PlayerHelper_.getShip()->getX().get()[PlayerHelper_.getShip()->getShipSize() - 1] != 0)
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
private:
	PlayerHelper& PlayerHelper_;
};
#endif
#pragma once
#include "../PlayerHelper.h"
#include "Command.h"
class FillRightTopConnorCellCommand : public Command
{
public:
	FillRightTopConnorCellCommand(PlayerHelper& p) : PlayerHelper_(p) {}
	void execute() override
	{
		if (PlayerHelper_.getShip()->getX().get()[0] - PlayerHelper_.getShip()->getX().get()[PlayerHelper_.getShip()->getShipSize() - 1] != 0)
		{
			for (int i = PlayerHelper_.getShip()->getX().get()[0]; i < PlayerHelper_.getShip()->getX().get()[0] + PlayerHelper_.getShip()->getShipSize() + 1; i++)
			{
				for (int j = PlayerHelper_.getShip()->getY().get()[0] - 1; j < PlayerHelper_.getShip()->getY().get()[0] + 1; j++)
				{

					PlayerHelper_.getPlayer().setField(i, j);

				}
			}
		}
		else
		{
			for (int i = PlayerHelper_.getShip()->getX().get()[0] - 1; i < PlayerHelper_.getShip()->getX().get()[0]; i++)
			{
				for (int j = PlayerHelper_.getShip()->getY().get()[0]; j < PlayerHelper_.getShip()->getY().get()[0] + PlayerHelper_.getShip()->getShipSize() + 1; j++)
				{

					PlayerHelper_.getPlayer().setField(i, j);

				}
			}
		}
	}
private:
	PlayerHelper& PlayerHelper_;
};
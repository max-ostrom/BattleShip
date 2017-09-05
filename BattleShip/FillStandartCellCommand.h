#pragma once

#include "Command\Command.h"
#include "Players\PlayerHelper.h"

class FillStandartCellCommand :
	public Command
{
public:

	FillStandartCellCommand(PlayerHelper& p) : PlayerHelper_(p) {}
	void execute() override 
	{
		if (PlayerHelper_.getShip()->getX().get()[0] - PlayerHelper_.getShip()->getX().get()[1] != 0)
		{
			for (int i = PlayerHelper_.getShip()->getX().get()[0] - 1;
				i < PlayerHelper_.getShip()->getX().get()[0] + PlayerHelper_.getShip()->getShipSize() + 1;
				i++)
			{
				for (int j = PlayerHelper_.getShip()->getY().get()[0] - 1; j < PlayerHelper_.getShip()->getY().get()[0] + 2; j++)
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
					j < PlayerHelper_.getShip()->getY().get()[0] + PlayerHelper_.getShip()->getShipSize() + 1; j++)
				{
					PlayerHelper_.getPlayer().setField(i, j);
				}
			}
		}
	}
private:
	PlayerHelper& PlayerHelper_;
};


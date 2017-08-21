#include "PlayerHelper.h"

#include<memory>

#include"..\Command\UnionCommand.h"
using namespace std;
PlayerHelper::PlayerHelper(IField& field, shared_ptr<Ship> ship) : Field_(field), Ship_(ship)
{

	Ship_->destroy();
	//lefttopconnor
	if (Ship_->getX().get()[0] == 0 && Ship_->getY().get()[0] == 0)
	{
		fillCells(FillLeftTopConnorCellCommand(*this));
	}

	//leftbottomconnor
	else if (Ship_->getX().get()[Ship_->getShipSize() - 1] == FIELD_SIZE - 1 && Ship_->getY().get()[0] == 0)
	{
		fillCells(FillLeftBottomConnorCellCommand(*this));
	}

	//righttopconnor
	else if (Ship_->getX().get()[0] == 0 && Ship_->getY().get()[Ship_->getShipSize() - 1] == FIELD_SIZE - 1)
	{
		fillCells(FillRightTopConnorCellCommand(*this));
	}

	//rightbottomconnor
	else if (Ship_->getX().get()[Ship_->getShipSize() - 1] == FIELD_SIZE - 1 && Ship_->getY().get()[Ship_->getShipSize() - 1] == FIELD_SIZE - 1)
	{
		fillCells(FillRightBottomConnorCellCommand(*this));
	}

	//leftside
	else if (Ship_->getY().get()[0] == 0)
	{
		fillCells(FillLeftSideCellCommand(*this));
	}

	//rightside
	else if (Ship_->getY().get()[Ship_->getShipSize() - 1] == FIELD_SIZE - 1)
	{
		fillCells(FillRightSideCellCommand(*this));
	}

	//bottomside
	else if (Ship_->getX().get()[Ship_->getShipSize() - 1] == FIELD_SIZE - 1)
	{
		fillCells(FillBottomSideCellCommand(*this));
	}

	//topside
	else if (Ship_->getX().get()[0] == 0)
	{
		fillCells(FillTopSideCellCommand(*this));
	}


	else
	{
		if (Ship_->getX().get()[0] - Ship_->getX().get()[1] != 0)
		{
			for (int i = Ship_->getX().get()[0] - 1; i < Ship_->getX().get()[0] + Ship_->getShipSize() + 1; i++)
			{
				for (int j = Ship_->getY().get()[0] - 1; j < Ship_->getY().get()[0] + 2; j++)
				{
					Field_.setField(i, j);
				}
			}
		}
		else
		{
			for (int i = Ship_->getX().get()[0] - 1; i < Ship_->getX().get()[0] + 2; i++)
			{
				for (int j = Ship_->getY().get()[0] - 1; j < Ship_->getY().get()[0] + Ship_->getShipSize() + 1; j++)
				{
					Field_.setField(i, j);
				}
			}
		}
	}

}


void PlayerHelper::fillCells(Command & command)
{
	command.execute();
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

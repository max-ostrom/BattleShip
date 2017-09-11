#include "PlayerHelper.h"

#include<memory>

#include"..\Command\UnionCommand.h"

using namespace std;

PlayerHelper::PlayerHelper(IField& field, shared_ptr<Ship> ship) 
	: Field_(field), Ship_(ship)
{

	Ship_->destroy();
	//lefttopconnor
	if (Ship_->getX().get()[0] == 0 && Ship_->getY().get()[0] == 0)
	{
		fillCells(FillLeftTopConnorCellCommand(*this));
	}

	//leftbottomconnor
	else if (Ship_->getX().get()[Ship_->getShipSize() - 1] 
		== STANDART_FIELD - 1 && Ship_->getY().get()[0] == 0)
	{
		fillCells(FillLeftBottomConnorCellCommand(*this));
	}

	//righttopconnor
	else if (Ship_->getX().get()[0] == 0 && Ship_->getY().get()[Ship_->getShipSize() - 1]
		== STANDART_FIELD - 1)
	{
		fillCells(FillRightTopConnorCellCommand(*this));
	}

	//rightbottomconnor
	else if (Ship_->getX().get()[Ship_->getShipSize() - 1] == STANDART_FIELD - 1
		&& Ship_->getY().get()[Ship_->getShipSize() - 1] == STANDART_FIELD - 1)
	{
		fillCells(FillRightBottomConnorCellCommand(*this));
	}

	//leftside
	else if (Ship_->getY().get()[0] == 0)
	{
		fillCells(FillLeftSideCellCommand(*this));
	}

	//rightside
	else if (Ship_->getY().get()[Ship_->getShipSize() - 1]
		== STANDART_FIELD - 1)
	{
		fillCells(FillRightSideCellCommand(*this));
	}

	//bottomside
	else if (Ship_->getX().get()[Ship_->getShipSize() - 1] 
		== STANDART_FIELD - 1)
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
		fillCells(FillStandartCellCommand(*this));
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

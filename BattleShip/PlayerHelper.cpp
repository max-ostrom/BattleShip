#include "PlayerHelper.h"

#include<memory>

using namespace std;
PlayerHelper::PlayerHelper(IPlayer& p, shared_ptr<Ship> ship) : Player_(p), item(ship)
{

	item->destroy();
	//lefttopconnor
	if (item->getX().get()[0] == 0 && item->getY().get()[0] == 0)
	{
		fillLeftTopConnorCell(item);
	}

	//leftbottomconnor
	else if (item->getX().get()[item->getShipSize() - 1] == FIELD_SIZE - 1 && item->getY().get()[0] == 0)
	{
		fillLeftBottomConnorCell(item);
	}

	//righttopconnor
	else if (item->getX().get()[0] == 0 && item->getY().get()[item->getShipSize() - 1] == FIELD_SIZE - 1)
	{
		fillRightTopConnorCell(item);
	}

	//rightbottomconnor
	else if (item->getX().get()[item->getShipSize() - 1] == FIELD_SIZE - 1 && item->getY().get()[item->getShipSize() - 1] == FIELD_SIZE - 1)
	{
		fillRightBottomConnorCell(item);
	}

	//leftside
	else if (item->getY().get()[0] == 0)
	{
		fillLeftSideCell(item);
	}

	//rightside
	else if (item->getY().get()[item->getShipSize() - 1] == FIELD_SIZE - 1)
	{
		fillRightSideCell(item);
	}

	//bottomside
	else if (item->getX().get()[item->getShipSize() - 1] == FIELD_SIZE - 1)
	{
		fillBottomSideCell(item);
	}

	//topside
	else if (item->getX().get()[0] == 0)
	{
		fillTopSideCell(item);
	}


	else
	{
		if (item->getX().get()[0] - item->getX().get()[1] != 0)
		{
			for (int i = item->getX().get()[0] - 1; i < item->getX().get()[0] + item->getShipSize() + 1; i++)
			{
				for (int j = item->getY().get()[0] - 1; j < item->getY().get()[0] + 2; j++)
				{
					Player_.setField(i, j);
				}
			}
		}
		else
		{
			for (int i = item->getX().get()[0] - 1; i < item->getX().get()[0] + 2; i++)
			{
				for (int j = item->getY().get()[0] - 1; j < item->getY().get()[0] + item->getShipSize() + 1; j++)
				{
					Player_.setField(i, j);
				}
			}
		}
	}

}


void PlayerHelper::fillLeftTopConnorCell()
{
	for (int i = 0; i < item->getShipSize() + 1; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (item->getX().get()[0] - item->getX().get()[item->getShipSize() - 1] != 0)
			{
				Player_.setField(i, j);
			}
			else
			{
				Player_.setField(j, i);
			}
		}
	}
}

void PlayerHelper::fillLeftBottomConnorCell()
{
	if (item->getX().get()[0] - item->getX().get()[item->getShipSize() - 1] != 0)
	{
		for (int i = item->getX().get()[0] - 1; i < item->getX().get()[0] + item->getShipSize() + 1; i++)
		{
			for (int j = item->getY().get()[0]; j < item->getY().get()[0] + 2; j++)
			{

				Player_.setField(i, j);

			}
		}
	}
	else
	{
		for (int i = item->getX().get()[0]; i < item->getX().get()[0] + 2; i++)
		{
			for (int j = item->getY().get()[0] - 1; j < item->getY().get()[0] + item->getShipSize(); j++)
			{

				Player_.setField(i, j);

			}
		}
	}
}

void PlayerHelper::fillRightTopConnorCell()
{
	if (item->getX().get()[0] - item->getX().get()[item->getShipSize() - 1] != 0)
	{
		for (int i = item->getX().get()[0]; i < item->getX().get()[0] + item->getShipSize() + 1; i++) 
		{
			for (int j = item->getY().get()[0] - 1; j < item->getY().get()[0] + 1; j++)
			{

				Player_.setField(i, j);

			}
		}
	}
	else
	{
		for (int i = item->getX().get()[0] - 1; i < item->getX().get()[0] ; i++)
		{
			for (int j = item->getY().get()[0]; j < item->getY().get()[0] + item->getShipSize() + 1; j++)
			{

				Player_.setField(i, j);

			}
		}
	}
}

void PlayerHelper::fillRightBottomConnorCell()
{
	for (int i = item->getX().get()[0] - 1; i < item->getX().get()[0] + item->getShipSize() + 1; i++)
	{
		for (int j = item->getY().get()[0] - 1; j < item->getY().get()[0] + 1; j++)
		{
			if (item->getX().get()[0] - item->getX().get()[item->getShipSize() - 1] != 0)
			{
				Player_.setField(i, j);
			}
			else
			{
				Player_.setField(j, i);
			}
		}
	}

}

void PlayerHelper::fillLeftSideCell()
{
	if (item->getX().get()[0] - item->getX().get()[item->getShipSize() - 1] != 0)
	{
		for (int i = item->getX().get()[0] - 1; i < item->getX().get()[0] + item->getShipSize() + 1; i++)
		{
			for (int j = item->getY().get()[0]; j < item->getY().get()[0] + 2; j++)
			{

				Player_.setField(i, j);

			}
		}
	}
	else
	{
		for (int i = item->getX().get()[0] - 1; i < item->getX().get()[0] + 2; i++)
		{
			for (int j = item->getY().get()[0]; j < item->getY().get()[0] + item->getShipSize() + 1; j++)
			{

				Player_.setField(i, j);

			}
		}
	}

}

void PlayerHelper::fillBottomSideCell()
{
	if (item->getX().get()[0] - item->getX().get()[1] != 0)
	{
		for (int i = item->getX().get()[0] - 1; i < item->getX().get()[0] + item->getShipSize() + 1; i++)
		{
			for (int j = item->getY().get()[0] - 1; j < item->getY().get()[0] + 2; j++)
			{

				Player_.setField(i, j);

			}
		}
	}
	else
	{
		for (int i = item->getX().get()[0] - 1; i < item->getX().get()[0] + 2; i++)
		{
			for (int j = item->getY().get()[0] - 1; j < item->getY().get()[0] + item->getShipSize() + 1; j++)
			{

				Player_.setField(i, j);

			}
		}
	}
}

void PlayerHelper::fillRightSideCell()
{
	if (item->getX().get()[0] - item->getX().get()[item->getShipSize() - 1] != 0)
	{
		for (int i = item->getX().get()[0] - 1; i < item->getX().get()[0] + item->getShipSize() + 1; i++)
		{
			for (int j = item->getY().get()[0] - 1; j < item->getY().get()[0] + 1; j++)
			{

				Player_.setField(i, j);

			}
		}
	}
	else
	{
		for (int i = item->getX().get()[0] - 1; i < item->getX().get()[0] + 2; i++)
		{
			for (int j = item->getY().get()[0] - 1; j < item->getY().get()[0] + item->getShipSize(); j++)
			{

				Player_.setField(i, j);

			}
		}
	}
}

void PlayerHelper::fillTopSideCell()
{
	if (item->getX().get()[0] - item->getX().get()[item->getShipSize() - 1] != 0)
	{
		for (int i = item->getX().get()[0]; i < item->getX().get()[0] + item->getShipSize() + 1; i++)
		{
			for (int j = item->getY().get()[0] - 1; j < item->getY().get()[0] + 2; j++)
			{

				Player_.setField(i, j);


			}
		}
	}
	else
	{
		for (int i = item->getX().get()[0]; i < item->getX().get()[0] + 2; i++)
		{
			for (int j = item->getY().get()[0] - 1; j < item->getY().get()[0] + item->getShipSize() + 1; j++)
			{
				Player_.setField(i, j);
			}
		}
	}
}

shared_ptr<Ship> PlayerHelper::getShip()
{
	return item;
}

shared_ptr<Ship> PlayerHelper::getShip() const
{
	return item;
}

PlayerHelper::~PlayerHelper()
{
}

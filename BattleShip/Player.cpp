#include "Player.h"
#include "UnionFactory.h"

using namespace std;
bool Player::isEndOfGame() const
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (getField(i, j) == 'X')
				return false;

		}
	}
	return true;
}

bool Player::isShipAlive(Ship* item) 
{
	bool flag = true;


	for (int i = 0; i < item->getShipSize(); i++)
	{
		if ( getField(item->getX()[i], item->getY()[i]) == '#' && flag)
		{
			flag = true;
		}
		else
		{
			flag = false;
		}
	}


	if (flag)
	{
		setNearCell(item);
		return false;
	}
	return true;
}

void Player::setNearCell(Ship* item)
{
	item->destroy();

	if (item->getX()[0] == 0 && item->getY()[0] == 0)
	{
		for (int i = 0; i < item->getShipSize() + 1; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (item->getX()[0] - item->getX()[item->getShipSize() - 1] != 0)
				{
					setField(i, j);
				}
				else
				{
					setField(j, i);
				}
			}
		}
	}


	else if (item->getX()[item->getShipSize() - 1] == 9 && item->getY()[0] == 0)
	{
		if (item->getX()[0] - item->getX()[item->getShipSize() - 1] != 0)
		{
			for (int i = item->getX()[0] - 1; i < item->getX()[0] + item->getShipSize() + 1; i++)
			{
				for (int j = item->getY()[0]; j < item->getY()[0] + 2; j++)
				{

					setField(i, j);

				}
			}
		}
		else
		{
			for (int i = item->getX()[0]; i < item->getX()[0] + 2; i++)
			{
				for (int j = item->getY()[0] - 1; j < item->getY()[0] + item->getShipSize(); j++)
				{

					setField(i, j);

				}
			}
		}
	}


	else if (item->getX()[0] == 0 && item->getY()[item->getShipSize() - 1] == 9)
	{
		if (item->getX()[0] - item->getX()[item->getShipSize() - 1] != 0)
		{
			for (int i = item->getX()[0]; i < item->getX()[0] + item->getShipSize() + 1; i++) // возможно ошибка если что убрать +1
			{
				for (int j = item->getY()[0] - 1; j < item->getY()[0] + 1; j++)
				{

					setField(i, j);

				}
			}
		}
		else
		{
			for (int i = item->getX()[0] - 1; i < item->getX()[0] + 1; i++)
			{
				for (int j = item->getY()[0]; j < item->getY()[0] + item->getShipSize() + 1; j++)
				{

					setField(i, j);

				}
			}
		}
	}


	else if (item->getX()[item->getShipSize() - 1] == 9 && item->getY()[item->getShipSize() - 1] == 9)
	{
		for (int i = item->getX()[0] - 1; i < item->getX()[0] + item->getShipSize() + 1; i++)
		{
			for (int j = item->getY()[0] - 1; j < item->getY()[0] + 1; j++)
			{
				if (item->getX()[0] - item->getX()[item->getShipSize() - 1] != 0)
				{
					setField(i, j);
				}
				else
				{
					setField(j, i);
				}
			}
		}
	}


	else if (item->getY()[0] == 0)
	{
		if (item->getX()[0] - item->getX()[item->getShipSize() - 1] != 0)
		{
			for (int i = item->getX()[0] - 1; i < item->getX()[0] + item->getShipSize() + 1; i++)
			{
				for (int j = item->getY()[0]; j < item->getY()[0] + 2; j++)
				{

					setField(i, j);

				}
			}
		}
		else
		{
			for (int i = item->getX()[0] - 1; i < item->getX()[0] + 2; i++)
			{
				for (int j = item->getY()[0]; j < item->getY()[0] + item->getShipSize() + 1; j++)
				{

					setField(i, j);

				}
			}
		}


	}


	else if (item->getY()[item->getShipSize() - 1] == 9)
	{
		if (item->getX()[0] - item->getX()[item->getShipSize() - 1] != 0)
		{
			for (int i = item->getX()[0] - 1; i < item->getX()[0] + item->getShipSize() + 1; i++)
			{
				for (int j = item->getY()[0] - 1; j < item->getY()[0] + 1; j++)
				{

					setField(i, j);

				}
			}
		}
		else
		{
			for (int i = item->getX()[0] - 1; i < item->getX()[0] + 2; i++)
			{
				for (int j = item->getY()[0] - 1; j < item->getY()[0] + item->getShipSize(); j++)
				{

					setField(i, j);

				}
			}
		}
	}


	else if (item->getX()[item->getShipSize() - 1] == 9)
	{
		if (item->getX()[0] - item->getX()[1] != 0)
		{
			for (int i = item->getX()[0] - 1; i < item->getX()[0] + item->getShipSize() + 1; i++)
			{
				for (int j = item->getY()[0] - 1; j < item->getY()[0] + 2; j++)
				{

					setField(i, j);

				}
			}
		}
		else
		{
			for (int i = item->getX()[0] - 1; i < item->getX()[0] + 2; i++)
			{
				for (int j = item->getY()[0] - 1; j < item->getY()[0] + item->getShipSize() + 1; j++)
				{

					setField(i, j);

				}
			}
		}
	}


	else if (item->getX()[0] == 0)
	{
		if (item->getX()[0] - item->getX()[item->getShipSize() - 1] != 0)
		{
			for (int i = item->getX()[0]; i < item->getX()[0] + item->getShipSize() + 1; i++)
			{
				for (int j = item->getY()[0] - 1; j < item->getY()[0] + 2; j++)
				{

					setField(i, j);


				}
			}
		}
		else
		{
			for (int i = item->getX()[0]; i < item->getX()[0] + 2; i++)
			{
				for (int j = item->getY()[0] - 1; j < item->getY()[0] + item->getShipSize() + 1; j++)
				{

					setField(i, j);


				}
			}
		}
	}


	else
	{
		if (item->getX()[0] - item->getX()[1] != 0)
		{
			for (int i = item->getX()[0] - 1; i < item->getX()[0] + item->getShipSize() + 1; i++)
			{
				for (int j = item->getY()[0] - 1; j < item->getY()[0] + 2; j++)
				{
					setField(i, j);
				}
			}
		}
		else
		{
			for (int i = item->getX()[0] - 1; i < item->getX()[0] + 2; i++)
			{
				for (int j = item->getY()[0] - 1; j < item->getY()[0] + item->getShipSize() + 1; j++)
				{
					setField(i, j);
				}
			}
		}
	}
}

char Player::getField(const int& i, const int& j) const
{
	if (i >= 0 && i < 11 && j >= 0 && j < 11)
		return yourField_[i][j];

	else
		return NULL;
}

char Player::getEnemyField(const int& i, const int& j) const
{
	if (i >= 0 && i < 11 && j >= 0 && j < 11)
		return enemyField_[i][j];

	else
		return NULL;
}

void Player::setField(const int& i, const int& j)
{
	if (yourField_[i][j] == ' ' || yourField_[i][j] == '*')
		yourField_[i][j] = '*';

	else
		yourField_[i][j] = '#';
}

void Player::setEnemyField(const int& i, const int& j,const Player& p)
{
	if (p.yourField_[i][j] == ' ' || p.yourField_[i][j] == '*')
		enemyField_[i][j] = '*';

	else
		enemyField_[i][j] = '#';
}

Player::Player() 
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			enemyField_[i][j] = ' ';
			yourField_[i][j] = ' ';
		}
	}

	IFactory* factory_fourShip = new FactoryFourShip();
	YourShips.push_back(factory_fourShip->createShip(yourField_));

	IFactory* factory_threeShip = new FactoryThreeShip();
	for (int i = 0; i < 2; i++)
	{
		YourShips.push_back(factory_threeShip->createShip(yourField_));
	}

	IFactory* factory_doubleShip = new FactoryDoubleShip();
	for (int i = 0; i < 3; i++)
	{
		YourShips.push_back(factory_doubleShip->createShip(yourField_));
	}

	IFactory* factory_singleShip = new FactorySingleShip();
	for (int i = 0; i < 4; i++)
	{
		YourShips.push_back(factory_singleShip->createShip(yourField_));
	}


	delete factory_doubleShip;
	delete factory_singleShip;
	delete factory_fourShip;
	delete factory_threeShip;
}

Player::~Player()
{
	
}

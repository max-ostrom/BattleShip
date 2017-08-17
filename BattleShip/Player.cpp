#include "Player.h"
#include "UnionFactory.h"

using namespace std;
	


bool Player::isEndOfGame() const
{
	for (int i = 0; i < FIELDSIZE; i++)
	{
		for (int j = 0; j < FIELDSIZE; j++)
		{
			if (getField(i, j) == 'X')
				return false;

		}
	}
	return true;
}

bool Player::isShipAlive(Ship* item) 
{
	if (item == nullptr)
	{
		throw exception();
	}
	bool flag = true;


	for (int i = 0; i < item->getShipSize(); i++)
	{
		if ( getField(item->getX().get()[i], item->getY().get()[i]) == '#' && flag)
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
	//lefttopconnor
	if (item->getX().get()[0] == 0 && item->getY().get()[0] == 0)
	{
		fillLeftTopConnorCell(item);
	}

	//leftbottomconnor
	else if (item->getX().get()[item->getShipSize() - 1] == FIELDSIZE-1 && item->getY().get()[0] == 0)
	{
		fillLeftBottomConnorCell(item);
	}

	//righttopconnor
	else if (item->getX().get()[0] == 0 && item->getY().get()[item->getShipSize() - 1] == FIELDSIZE-1)
	{
		fillRightTopConnorCell(item);
	}

	//rightbottomconnor
	else if (item->getX().get()[item->getShipSize() - 1] == FIELDSIZE-1 && item->getY().get()[item->getShipSize() - 1] == FIELDSIZE-1)
	{
		fillRightBottomConnorCell(item);
	}

	//leftside
	else if (item->getY().get()[0] == 0)
	{
		fillLeftSideCell(item);
	}

	//rightside
	else if (item->getY().get()[item->getShipSize() - 1] == FIELDSIZE-1)
	{
		fillRightSideCell(item);
	}

	//bottomside
	else if (item->getX().get()[item->getShipSize() - 1] == FIELDSIZE-1)
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
					setField(i, j);
				}
			}
		}
		else
		{
			for (int i = item->getX().get()[0] - 1; i < item->getX().get()[0] + 2; i++)
			{
				for (int j = item->getY().get()[0] - 1; j < item->getY().get()[0] + item->getShipSize() + 1; j++)
				{
					setField(i, j);
				}
			}
		}
	}
	notifyUpdate();
}

char Player::getField(const int& i, const int& j) const
{
	if (i >= 0 && i < FIELDSIZE && j >= 0 && j < FIELDSIZE)
		return yourField_[i][j];

	else
		return NULL;
}

char Player::getEnemyField(const int& i, const int& j) const
{
	if (i >= 0 && i < FIELDSIZE+1 && j >= 0 && j < FIELDSIZE+1)
		return enemyField_[i][j];

	else
		return NULL;
}

void Player::fillLeftTopConnorCell(Ship * item)
{
	for (int i = 0; i < item->getShipSize() + 1; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (item->getX().get()[0] - item->getX().get()[item->getShipSize() - 1] != 0)
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

void Player::fillLeftBottomConnorCell(Ship * item)
{
	if (item->getX().get()[0] - item->getX().get()[item->getShipSize() - 1] != 0)
	{
		for (int i = item->getX().get()[0] - 1; i < item->getX().get()[0] + item->getShipSize() + 1; i++)
		{
			for (int j = item->getY().get()[0]; j < item->getY().get()[0] + 2; j++)
			{

				setField(i, j);

			}
		}
	}
	else
	{
		for (int i = item->getX().get()[0]; i < item->getX().get()[0] + 2; i++)
		{
			for (int j = item->getY().get()[0] - 1; j < item->getY().get()[0] + item->getShipSize(); j++)
			{

				setField(i, j);

			}
		}
	}
}

void Player::fillRightTopConnorCell(Ship * item)
{
	if (item->getX().get()[0] - item->getX().get()[item->getShipSize() - 1] != 0)
	{
		for (int i = item->getX().get()[0]; i < item->getX().get()[0] + item->getShipSize() + 1; i++) // возможно ошибка если что убрать +1
		{
			for (int j = item->getY().get()[0] - 1; j < item->getY().get()[0] + 1; j++)
			{

				setField(i, j);

			}
		}
	}
	else
	{
		for (int i = item->getX().get()[0] - 1; i < item->getX().get()[0] + 1; i++)
		{
			for (int j = item->getY().get()[0]; j < item->getY().get()[0] + item->getShipSize() + 1; j++)
			{

				setField(i, j);

			}
		}
	}
}

void Player::fillRightBottomConnorCell(Ship * item)
{
	for (int i = item->getX().get()[0] - 1; i < item->getX().get()[0] + item->getShipSize() + 1; i++)
	{
		for (int j = item->getY().get()[0] - 1; j < item->getY().get()[0] + 1; j++)
		{
			if (item->getX().get()[0] - item->getX().get()[item->getShipSize() - 1] != 0)
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

void Player::fillLeftSideCell(Ship * item)
{
	if (item->getX().get()[0] - item->getX().get()[item->getShipSize() - 1] != 0)
	{
		for (int i = item->getX().get()[0] - 1; i < item->getX().get()[0] + item->getShipSize() + 1; i++)
		{
			for (int j = item->getY().get()[0]; j < item->getY().get()[0] + 2; j++)
			{

				setField(i, j);

			}
		}
	}
	else
	{
		for (int i = item->getX().get()[0] - 1; i < item->getX().get()[0] + 2; i++)
		{
			for (int j = item->getY().get()[0]; j < item->getY().get()[0] + item->getShipSize() + 1; j++)
			{

				setField(i, j);

			}
		}
	}

}

void Player::fillBottomSideCell(Ship * item)
{
	if (item->getX().get()[0] - item->getX().get()[1] != 0)
	{
		for (int i = item->getX().get()[0] - 1; i < item->getX().get()[0] + item->getShipSize() + 1; i++)
		{
			for (int j = item->getY().get()[0] - 1; j < item->getY().get()[0] + 2; j++)
			{

				setField(i, j);

			}
		}
	}
	else
	{
		for (int i = item->getX().get()[0] - 1; i < item->getX().get()[0] + 2; i++)
		{
			for (int j = item->getY().get()[0] - 1; j < item->getY().get()[0] + item->getShipSize() + 1; j++)
			{

				setField(i, j);

			}
		}
	}
}

void Player::fillRightSideCell(Ship * item)
{
	if (item->getX().get()[0] - item->getX().get()[item->getShipSize() - 1] != 0)
	{
		for (int i = item->getX().get()[0] - 1; i < item->getX().get()[0] + item->getShipSize() + 1; i++)
		{
			for (int j = item->getY().get()[0] - 1; j < item->getY().get()[0] + 1; j++)
			{

				setField(i, j);

			}
		}
	}
	else
	{
		for (int i = item->getX().get()[0] - 1; i < item->getX().get()[0] + 2; i++)
		{
			for (int j = item->getY().get()[0] - 1; j < item->getY().get()[0] + item->getShipSize(); j++)
			{

				setField(i, j);

			}
		}
	}
}

void Player::fillTopSideCell(Ship * item)
{
	if (item->getX().get()[0] - item->getX().get()[item->getShipSize() - 1] != 0)
	{
		for (int i = item->getX().get()[0]; i < item->getX().get()[0] + item->getShipSize() + 1; i++)
		{
			for (int j = item->getY().get()[0] - 1; j < item->getY().get()[0] + 2; j++)
			{

				setField(i, j);


			}
		}
	}
	else
	{
		for (int i = item->getX().get()[0]; i < item->getX().get()[0] + 2; i++)
		{
			for (int j = item->getY().get()[0] - 1; j < item->getY().get()[0] + item->getShipSize() + 1; j++)
			{

				setField(i, j);


			}
		}
	}
}





void Player::setField(const int& i, const int& j)
{
	
	if (yourField_[i][j] == ' ' || yourField_[i][j] == '*')
	{
		yourField_[i][j] = '*';
	}
	else
	{
		yourField_[i][j] = '#';
	}
	notifyUpdate();
}

void Player::setEnemyField(const int& i, const int& j,const Player& p)
{
	
	if (p.yourField_[i][j] == ' ' || p.yourField_[i][j] == '*')
	{
		enemyField_[i][j] = '*';
	}
	else
	{
		enemyField_[i][j] = '#';
	}
	notifyUpdate();
}

Player::Player(IShipSettings& shipSettings) 
{

	cout << 2;
	for (int i = 0; i < FIELDSIZE; i++)
	{
		for (int j = 0; j < FIELDSIZE; j++)
		{
			enemyField_[i][j] = ' ';
			yourField_[i][j] = ' ';
		}
	}

	cout << 3;
	try {
		addShip(new FactoryFourShip());

		cout << 4;
		for (int i = 0; i < shipSettings.getThreeDeckShipCounter(); i++)
		{
			addShip(new FactoryThreeShip());
		}
		cout << 5;
		for (int i = 0; i < shipSettings.getDoubleDeckShipCounter(); i++)
		{
			addShip(new FactoryDoubleShip());
		}

		cout << 6;
		for (int i = 0; i < shipSettings.getSingleDeckShipCounter(); i++)
		{
			addShip(new FactorySingleShip());
		}
		
	}
	catch (exception& ex)
	{
		cout <<ex.what() << endl;
	}

	cout << 7 << "all ok  ";
}
void Player::addShip(IFactory* factory)
{
	try {
		YourShips.push_back(factory->createShip(yourField_));
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}
Player::~Player()
{
	
}


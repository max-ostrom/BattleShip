#include "Player.h"
#include "UnionFactory.h"

using namespace std;
	


bool Player::isEndOfGame() const
{
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			if (getField(i, j) == 'X')
				return false;

		}
	}
	return true;
}

bool Player::isShipAlive(shared_ptr<Ship> item) 
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
		PlayerHelper(*this,item);
		return false;
	}
	return true;
}



char Player::getField(const int& i, const int& j) const
{
	if (i >= 0 && i < FIELD_SIZE && j >= 0 && j < FIELD_SIZE)
		return yourField_[i][j];

	else
		return NULL;
}

char Player::getEnemyField(const int& i, const int& j) const
{
	if (i >= 0 && i < FIELD_SIZE+1 && j >= 0 && j < FIELD_SIZE+1)
		return enemyField_[i][j];

	else
		return NULL;
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

void Player::setEnemyField(const int& i, const int& j,const IPlayer& p)
{
	
	if (p.getField(i, j) == ' ' || p.getField(i, j) == '*')
	{
		enemyField_[i][j] = '*';
	}
	else
	{
		enemyField_[i][j] = '#';
	}
	notifyUpdate();
}

std::vector<std::shared_ptr<Ship>>& Player::getShips()
{
	return YourShips_;
}

const std::vector<std::shared_ptr<Ship>>& Player::getShips() const
{
	return YourShips_;
}

Player::Player(IShipSettings& shipSettings)
{


	for (int i = 0; i < FIELD_SIZE; i++)
	{
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			enemyField_[i][j] = ' ';
			yourField_[i][j] = ' ';
		}
	}

	
	try {
		addShip(FactoryFourShip());

		
		for (int i = 0; i < shipSettings.getThreeDeckShipCounter(); i++)
		{
			addShip(FactoryThreeShip());
		}
		
		for (int i = 0; i < shipSettings.getDoubleDeckShipCounter(); i++)
		{
			addShip(FactoryDoubleShip());
		}

		
		for (int i = 0; i < shipSettings.getSingleDeckShipCounter(); i++)
		{
			addShip(FactorySingleShip());
		}
		
	}
	catch (exception& ex)
	{
		cout <<ex.what() << endl;
	}
}
void Player::addShip(IFactory& factory)
{
	YourShips_.push_back(factory.createShip(yourField_));
}
Player::~Player()
{
	
}


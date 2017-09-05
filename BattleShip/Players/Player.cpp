#include "Player.h"
#include "..\Resource\UnionFactory.h"

using namespace std;

bool Player::isEndOfGame() const
{
	for (int i = 0; i < STANDART_FIELD; i++)
	{
		for (int j = 0; j < STANDART_FIELD; j++)
		{
			if (getField(i, j) == 'X')
				return false;

		}
	}
	return true;
}

bool Player::isShipAlive(shared_ptr<Ship> Ship_) 
{
	if (Ship_ == nullptr)
	{
		throw exception();
	}
	bool flag = true;


	for (int i = 0; i < Ship_->getShipSize(); i++)
	{
		if ( getField(Ship_->getX().get()[i], Ship_->getY().get()[i]) == '#' && flag)
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
		PlayerHelper(*this,Ship_);
		return false;
	}
	return true;
}

char Player::getField(const int i, const int j) const
{
	if (i >= 0 && i < STANDART_FIELD && j >= 0 && j < STANDART_FIELD)
		return yourField_[i][j];

	else
		return NULL;
}

char Player::getEnemyField(const int i, const int j) const
{
	if (i >= 0 && i < STANDART_FIELD+1 && j >= 0 && j < STANDART_FIELD+1)
		return enemyField_[i][j];

	else
		return NULL;
}

void Player::setField(const int i, const int j)
{
	
	if (yourField_[i][j] == ' ' || yourField_[i][j] == '*')
	{
		yourField_[i][j] = '*';
	}
	else
	{
		yourField_[i][j] = '#';
	}
}

void Player::setEnemyField(const int i, const int j,const IField& p)
{
	
	if (p.getField(i, j) == ' ' || p.getField(i, j) == '*')
	{
		enemyField_[i][j] = '*';
	}
	else
	{
		enemyField_[i][j] = '#';
	}
}

std::vector<std::shared_ptr<Ship>>& Player::getShips()
{
	return YourShips_;
}

const std::vector<std::shared_ptr<Ship>>& Player::getShips() const
{
	return YourShips_;
}

Player::Player(list<shared_ptr<IFactory>> Factories)
{
	for (int i = 0; i < STANDART_FIELD; i++)
	{
		for (int j = 0; j < STANDART_FIELD; j++)
		{
			enemyField_[i][j] = ' ';
			yourField_[i][j] = ' ';
		}
	}
	try {
		for (shared_ptr<IFactory> item : Factories)
		{
			addShip(item);
		}
	}
	catch (exception& ex)
	{
		cout <<ex.what() << endl;
	}
}

void Player::addShip(shared_ptr<IFactory> factory)
{
	YourShips_.push_back(factory->createShip(yourField_));
}

Player::~Player()
{
	
}


#include "Player.h"



Player::Player()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			enemyfield[i][j] = ' ';
			yourfield[i][j] = ' ';
		}
	}
	this->CreateShips();
}

void Player::CreateShips()
{
	FourDeckShip Ship(yourfield);
	YourShips.push_back(Ship);
	for (int i = 0; i < 2; i++)
	{
		ThreeDeckShip Ship(yourfield);
		YourShips.push_back(Ship);
	}
	for (int i = 0; i < 3; i++)
	{
		DoubleDeckShip Ship(yourfield);
		YourShips.push_back(Ship);
	}
	for (int i = 0; i < 4; i++)
	{
		SingleDeckShip Ship(yourfield);
		YourShips.push_back(Ship);
	}
}


Player::~Player()
{
}

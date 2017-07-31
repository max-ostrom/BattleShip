#include "Player.h"



Player::Player() 
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			enemyfield_[i][j] = ' ';
			yourfield_[i][j] = ' ';
		}
	}


	YourShips.push_back(new FourDeckShip(yourfield_));
	for (int i = 0; i < 2; i++)
	{
	
		YourShips.push_back(new ThreeDeckShip(yourfield_));
	}
	for (int i = 0; i < 3; i++)
	{
		YourShips.push_back(new DoubleDeckShip(yourfield_));
	}
	for (int i = 0; i < 4; i++)
	{
		YourShips.push_back(new SingleDeckShip(yourfield_));
	}
}
Player::~Player()
{
}

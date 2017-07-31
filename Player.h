#pragma once
#include <iostream>
#include <list>
#include "SingleDeckShip.h"
#include "DoubleDeckShip.h"
#include "ThreeDeckShip.h"
#include "FourDeckShip.h"
using namespace std;
class Player
{
public:
	Player();
	
	~Player();
	char GetField(int i, int j)
	{ 
		if (i >= 0 && i < 11 && j >= 0 && j < 11)
			return yourfield[i][j];
		else
			return NULL;
	}
	char GetEnemyField(int i, int j)
	{
		if (i >= 0 && i < 11 && j >= 0 && j < 11)
			return enemyfield[i][j];
		else
			return NULL;
	}
	void SetField(int i, int j)
	{
		if (yourfield[i][j] == ' ' || yourfield[i][j] == '*')
			yourfield[i][j] = '*';
		else
			yourfield[i][j] = '#';
	}
	void SetEnemyField(int i, int j,Player& p )
	{
		if (p.yourfield[i][j] == ' ' || p.yourfield[i][j] == '*')
			enemyfield[i][j] = '*';
		else
			enemyfield[i][j] = '#';
	}
	list<Ship> YourShips;
private:
	void CreateShips();
	char yourfield[10][10];
	char enemyfield[10][10];
	

};


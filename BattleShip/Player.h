#pragma once
#include <iostream>
#include <list>
#include <vector>
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
			return yourfield_[i][j];
		else
			return NULL;
	}
	char GetEnemyField(int i, int j)
	{
		if (i >= 0 && i < 11 && j >= 0 && j < 11)
			return enemyfield_[i][j];
		else
			return NULL;
	}
	void SetField(int i, int j)
	{
		if (yourfield_[i][j] == ' ' || yourfield_[i][j] == '*')
			yourfield_[i][j] = '*';
		else
			yourfield_[i][j] = '#';
	}
	void SetEnemyField(int i, int j,Player& p )
	{
		if (p.yourfield_[i][j] == ' ' || p.yourfield_[i][j] == '*')
			enemyfield_[i][j] = '*';
		else
			enemyfield_[i][j] = '#';
	}
	vector<Ship*> YourShips; 
	// привет полиморфизму и переопределенный методам 
private:
	int aliveShips_ = 10;
	char yourfield_[10][10];
	char enemyfield_[10][10];
	
	
	
	

};


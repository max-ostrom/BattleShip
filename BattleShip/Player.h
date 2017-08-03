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
private:
	char yourField_[10][10];
	char enemyField_[10][10];
public:
	vector<IShip*> YourShips;

	Player();
	~Player();
	void setField(int i, int j);
	void setEnemyField(int i, int j, const Player& p);
	void setNearCell(IShip* item);

	bool isShipAlive(IShip* item);
	bool isEndOfGame();

	char getField(const int i, const int j) const;
	char getEnemyField(const int i, const int j) const;

};


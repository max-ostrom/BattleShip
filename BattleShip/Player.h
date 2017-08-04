#pragma once
#include <iostream>
#include <vector>

#include"UnionHeader.h"

class Player
{
private:
	char yourField_[10][10];
	char enemyField_[10][10];
public:
	std::vector<Ship*> YourShips;
	Player();
	~Player();
	void setField(const int i, const int j);
	void setEnemyField(const int i, const  int j,const Player& p);
	void setNearCell(Ship* item);

	bool isShipAlive(Ship* item) ;
	bool isEndOfGame() const;

	char getField(const int i, const int j) const;
	char getEnemyField(const int i, const int j) const;

};


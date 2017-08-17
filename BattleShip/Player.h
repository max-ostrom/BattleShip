#ifndef Player_H
#define Player_H

#include <iostream>
#include <vector>

#include "UnionFactory.h"
#include "Settings.h"
#include "UnionHeader.h"
#include "Observable.h"
class Player :
	public Observable
{
public:
	std::vector<std::shared_ptr<Ship>>& getShips();
	const std::vector<std::shared_ptr<Ship>>& getShips() const;
	Player(IShipSettings& shipSettings);
	virtual ~Player();
	void setField(const int& i, const int& j);
	void setEnemyField(const int& i, const  int& j,const Player& p);
	void setNearCell(Ship* item);
	bool isShipAlive(Ship* item) ;
	bool isEndOfGame() const;

	char getField(const int& i, const int& j) const;
	char getEnemyField(const int& i, const int& j) const;
private:
	std::vector<std::shared_ptr<Ship>> YourShips;

	char yourField_[FIELDSIZE][FIELDSIZE];
	char enemyField_[FIELDSIZE][FIELDSIZE];

	void fillLeftTopConnorCell(Ship* item);
	void fillLeftBottomConnorCell(Ship* item);
	void fillRightTopConnorCell(Ship* item);
	void fillRightBottomConnorCell(Ship* item);

	void fillLeftSideCell(Ship* item);
	void fillBottomSideCell(Ship* item);
	void fillRightSideCell(Ship* item);
	void fillTopSideCell(Ship* item);

	void addShip(IFactory& factory);
};

#endif
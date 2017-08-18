#ifndef Player_H
#define Player_H

#include <iostream>
#include <vector>

#include "UnionFactory.h"
#include "Settings.h"
#include "UnionHeader.h"
#include "Observable.h"
#include"IPlayer.h"
class Player :
	public Observable, public IPlayer
{
public:
	std::vector<std::shared_ptr<Ship>>& getShips() override;
	const std::vector<std::shared_ptr<Ship>>& getShips() const override;
	Player(IShipSettings& shipSettings);
	virtual ~Player();
	void setField(const int& i, const int& j) override;
	void setEnemyField(const int& i, const  int& j,const IPlayer& p) override;
	void setNearCell(shared_ptr<Ship> item);
	bool isShipAlive(shared_ptr<Ship> item) ;
	bool isEndOfGame() const;

	char getField(const int& i, const int& j) const override;
	char getEnemyField(const int& i, const int& j) const override;
private:
	std::vector<std::shared_ptr<Ship>> YourShips_;

	char yourField_[FIELD_SIZE][FIELD_SIZE];
	char enemyField_[FIELD_SIZE][FIELD_SIZE];

	void fillLeftTopConnorCell(shared_ptr<Ship> item);
	void fillLeftBottomConnorCell(shared_ptr<Ship> item);
	void fillRightTopConnorCell(shared_ptr<Ship> item);
	void fillRightBottomConnorCell(shared_ptr<Ship> item);

	void fillLeftSideCell(shared_ptr<Ship> item);
	void fillBottomSideCell(shared_ptr<Ship> item);
	void fillRightSideCell(shared_ptr<Ship> item);
	void fillTopSideCell(shared_ptr<Ship> item);

	void addShip(IFactory& factory);
};

#endif
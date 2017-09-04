#ifndef Player_H
#define Player_H

#include <iostream>
#include <vector>

#include "..\Resource\UnionFactory.h"
#include "..\Resource\Settings.h"
#include "..\Resource\UnionHeader.h"
#include "IPlayer.h"
#include "PlayerHelper.h"
// must have class PlayerHelper !!!!
class Player :
	 public IPlayer
{
public:
	std::vector<std::shared_ptr<Ship>>& getShips() override;
	const std::vector<std::shared_ptr<Ship>>& getShips() const override;
	Player(IShipSettings& shipSettings = Settings());
	virtual ~Player();
	void setField(const int i, const int j) override;
	void setEnemyField(const int i, const  int j,const IField& p) override;
	bool isShipAlive(shared_ptr<Ship> Ship_) override;
	bool isEndOfGame() const override;

	char getField(const int i, const int j) const override;
	char getEnemyField(const int i, const int j) const override;
private:
	std::vector<std::shared_ptr<Ship>> YourShips_;

	char yourField_[STANDART_FIELD][STANDART_FIELD];
	char enemyField_[STANDART_FIELD][STANDART_FIELD];

	void addShip(IFactory& factory);
};

#endif
#pragma once
#include "Player.h"

class GameModel 
{
public:
	Player& getUser();
	Player& getComputer();
	void setStartTime(clock_t start);
	const clock_t& getStartTime() const;
	GameModel();

protected:
	Player You_;
	Player Computer_;
	clock_t startGame_;
};


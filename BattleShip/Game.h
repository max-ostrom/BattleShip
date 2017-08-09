#pragma once
#include "Player.h"
class Game 
{
protected:
	char choose_[7];
	Player You_;
	Player Computer_;

	virtual void endOfGame(const clock_t& startGame) const = 0;
	virtual void reprintField() const = 0 ;
	virtual bool isKeyPressed(const int& key) const = 0;

public:
	virtual void run() = 0;
	Game();
};


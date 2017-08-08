#pragma once
#include "Player.h"
class Game 
{
private:
	int seconds = 0;
	char choose_[7];
	Player You_;
	Player Computer_;

	void endOfGame(const clock_t& startGame) const;
	void reprintField() const;

	
	bool isKeyPressed(const int& key) const;

public:
	Game();
};


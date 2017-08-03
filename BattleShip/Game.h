#pragma once
#include "Player.h"
class Game
{
private:


	int seconds = 0;
	char choose_[7];
	Player You_;
	Player Computer_;

	void endOfGame(clock_t startGame);
	void reprintField();
	void setSeconds(int s) { seconds = s; }
	
	int getSeconds() { return seconds; }
	
	bool isKeyPressed(int key);

public:
	Game();
	
};


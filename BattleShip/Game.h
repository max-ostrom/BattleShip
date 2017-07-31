#pragma once
#include "Player.h"
class Game
{
public:
	Game();
	~Game();
	void Reprintfield();
	bool EndOfYourGame();
	bool EndOfComputerGame();
	void NearCell(Ship* s,int x, int y);
	void setSeconds(int s) { seconds = s; }
	int getSeconds() { return seconds; }
private :
	void Timer();
	void PauseTimer();
	void FillNearestCell(Ship* item, Player& You_);
	int seconds = 0;
	char choose_[7];
	Player You_;
	Player Computer_;
};


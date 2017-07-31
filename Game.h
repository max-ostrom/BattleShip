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
	void NearCell(Ship& s);
private :
	Player you;
	Player computer;
};


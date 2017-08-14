#ifndef Game_H
#define Game_H

#include "Player.h"

class GameModel 
{
public:
	Player& getUser();
	Player& getComputer();
	const Player& getUser() const;
	const Player& getComputer() const;
	void setStartTime(clock_t start);
	const clock_t& getStartTime() const;
	GameModel();
private:
	Player You_;
	Player Computer_;
	clock_t startGame_;
};
#endif

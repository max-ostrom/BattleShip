#ifndef Game_H
#define Game_H

#include "Player.h"

class GameModel 
{
public:
	IPlayer& getUser();
	IPlayer& getComputer();
	const IPlayer& getUser() const;
	const IPlayer& getComputer() const;
	void setStartTime(clock_t start);
	const clock_t& getStartTime() const;
	GameModel(IPlayer& you = Player(), IPlayer& computer = Player());
private:
	IPlayer& You_;
	IPlayer& Computer_;
	clock_t startGame_;
};
#endif

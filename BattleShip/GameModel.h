#ifndef Game_H
#define Game_H

#include "Player.h"
#include "IGameWithTime.h"
class GameModel :
	public IGameWithTime
{
public:
	IPlayer& getUser() override;
	IPlayer& getComputer() override;
	const IPlayer& getUser() const override;
	const IPlayer& getComputer() const override;
	void setStartTime(clock_t start) override;
	const clock_t& getStartTime() const override;
	GameModel(IPlayer& you = Player(), IPlayer& computer = Player());
private:
	IPlayer& You_;
	IPlayer& Computer_;
	clock_t startGame_;
};
#endif

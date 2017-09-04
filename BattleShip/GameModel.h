#ifndef Game_H
#define Game_H

#include "Players\Player.h"
#include "ITime.h"
#include "IGame.h"
class GameModel :
	 public IGame , public ITime
{
public:
	IPlayer& getUser() override;
	IPlayer& getComputer() override;
	const IPlayer& getUser() const override;
	const IPlayer& getComputer() const override;
	void setStartTime(clock_t start) override;
	const clock_t& getStartTime() const override;
	GameModel(IPlayer& you , IPlayer& computer );
private:
	IPlayer& You_;
	IPlayer& Computer_;
	clock_t startGame_;
};
#endif

#ifndef Controller_H
#define Controller_H

#include "Game.h"
class Controller final
{
public:
	void run();
	Controller(GameModel& model);
private:
	bool isKeyPressed(const int& key) const;
	GameModel& model_;
};
#endif

#ifndef Controller_H
#define Controller_H

#include "GameModel.h"
class Controller final
{
public:
	void run();
	Controller(GameModel& gameModel);
private:
	bool isKeyPressed(const int& key) const;
	GameModel& model_;
};
#endif

#ifndef Controller_H
#define Controller_H

#include "Game.h"
class Controller
{
public:
	virtual void run();
	Controller(GameModel* model);
	~Controller();
private:
	virtual bool isKeyPressed(const int& key) const;
	std::shared_ptr<GameModel> model_;
	char choose_[7];
};
#endif

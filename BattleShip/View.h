#ifndef View_H
#define View_H

#include <memory>

#include "Observer.h"
#include "Game.h"

class View final :
	public Observer
{
public:
	View(GameModel& model);
	void update() const override;
private:
	void endOfGame() const;
	const GameModel& model_;
};
#endif

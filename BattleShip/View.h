#ifndef View_H
#define View_H

#include <memory>

#include "Observer.h"
#include "GameModel.h"

class View final :
	public Observer
{
public:
	View(const GameModel& gameModel);
	void update() const override;
private:
	void endOfGame() const;
	const GameModel& model_;
};
#endif

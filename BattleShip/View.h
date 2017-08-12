#ifndef View_H
#define View_H

#include <memory>

#include "Observer.h"
#include "Game.h"

class View :
	public Observer
{
public:
	explicit View(GameModel* model);
	void update() const override;
	~View();
private:
	void endOfGame() const;
	const std::shared_ptr<const GameModel> model_;
};
#endif

#pragma once
#include <memory>
#include "Observer.h"
#include "Game.h"
class View :
	public Observer
{
public:
	View(GameModel* model);
	void update() const override;
	~View();
private:
	void endOfGame() const;
	std::shared_ptr<GameModel> model_;
};


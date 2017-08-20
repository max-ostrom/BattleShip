#ifndef View_H
#define View_H

#include <memory>

#include "Observer.h"
#include "GameModel.h"

class View final :
	public Observer
{
public:
	View(const IGameWithTime& gameModel);
	void update() const override;
private:
	void endOfGame() const;
	const IGameWithTime& model_;
};
#endif

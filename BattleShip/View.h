#ifndef View_H
#define View_H

#include <memory>

#include "IView.h"
#include "GameModel.h"
class View final :
	public GameModel, public IView
{
public:
	explicit View(IPlayer& you = Player(), IPlayer& computer = Player());
	void update() const override;
private:
	void endOfGame() const override;
	
};
#endif

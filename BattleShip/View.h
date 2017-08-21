#ifndef View_H
#define View_H

#include <memory>

#include "Observer.h"
#include "GameModel.h"

class View final :
	public Observer
{
public:
	View(const IGame& gameModel,const ITime& time);
	void update() const override;
private:
	void endOfGame() const;
	const IGame& Model_;
	const ITime& Time_;
};
#endif

#ifndef View_H
#define View_H

#include <memory>

#include "IView.h"
#include "GameModel.h"

class View final :
	public IView
{
public:
	explicit View(const IGame& gameModel,const ITime& time);
	void update() const override;
private:
	void endOfGame() const override;
	const IGame& Model_;
	const ITime& Time_;
};
#endif

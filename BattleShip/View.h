#ifndef View_H
#define View_H

#include <memory>

#include "Observer.h"
#include "GameModel.h"
#include "ViewModel.h"
class View final :
	public Observer, public ITime
{
public:
	View(const IViewModel& game);
	void update() const override;
	void setStartTime(clock_t start) override;
	const clock_t& getStartTime() const override;
private:
	const IViewModel& Model_;
	clock_t startGame_;
};
#endif

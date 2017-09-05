#ifndef View_H
#define View_H

#include <memory>

#include "Observer.h"
#include "GameModel.h"
class View final :
	public Observer, public ITime
{
public:
	explicit View(const IGame& game);
	void update() const override;
	void setStartTime(clock_t start) override;
	const clock_t& getStartTime() const override;
private:
	void endOfGame() const;
	const IGame& Model_;
	clock_t startGame_;
};
#endif

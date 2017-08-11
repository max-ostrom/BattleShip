#include "Observable.h"
#include <algorithm>

void Observable::addObserver(Observer *observer)
{
	observers_.push_back(std::shared_ptr<Observer>(observer));
}
void Observable::notifyUpdate()
{
	std::for_each(observers_.begin(), observers_.end(), [this](std::shared_ptr<Observer> item)// Lambda expression
	{
		item.get()->update();
	});
}
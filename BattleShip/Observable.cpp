#include "Observable.h"
#include <algorithm>
#include <iostream>
void Observable::addObserver(std::shared_ptr<Observer> observer)
{
	if (observer.get() == nullptr)
	{
		throw std::exception();
	}
	observers_.push_back(observer);
}
void Observable::notifyUpdate() const
{
	std::for_each(observers_.begin(), observers_.end(), [](std::shared_ptr<Observer> item)// Lambda expression
	{
		item->update();
	});
}
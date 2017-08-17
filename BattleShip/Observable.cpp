#include "Observable.h"
#include <new>
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
{	// i dont know what can fix here
	std::for_each(observers_.begin(), observers_.end(), [](const std::shared_ptr<Observer> item)// Lambda expression
	{
		item->update();
	});
}
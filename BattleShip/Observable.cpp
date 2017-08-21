#include <algorithm>
#include <iostream>
#include <thread> 
#include <mutex>

#include "Observable.h"

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
	// Lambda expression
	std::mutex locker;
	std::for_each(observers_.begin(), observers_.end(), [&locker](const std::shared_ptr<Observer> item) 
	{	
		locker.lock();
		std::thread([item] {item->update(); }).join();
		locker.unlock();
	});
}
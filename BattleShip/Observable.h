#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include "Observer.h"
class Observable
{
public:
	void addObserver(Observer *observer);
	void notifyUpdate();
private:
	std::vector<std::shared_ptr<Observer>> observers_;
};


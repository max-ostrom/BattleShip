#ifndef Observable_H
#define Observable_H

#include <vector>
#include <memory>
#include <algorithm>

#include "Observer.h"

class Observable
{
public:
	void addObserver(std::shared_ptr<Observer> observer);
	void notifyUpdate() const;
private:
	std::vector<std::shared_ptr<Observer>> observers_;
};
#endif

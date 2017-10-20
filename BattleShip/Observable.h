#ifndef Observable_H
#define Observable_H

#include <list>
#include <memory>
#include <algorithm>

#include "Observer.h"

class Observable
{
public:
    void addObserver(std::shared_ptr<Observer> observer);
    void notifyUpdate() const;
private:
    std::list<std::shared_ptr<Observer>> observers_;
};
#endif

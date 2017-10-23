#ifndef IController_H
#define IController_H

#include "../Observer/Observable.h"
class IController :
    public Observable
{
public:

    virtual void run() = 0;
    virtual void input() = 0;
    virtual ~IController()
    {
    }
};
#endif

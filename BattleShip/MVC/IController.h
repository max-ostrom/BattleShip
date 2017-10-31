#ifndef IController_H
#define IController_H

#include "../../BattleShipLibrary/Patterns/Observer/Observable.h"
namespace BattleShip
{
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
}
#endif

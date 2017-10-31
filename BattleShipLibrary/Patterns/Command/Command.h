#ifndef Command_H
#define Command_H

#include "../../Players/PlayerHelper.h"
#include "../../../BattleShipLibrary/Exceptions/ExecuteCommandException.h"

#include <mutex>
namespace BattleShip
{
    class Command
    {
    protected:
        std::mutex mutex_;
    public:
        virtual ~Command() {}
        virtual void execute() = 0;
        virtual bool tryExecute() = 0;
    };
}
#endif
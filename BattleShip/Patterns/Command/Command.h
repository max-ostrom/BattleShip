#ifndef Command_H
#define Command_H

#include "../../Players/PlayerHelper.h"
#include "../../../BattleShip/Exceptions/ExecuteCommandException.h"

#include <mutex>
class Command
{
protected:
    std::mutex mutex_;
public:
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual bool tryExecute() = 0;
};
#endif
#ifndef Command_H
#define Command_H

#include "../../Players/PlayerHelper.h"

class Command
{
public:
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual bool tryExecute() = 0;
};
#endif
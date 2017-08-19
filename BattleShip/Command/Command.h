#ifndef Command_H
#define Command_H
#include "../PlayerHelper.h"
class Command 
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;
};
#endif
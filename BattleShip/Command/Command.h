#pragma once
#include "../PlayerHelper.h"
class Command 
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;
};
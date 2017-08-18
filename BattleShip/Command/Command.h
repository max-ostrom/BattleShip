#pragma once
#include "../PlayerHelper.h"
class Command
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;
protected:
	Command(PlayerHelper& p) : PlayerHelper_(p) {}
	PlayerHelper& PlayerHelper_;
};
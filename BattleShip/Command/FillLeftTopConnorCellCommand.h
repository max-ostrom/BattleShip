#pragma once
#include "Command.h"
class FillLeftTopConnorCellCommand : public Command
{
public:
	FillLeftTopConnorCellCommand(PlayerHelper& p) : Command(p) {}
	void execute() {
		PlayerHelper_.fillLeftTopConnorCell();
	}
};
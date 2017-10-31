#include "ExecuteCommandException.h"

namespace BattleShip
{
    char const * ExecuteCommandException::what() const
    {
        return "Can not execute command";
    }
}
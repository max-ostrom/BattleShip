#include "ExecuteCommandException.h"





char const * ExecuteCommandException::what() const
{
    return "Can not execute command";
}

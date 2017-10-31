#pragma once
#include <iostream>
namespace BattleShip
{
    class ExecuteCommandException :
        public std::exception
    {
    public:
        char const* what() const override;

    };
}

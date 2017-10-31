#pragma once
#include <iostream>
class ExecuteCommandException :
    public std::exception
{
public:
    char const* what() const override;

};


#include <iostream>

class CreateShipException : 
    public std::exception
{
public:
    char const* what() const override;
};

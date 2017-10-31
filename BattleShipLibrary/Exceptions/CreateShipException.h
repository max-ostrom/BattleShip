#include <iostream>
#include <string>
class CreateShipException : 
    public std::exception
{
private:
    std::string shipType_;
public:
    CreateShipException(const std::string ShipType);
    char const* what() const override;
};

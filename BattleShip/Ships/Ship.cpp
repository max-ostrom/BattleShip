#include "Ship.h"

bool Ship::isAlive() const 
{ 
	return is_Alive_; 
}

void Ship::destroy() 
{
	is_Alive_ = false; 
}

std::shared_ptr<int> Ship::getX() const
{ 
	return coordsX_; 
}

std::shared_ptr<int> Ship::getY() const
{ 
	return coordsY_; 
}
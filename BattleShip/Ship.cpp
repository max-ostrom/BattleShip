#include "Ship.h"

bool Ship::isAlive() const 
{ 
	return is_Alive_; 
}

void Ship::destroy() 
{
	is_Alive_ = false; 
}

int* Ship::getX() const
{ 
	return coordsX_.get(); 
}

int* Ship::getY() const
{ 
	return coordsY_.get(); 
}
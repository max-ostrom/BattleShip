

#include "GameModel.h"

Player& GameModel::getUser() 
{ 
	return You_; 
}
Player& GameModel::getComputer()
{
	return Computer_;
}
const Player & GameModel::getUser() const
{
	return You_;
}
const Player & GameModel::getComputer() const
{
	return Computer_;
}
void GameModel::setStartTime(clock_t start) 
{ 
	startGame_ = start; 
}
const clock_t& GameModel::getStartTime() const
{
	return startGame_;
}
GameModel::GameModel()
	: You_(Settings()) , Computer_(Settings())
{
	
}





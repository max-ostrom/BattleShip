

#include "GameModel.h"

IPlayer& GameModel::getUser() 
{ 
	return You_; 
}
IPlayer& GameModel::getComputer()
{
	return Computer_;
}
const IPlayer & GameModel::getUser() const
{
	return You_;
}
const IPlayer & GameModel::getComputer() const
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
GameModel::GameModel(IPlayer& you = Player(), IPlayer& computer = Player())
	: You_(you) , Computer_(computer)
{
	
}





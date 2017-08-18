#ifndef PlayerHelper_H
#define PlayerHelper_H

#include "IPlayer.h"


#include <memory>
#include "Command\Command.h"
using namespace std;
class PlayerHelper
{
public:
	PlayerHelper(IPlayer& p, shared_ptr<Ship> Ship_);
	virtual ~PlayerHelper();

	void fillCells(Command& command);
	
	shared_ptr<Ship> getShip();
	shared_ptr<Ship> getShip() const;

	IPlayer& getPlayer();
	IPlayer& getPlayer() const;
private:
	shared_ptr<Ship> Ship_;
	IPlayer& Player_;
};
#endif
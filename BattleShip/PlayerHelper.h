#ifndef PlayerHelper_H
#define PlayerHelper_H

#include <memory>

#include "Command\Command.h"
#include "IPlayer.h"

using namespace std;

class PlayerHelper
{
public:
	PlayerHelper(IField& p, shared_ptr<Ship> Ship_);
	virtual ~PlayerHelper();

	void fillCells(Command& command);
	
	shared_ptr<Ship> getShip();
	shared_ptr<Ship> getShip() const;

	IField& getPlayer();
	IField& getPlayer() const;
private:
	shared_ptr<Ship> Ship_;
	IField& Player_;
};
#endif
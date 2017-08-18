#ifndef IPlayer_H
#define IPlayer_H

#include <vector>
#include <memory>

#include "Ships\Ship.h"
class IPlayer
{
public:
	virtual bool isEndOfGame() const = 0;
	virtual bool isShipAlive(std::shared_ptr<Ship> item) = 0;
	virtual std::vector<std::shared_ptr<Ship>>& getShips() = 0;
	virtual const std::vector<std::shared_ptr<Ship>>& getShips() const = 0;
	virtual char getField(const int& i, const int& j) const = 0 ;
	virtual char getEnemyField(const int& i, const int& j) const = 0;
	virtual void setField(const int& i, const int& j) = 0;
	virtual void setEnemyField(const int& i, const  int& j, const IPlayer& p) = 0;
	virtual ~IPlayer() {}
};
#endif

#ifndef PlayerHelper_H
#define PlayerHelper_H

#include "IPlayer.h"

#include <memory>

using namespace std;
class PlayerHelper
{
public:
	PlayerHelper(IPlayer& p, shared_ptr<Ship> item);
	virtual ~PlayerHelper();

	void fillLeftTopConnorCell();
	void fillLeftBottomConnorCell();
	void fillRightTopConnorCell();
	void fillRightBottomConnorCell();

	void fillLeftSideCell();
	void fillBottomSideCell();
	void fillRightSideCell();
	void fillTopSideCell();

	shared_ptr<Ship> getShip();
	shared_ptr<Ship> getShip() const;
private:
	shared_ptr<Ship> item;
	IPlayer& Player_;
};
#endif
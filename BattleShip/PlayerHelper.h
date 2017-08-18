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
private:
	void fillLeftTopConnorCell(shared_ptr<Ship> item);
	void fillLeftBottomConnorCell(shared_ptr<Ship> item);
	void fillRightTopConnorCell(shared_ptr<Ship> item);
	void fillRightBottomConnorCell(shared_ptr<Ship> item);

	void fillLeftSideCell(shared_ptr<Ship> item);
	void fillBottomSideCell(shared_ptr<Ship> item);
	void fillRightSideCell(shared_ptr<Ship> item);
	void fillTopSideCell(shared_ptr<Ship> item);

	IPlayer& Player_;
};
#endif
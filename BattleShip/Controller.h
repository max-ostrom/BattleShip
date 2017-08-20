#ifndef Controller_H
#define Controller_H

#include "GameModel.h"

class Controller final
{
public:
	//pattern STATE soon
	void run();
	Controller(IGameWithTime& gameModel);
private:
	bool isKeyPressed(const int& key) const;
	IGameWithTime& model_;
};
#endif

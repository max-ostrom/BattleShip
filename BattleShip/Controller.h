#ifndef Controller_H
#define Controller_H

#include "GameModel.h"

class Controller final
{
public:
	//pattern STATE soon
	void run();
	explicit Controller(IGame& gameModel, ITime& time);
private:
	bool isKeyPressed(const int& key) const;
	IGame& Model_;
	ITime& Time_;
};
#endif

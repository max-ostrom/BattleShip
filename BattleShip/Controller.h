#ifndef Controller_H
#define Controller_H

#include "GameModel.h"
#include "IController.h"
class Controller final : 
	public IController
{
public:
	// main game loop
	void run() override;
	explicit Controller(IGame& gameModel, ITime& time);
private:
	//here user input coords 
	void input(vector<int>& coordAtack) override;
	bool isKeyPressed(const int& key) const;
	IGame& Model_;
	ITime& Time_;
};
#endif

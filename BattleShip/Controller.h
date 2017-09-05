#ifndef Controller_H
#define Controller_H

#include "GameModel.h"
#include "IController.h"
#include "IViewModel.h"
class Controller final : 
	public IController
{
public:
	// main game loop
	void run() override;
	explicit Controller(IGame& gameModel, ITime& time, shared_ptr<Observer> view, shared_ptr<IViewModel> viewModel);
private:
	//here user input coords 
	void userAtack();
	void computerAtack();
	void input() override;
	bool isKeyPressed(const int& key) const;

	shared_ptr<IViewModel> viewModel_;
	shared_ptr<Observer> view_ ;
	IGame& Model_;
	ITime& Time_;

	vector<int> coordAtack = { 0,0 };
	bool turn = true;
};
#endif

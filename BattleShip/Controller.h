#ifndef Controller_H
#define Controller_H

#include "GameModel.h"
#include "IController.h"
#include "IViewModel.h"
#include "View.h"
class Controller final : 
	public IController, public Observable
{
public:
	// main game loop
	void run() override;
	explicit Controller(IGame& gameModel, shared_ptr<IViewModel> viewModel);
private:
	//here user input coords 
	void userAtack();
	void computerAtack();
	void input() override;
	bool isKeyPressed(const int& key) const;

	shared_ptr<IViewModel> viewModel_;
	shared_ptr<View> view_ ;
	IGame& Model_;
	vector<int> coordAtack = { 0,0 };
	bool turn = true;
};
#endif

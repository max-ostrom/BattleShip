#include "Controller.h"
#include "View.h"
int main()
{
	GameModel model;
	Controller controller(&model);
	std::shared_ptr<View> view(&model);
	model.getComputer().addObserver(view);
	model.getUser().addObserver(view);
	controller.run();
	return 0;
}
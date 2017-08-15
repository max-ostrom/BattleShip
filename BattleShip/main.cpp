#include "Controller.h"
#include "View.h"
int main()
{
	GameModel model;
	Controller controller(&model);
	View view(&model);
	model.getComputer().addObserver(std::make_shared<View>(view));
	model.getUser().addObserver(std::make_shared<View>(view));
	controller.run();
	return 0;
}
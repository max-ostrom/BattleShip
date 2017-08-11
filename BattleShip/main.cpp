#include "Controller.h"
#include "View.h"
int main()
{
	GameModel model;
	Controller controller(&model);
	View view(&model);
	controller.run();
	return 0;
}
#include "Controller.h"
#include "View.h"
int main()
{
	try {
		GameModel model;
		Controller controller(model);
		std:shared_ptr<View> view = std::make_shared<View>(model);
		model.getComputer().addObserver(view);
		model.getUser().addObserver(view);
		controller.run();
		return 0;
	}
	catch (exception& ex)
	{
		cout << "main "<<ex.what();
	}
}
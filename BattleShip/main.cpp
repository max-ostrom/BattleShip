#include "Controller.h"
#include "View.h"
int main()
{
	try 
	{
		IShipSettings& settings = Settings();
		Player User(settings);
		Player Computer(settings);
		shared_ptr<View> view = make_shared<View>(User,Computer);
		shared_ptr<Controller> controller = make_shared<Controller>(*view.get(), *view.get());
		view->getComputer().addObserver(view);
		view->getUser().addObserver(view);
		controller->run();
		return 0;
	}
	catch (exception& ex)
	{
		cout << "main "<<ex.what();
	}
}
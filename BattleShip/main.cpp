#include "Controller.h"
#include "View.h"
int main()
{
	try 
	{
		IShipSettings& settings = Settings();
		Player User(settings);
		Player Computer(settings);
		GameModel model(User,Computer);
		Controller controller(model,model);
		shared_ptr<View> view = make_shared<View>(model,model);
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
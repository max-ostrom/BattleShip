#include "Controller.h"
#include "View.h"
int main()
{
	try 
	{
		IShipSettings& settings = Settings();
		list<shared_ptr<IFactory>> Factories;
		Factories.push_back(make_shared<FactoryFourShip>());
		for(int i = 0; i <settings.getThreeDeckShipCounter(); i++)
		Factories.push_back(make_shared<FactoryThreeShip>());
		for (int i = 0; i < settings.getDoubleDeckShipCounter(); i++)
		Factories.push_back(make_shared<FactoryDoubleShip>());
		for (int i = 0; i < settings.getSingleDeckShipCounter(); i++)
		Factories.push_back(make_shared<FactorySingleShip>());
		
		IPlayer& User = Player(Factories);
		IPlayer& Computer = Player(Factories);
		GameModel model(User, Computer);
		shared_ptr<IController> controller = make_shared<Controller>(model, model);
		controller->run();
		return 0;
	}
	catch (exception& ex)
	{
		cout << "main "<<ex.what();
	}
}
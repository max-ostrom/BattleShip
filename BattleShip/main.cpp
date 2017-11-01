#include "../BattleShip/MVC/Controller.h"
#include "../BattleShip/MVC/View.h"
#include "../BattleShip/MVC/ViewModel.h"
#include "../BattleShipLibrary/Director.h"
#include "../BattleShipLibrary/PlayerBuilder.h"
using namespace BattleShip;
int main()
{
    try
    {
        Director director;
        IBuilder& builder = PlayerBuilder();
        shared_ptr<IPlayer> User = director.createPlayer(builder);
        shared_ptr<IPlayer> Computer = director.createPlayer(builder);
        GameModel model(User, Computer);

        shared_ptr<IViewModel> viewModel
            = make_shared<ViewModel>();
        shared_ptr<Observer> view
            = make_shared<View>(*viewModel);
        shared_ptr<IController> controller
            = make_shared<Controller>(model, viewModel);

        controller->addObserver(view);
        controller->notifyUpdate();
        controller->run();
        return 0;
    }
    catch (exception& ex)
    {
        cout << "main " << ex.what();
    }
}
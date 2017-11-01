#include "PlayerBuilder.h"
#include "Resource\UnionFactory.h"
#include "Resource\Settings.h"
#include "Players\Player.h"
namespace BattleShip 
{
    using namespace std;
    void PlayerBuilder::setSettings()
    {
        settings = make_shared<Settings>();
    }
    void PlayerBuilder::setFactories()
    {
        Factories.clear();
        Factories.push_back(make_shared<FactoryFourShip>());

        for (int i = 0; i < settings->getThreeDeckShipCounter(); i++)
            Factories.push_back(make_shared<FactoryThreeShip>());

        for (int i = 0; i < settings->getDoubleDeckShipCounter(); i++)
            Factories.push_back(make_shared<FactoryDoubleShip>());

        for (int i = 0; i < settings->getSingleDeckShipCounter(); i++)
            Factories.push_back(make_shared<FactorySingleShip>());
    }
    shared_ptr<IPlayer> PlayerBuilder::biuld()
    {
        shared_ptr<IPlayer> player = make_shared<Player>(Factories);
        return player;
    }
}
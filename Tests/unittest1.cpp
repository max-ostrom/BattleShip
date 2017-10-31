#include "stdafx.h"
#include "CppUnitTest.h"
#include "../BattleShipLibrary/Players/Player.h"
#include "../BattleShipLibrary/Patterns/Factory/FactoryDoubleShip.h"
#include "../BattleShipLibrary/Patterns/Factory/FactorySingleShip.h"
#include "../BattleShipLibrary/Patterns/Factory/FactoryFourShip.h"
#include "../BattleShipLibrary/Patterns/Factory/FactoryThreeShip.h"

#include <list>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{

    TEST_CLASS(Tests)
    {
    public:
        TEST_METHOD(testPlayer)
        {
            std::shared_ptr<IShipSettings>settings = std::make_shared<Settings>();

            std::list<shared_ptr<IFactory>> Factories;

            Factories.push_back(std::make_shared<FactoryFourShip>());

            for (int i = 0; i < settings->getThreeDeckShipCounter(); i++)
                Factories.push_back(std::make_shared<FactoryThreeShip>());

            for (int i = 0; i < settings->getDoubleDeckShipCounter(); i++)
                Factories.push_back(std::make_shared<FactoryDoubleShip>());

            for (int i = 0; i < settings->getSingleDeckShipCounter(); i++)
                Factories.push_back(std::make_shared<FactorySingleShip>());

            IPlayer& p = Player(Factories);
            IPlayer& p2 = Player(Factories);
            Assert::AreEqual(static_cast<size_t>(10), p.getShips().size(), L"Amount of Ships is not correct");

            Assert::IsFalse(p == p2, L"Players field are same");
        }
    };
}
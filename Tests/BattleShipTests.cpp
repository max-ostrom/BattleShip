#include "stdafx.h"
#include "CppUnitTest.h"
#include "../BattleShipLibrary/Players/Player.h"
#include "../BattleShipLibrary/Patterns/Factory/FactoryDoubleShip.h"
#include "../BattleShipLibrary/Patterns/Factory/FactorySingleShip.h"
#include "../BattleShipLibrary/Patterns/Factory/FactoryFourShip.h"
#include "../BattleShipLibrary/Patterns/Factory/FactoryThreeShip.h"

#include <list>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
static Player createPlayer()
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

    Player p(Factories);
    return p;
}
static void throwCreateShipExceptionMethod()
{
    std::shared_ptr<IShipSettings>settings = std::make_shared<Settings>();

    std::list<shared_ptr<IFactory>> Factories;
    for (int i = 0; i < 100; i++)
        Factories.push_back(std::make_shared<FactoryFourShip>());

    IPlayer& p = Player(Factories);

}
namespace Tests
{

    TEST_CLASS(Tests)
    {
    public:
        TEST_METHOD(testPlayer)
        {
            IPlayer& p = createPlayer();
            IPlayer& p2 = createPlayer();
            Assert::AreEqual(static_cast<size_t>(10), p.getShips().size(), L"Amount of Ships is not correct");

            Assert::IsFalse(p == p2, L"Players field are same");
        }
        TEST_METHOD(testShips)
        {
            IPlayer& p = createPlayer();
            for (size_t i = 0; i < p.getShips().size(); i++)
            {
                for (size_t j = 0; j < p.getShips().size(); j++)
                {
                    if (i != j)
                    {
                        Assert::IsTrue(p.getShips()[i]->getX().get()[0] != p.getShips()[j]->getX().get()[0]
                            || p.getShips()[i]->getY().get()[0] != p.getShips()[j]->getY().get()[0], L"Ships are on same positions");
                    }
                }
            }
        }
        TEST_METHOD(testCreateShipException)
        {
            Assert::IsTrue(false);
            /*function<void(void)> f = throwCreateShipExceptionMethod;
            Assert::ExpectException<CreateShipException>(throwCreateShipExceptionMethod);*/
        }
        TEST_METHOD(testFillTopRightCornerCell)
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

            Player p(Factories);
            do 
            {
                p = Player(Factories);
            } while (p.getField(0, 0) == ShipInfo::EMPTY_CELL);
            for (auto item : p.getShips())
            {
                if (item->getX().get()[0] == 0 && item->getY().get()[0] == 0) // find ship which are on position [0,0]
                {
                    for (int i = 0; i < item.get()->getShipSize(); i++)
                    {
                        p.setField(item->getX().get()[i], item->getY().get()[i]); // fill Ships Cells
                    }
                    p.isShipAlive(item); // fill Cells around ship and destroy ship
                    Assert::AreEqual(false, item->isAlive(),L"Ship are not destroyed");
                    break;
                }
            }
            Assert::AreEqual(static_cast<char>(ShipInfo::HITTING)
                ,(p.getField(0, 0)), L"TopRightCornerCell are not filled");

            Assert::AreEqual(static_cast<char>(ShipInfo::MIS_HIT)
                , (p.getField(1, 1)), L"TopRightCornerCell are not filled");
        }
    };
}
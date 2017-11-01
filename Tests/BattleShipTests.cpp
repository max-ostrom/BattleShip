#include "stdafx.h"
#include "CppUnitTest.h"
#include "../BattleShipLibrary/Players/Player.h"
#include "../BattleShipLibrary/Patterns/Factory/FactoryDoubleShip.h"
#include "../BattleShipLibrary/Patterns/Factory/FactorySingleShip.h"
#include "../BattleShipLibrary/Patterns/Factory/FactoryFourShip.h"
#include "../BattleShipLibrary/Patterns/Factory/FactoryThreeShip.h"
#include "../BattleShipLibrary/Director.h"
#include "../BattleShipLibrary/PlayerBuilder.h"

#include <list>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace BattleShip;

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


        TEST_METHOD(testAmountOfShips)
        {

            Director director;
            IBuilder& builder = PlayerBuilder();
            shared_ptr<IPlayer> p = director.createPlayer(builder);
            Assert::AreEqual(static_cast<size_t>(10), p->getShips().size(), L"Amount of Ships is not correct");

        }
        TEST_METHOD(testSamePlayersFields)
        {
            Director director;
            IBuilder& builder = PlayerBuilder();
            shared_ptr<IPlayer> p = director.createPlayer(builder);

            shared_ptr<IPlayer> p2 = director.createPlayer(builder);
            Assert::IsFalse(p == p2, L"Players field are same");
        }

        TEST_METHOD(testShips)
        {
            Director director;
            IBuilder& builder = PlayerBuilder();
            shared_ptr<IPlayer> p = director.createPlayer(builder);
            for (size_t i = 0; i < p->getShips().size(); i++)
            {
                for (size_t j = 0; j < p->getShips().size(); j++)
                {
                    if (i != j)
                    {
                        Assert::IsTrue(p->getShips()[i]->getX().get()[0] != p->getShips()[j]->getX().get()[0]
                            || p->getShips()[i]->getY().get()[0] != p->getShips()[j]->getY().get()[0], L"Ships are on same positions");
                    }
                }
            }
            for (auto item : p->getShips())
            {
                Assert::AreEqual(true,item.get()->isAlive(), L"Not all ships are alive");
            }
        }


        TEST_METHOD(testCreateShipException)
        {
            Assert::IsTrue(false,L"Not implemented test");
            /*function<void(void)> f = throwCreateShipExceptionMethod;
            Assert::ExpectException<CreateShipException>(throwCreateShipExceptionMethod);*/
        }


        TEST_METHOD(testSettings)
        {
            std::shared_ptr<IShipSettings>settings = std::make_shared<Settings>();

            Assert::AreEqual(2, settings->getThreeDeckShipCounter(), L"Amount of ThreeDeckShips is not right");
            Assert::AreEqual(3, settings->getDoubleDeckShipCounter(), L"Amount of DoubleDeckShips is not right");
            Assert::AreEqual(4, settings->getSingleDeckShipCounter(), L"Amount of SingleDeckShips is not right");
        }


        TEST_METHOD(testFillTopRightCornerCell)
        {

            Director director;
            IBuilder& builder = PlayerBuilder();
            shared_ptr<IPlayer> p = director.createPlayer(builder);
            while (p->getField(0, 0) == ShipInfo::EMPTY_CELL) 
            {
                p = director.createPlayer(builder);
            }
            for (auto item : p->getShips())
            {
                if (item->getX().get()[0] == 0 && item->getY().get()[0] == 0) // find ship which are on position [0,0]
                {
                    for (int i = 0; i < item.get()->getShipSize(); i++)
                    {
                        p->setField(item->getX().get()[i], item->getY().get()[i]); // fill Ships Cells
                    }
                    p->isShipAlive(item); // fill Cells around ship and destroy ship
                    Assert::AreEqual(false, item->isAlive(),L"Ship are not destroyed");
                    break;
                }
            }
            Assert::AreEqual(static_cast<char>(ShipInfo::HITTING)
                ,(p->getField(0, 0)), L"TopRightCornerCell are not filled");

            Assert::AreEqual(static_cast<char>(ShipInfo::MIS_HIT)
                , (p->getField(1, 1)), L"TopRightCornerCell are not filled");
        }


        TEST_METHOD(testChangingField)
        {

            Director director;
            IBuilder& builder = PlayerBuilder();
            shared_ptr<IPlayer> p = director.createPlayer(builder);

            auto lambda = [&p](int row, int colum) 
            {
            p->setField(row, colum);
            Assert::AreNotEqual(static_cast<char>(ShipInfo::EMPTY_CELL)
                , (p->getField(row, colum)), L"Cell not changed");
            };
           
            for (int i = 0; i < STANDART_FIELD; i++)
            {
                for (int j = 0; j < STANDART_FIELD; j++)
                {
                    lambda(i, j);
                }
            }
        }
    };
}
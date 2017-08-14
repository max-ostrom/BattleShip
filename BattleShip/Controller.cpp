#include "Controller.h"

#include <chrono>
#include <thread>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
using namespace std;
bool Controller::isKeyPressed(const int& key) const
{
	const unsigned int MSB = 0x8000;

	if (GetAsyncKeyState(key) & MSB)
	{
		return true;
	}

	return false;
}
void Controller::run()
{
		model_.get()->setStartTime(clock());
		bool turn = true;
		int coordAtack[2];
		bool hitting = false;
		string choose;

		while (!model_.get()->getUser().isEndOfGame() && !model_.get()->getComputer().isEndOfGame())
		{
			if (turn)
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 14,14 });
				cout << "At first write letter then number without Enter : " << endl;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 14,15 });
				cout << "Enter - pause, any key to atack ship";
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 14,16 });


				switch (_getch())
				{

				case VK_RETURN: // enter
								//pause
				{
					clock_t startPause = clock();
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 17,17 });
					cout << "Pause, press space to continue, seconds :\t";
					while (!isKeyPressed(32))
					{
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 60,17 });
						cout << static_cast<int>(clock() - startPause) / CLOCKS_PER_SEC;
						Sleep(1000);
					}
					break;
				}
				default:
				{
					do
					{
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 14,16 });
						cin >> choose;
						coordAtack[0] = choose[0] % static_cast<int>('a');
						cout << endl;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 14,17 });
						cin >> coordAtack[1];

					} while (coordAtack[0]<0 || coordAtack[0]>FIELDSIZE || coordAtack[1]<0 || coordAtack[1]>FIELDSIZE);
					break;
				}
				}



				model_.get()->getUser().setEnemyField(coordAtack[0], coordAtack[1], model_.get()->getComputer());
				model_.get()->getComputer().setField(coordAtack[0], coordAtack[1]);


				// player shot
				if (model_.get()->getComputer().getField(coordAtack[0], coordAtack[1]) == '#')
				{

					for each (auto var in model_.get()->getComputer().YourShips)
					{
						for (int i = 0; i < var->getShipSize(); i++)
						{
							if (var->getX().get()[i] == coordAtack[0] && var->getY().get()[i] == coordAtack[1])
							{
								model_.get()->getComputer().isShipAlive(var.get());
							}
						}


					}
				}
				else
				{
						turn = false;
				}
			}


				// computer shot
			else
			{
				if (!hitting)
				{
					do {
						coordAtack[0] = rand() % FIELDSIZE;
						coordAtack[1] = rand() % FIELDSIZE;
					} while (model_.get()->getUser().getEnemyField(coordAtack[0], coordAtack[1]) != ' ');
				}
				if (model_.get()->getUser().getEnemyField(coordAtack[0], coordAtack[1]) == ' ')
				{
					model_.get()->getUser().setField(coordAtack[0], coordAtack[1]);
					if (model_.get()->getUser().getField(coordAtack[0], coordAtack[1]) == '#')
					{
						for each (auto var in model_.get()->getUser().YourShips)
						{
							for (int i = 0; i < var->getShipSize(); i++)
							{
								if (var->getX().get()[i] == coordAtack[0] && var->getY().get()[i] == coordAtack[1])
								{
									model_.get()->getUser().isShipAlive(var.get());
								}
							}

						}

					}
					else
					{
						turn = true;
					}
				}

			}
				
		}
}
	


Controller::Controller(GameModel* model) : model_(model)
{
	
}

Controller::~Controller()
{
}

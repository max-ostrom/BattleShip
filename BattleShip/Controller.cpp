#include "Controller.h"

#include <chrono>
#include <thread>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <algorithm>

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
	time_.setStartTime(clock());
	bool turn = true;
	int coordAtack[2];
	bool hitting = false;
	string choose;

	while (!model_.getUser().isEndOfGame() && !model_.getComputer().isEndOfGame())
	{
		if (model_.getUser().isEndOfGame() || model_.getComputer().isEndOfGame())
		{
			_getch();
			exit(0); // end of game
		}
		if (turn)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 14,14 });
			cout << "At first write letter then number without Enter : " << endl;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 14,15 });
			cout << "Enter - pause, any key to atack ship";
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 14,16 });


			switch (_getch())
			{

			case VK_RETURN : 
			// enter - pause
			{
				clock_t startPause = clock();
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 17, 17 });
				cout << "Pause, press space to continue, seconds :\t";
				while (!isKeyPressed (VK_SPACE))
				{
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 60, 17 });
					cout << static_cast<int>(clock() - startPause) / CLOCKS_PER_SEC;
					Sleep(1000);
				}
				break;
			}
			default :
			{
				do
				{
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 14, 16 });
					cin >> choose;
					coordAtack[0] = choose[0] % static_cast<int>('a');
					cout << endl;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 14, 17 });
					cin >> coordAtack[1];

				} while (coordAtack[0]<0 || coordAtack[0]>FIELD_SIZE || coordAtack[1]<0 || coordAtack[1]>FIELD_SIZE);
				break;
			}
			}



			model_.getUser().setEnemyField(coordAtack[0], coordAtack[1], model_.getComputer());
			model_.getComputer().setField(coordAtack[0], coordAtack[1]);


			// Player_ shot
			if (model_.getComputer().getField(coordAtack[0], coordAtack[1]) == '#')
			{
				for_each(
					model_.getComputer().getShips().begin(),
					model_.getComputer().getShips().end(),
					[this, &coordAtack](std::shared_ptr<Ship> Ship_) mutable// Lambda expression
				{
					for (int i = 0; i < Ship_->getShipSize(); i++)
					{
						if (Ship_->getX().get()[i] == coordAtack[0] && Ship_->getY().get()[i] == coordAtack[1])
						{
							model_.getComputer().isShipAlive(Ship_);
						}
					}
				});
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
					coordAtack[0] = rand() % FIELD_SIZE;
					coordAtack[1] = rand() % FIELD_SIZE;
				} while (model_.getUser().getEnemyField(coordAtack[0], coordAtack[1]) != ' ');
			}
			if (model_.getUser().getEnemyField(coordAtack[0], coordAtack[1]) == ' ')
			{
				model_.getUser().setField(coordAtack[0], coordAtack[1]);
				if (model_.getUser().getField(coordAtack[0], coordAtack[1]) == '#')
				{
					for_each(
						model_.getUser().getShips().begin(),
						model_.getUser().getShips().end(),
						[this, &coordAtack](std::shared_ptr<Ship> Ship_) mutable// Lambda expression
					{
						for (int i = 0; i < Ship_->getShipSize(); i++)
						{
							if (Ship_->getX().get()[i] == coordAtack[0] && Ship_->getY().get()[i] == coordAtack[1])
							{
								model_.getUser().isShipAlive(Ship_);
							}
						}
					});

				}
				else
				{
					turn = true;
				}
			}

		}

	}
}
Controller::Controller(IGame& model, ITime& time) : model_(model), time_(time)
{

}
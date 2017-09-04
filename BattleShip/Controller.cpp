#include "Controller.h"

#include <chrono>
#include <thread>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <algorithm>

using namespace std;

void Controller::userAtack()
{
	input();


	Model_.getUser().setEnemyField(coordAtack[0], coordAtack[1], Model_.getComputer());
	Model_.getComputer().setField(coordAtack[0], coordAtack[1]);


	// Player_ shot
	if (Model_.getComputer().getField(coordAtack[0], coordAtack[1]) == '#')
	{
		for_each(
			Model_.getComputer().getShips().begin(),
			Model_.getComputer().getShips().end(),
			[this](std::shared_ptr<Ship> Ship_) mutable// Lambda expression
		{
			for (int i = 0; i < Ship_->getShipSize(); i++)
			{
				if (Ship_->getX().get()[i] == coordAtack[0] && Ship_->getY().get()[i] == coordAtack[1])
				{
					Model_.getComputer().isShipAlive(Ship_);
				}
			}
		});
	}
	else
	{
		turn = false;
	}
}

void Controller::computerAtack()
{
	
	do {
		coordAtack[0] = rand() % STANDART_FIELD;
		coordAtack[1] = rand() % STANDART_FIELD;
	} while (Model_.getUser().getEnemyField(coordAtack[0], coordAtack[1]) != ' ');
	
	if (Model_.getUser().getEnemyField(coordAtack[0], coordAtack[1]) == ' ')
	{
		Model_.getUser().setField(coordAtack[0], coordAtack[1]);
		if (Model_.getUser().getField(coordAtack[0], coordAtack[1]) == '#')
		{
			for_each(
				Model_.getUser().getShips().begin(),
				Model_.getUser().getShips().end(),
				[this](std::shared_ptr<Ship> Ship_) mutable// Lambda expression
			{
				for (int i = 0; i < Ship_->getShipSize(); i++)
				{
					if (Ship_->getX().get()[i] == coordAtack[0] && Ship_->getY().get()[i] == coordAtack[1])
					{
						Model_.getUser().isShipAlive(Ship_);
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

void Controller::input()
{

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 14,14 });
	cout << "At first write letter then number without Enter : " << endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 14,15 });
	cout << "Enter - pause, any key to atack ship";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 14,16 });


	switch (_getch())
	{

	case VK_RETURN:
		// enter - pause
	{
		clock_t startPause = clock();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 17, 17 });
		cout << "Pause, press space to continue, seconds :\t";
		while (!isKeyPressed(VK_SPACE))
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 60, 17 });
			cout << static_cast<int>(clock() - startPause) / CLOCKS_PER_SEC;
			Sleep(1000);
		}
		break;
	}
	default:
	{
		do
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 14, 16 });
			string choose;
			cin >> choose;
			coordAtack[0] = choose[0] % static_cast<int>('a');
			cout << endl;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 14, 17 });
			cin >> coordAtack[1];

		} while (coordAtack[0]<0 || coordAtack[0]>STANDART_FIELD || coordAtack[1]<0 || coordAtack[1]>STANDART_FIELD);
		break;
	}
	}

}

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
	Time_.setStartTime(clock());
	
	while (!Model_.getUser().isEndOfGame() && !Model_.getComputer().isEndOfGame())
	{
		if (Model_.getUser().isEndOfGame() || Model_.getComputer().isEndOfGame())
		{
			_getch();
			exit(0); // end of game
		}
		if (turn)
		{
			userAtack();
		}
		// computer shot
		else
		{
			computerAtack();
		}
	}
}
Controller::Controller(IGame& model, ITime& time) : Model_(model), Time_(time)
{

}
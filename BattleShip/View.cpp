#include <chrono>
#include <thread>
#include <string>
#include <algorithm>

#include <Windows.h>
#include <conio.h>

#include "View.h"

View::View(GameModel& model) :model_(model)
{
	
}


void View::update() const
{
	if (model_.getUser().isEndOfGame() || model_.getComputer().isEndOfGame())
	{
		endOfGame();
	}
	else
	{
		system("cls");
		char alf[] = { "ABCDEFGHIJ" };
		char numbers[12] = { " 0123456789" };


		cout << "Your ships" << endl << numbers << endl;


		for (int i = 0; i < FIELDSIZE; i++)
		{
			cout << alf[i];
			for (int j = 0; j < FIELDSIZE; j++)
			{
				cout << model_.getUser().getField(i, j);
			}
			cout << "|" << endl;
		}


		cout << endl << "Computer ships" << endl << numbers << endl;
		for (int i = 0; i < FIELDSIZE; i++)
		{
			cout << alf[i];
			for (int j = 0; j < FIELDSIZE; j++)
			{
				if (model_.getComputer().getField(i, j) == 'X')
					cout << " ";
				else
					cout << model_.getComputer().getField(i, j);
			}
			cout << "|" << endl;
		}

	}
}
void View::endOfGame() const
{
	this_thread::sleep_for(chrono::seconds(2));

	int yourAliveShips = 0;
	//players alive ships
	for_each(model_.getUser().getShips().begin(), model_.getUser().getShips().end(),
		[yourAliveShips](std::shared_ptr<Ship> item) mutable// Lambda expression
	{
		if (item->isAlive())
		{
			yourAliveShips++;
		}
	});


	int computerAliveShips = 0;
	//computers alive ships
	for_each(model_.getComputer().getShips().begin(), model_.getComputer().getShips().end(),
		[computerAliveShips](std::shared_ptr<Ship> item) mutable// Lambda expression
	{
		if (item->isAlive())
		{
			computerAliveShips++;
		}
	});

	system("cls");
	char alf[11] = { "ABCDEFGHIJ" };
	char numbers[12] = { "0123456789" };
	cout << "Computer ships" << endl;
	cout << numbers << endl;


	//print computer ships
	for (int i = 0; i < FIELDSIZE; i++)
	{
		cout << alf[i];
		for (int j = 0; j < FIELDSIZE; j++)
		{
			cout << model_.getComputer().getField(i, j);
		}
		cout << endl;

	}


	// time and ships count
	cout << "Time: "
		<< static_cast<int>((clock() - model_.getStartTime()) / CLOCKS_PER_SEC) / 60
		<< ":"
		<< static_cast<int>((clock() - model_.getStartTime()) / CLOCKS_PER_SEC) % 60
		<< "Your Ships : " << yourAliveShips << endl
		<< "Computer Ships : " << computerAliveShips << endl;
}


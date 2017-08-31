#include <chrono>
#include <thread>
#include <string>
#include <algorithm>

#include <Windows.h>
#include <conio.h>

#include "View.h"

View::View(IPlayer& you , IPlayer& computer) : GameModel(you,computer)
{
	update();
}
void View::update() const
{
	if (getUser().isEndOfGame() || getComputer().isEndOfGame())
	{
		endOfGame();
	}
	else
	{
		system("cls");
		char alf[] = { "ABCDEFGHIJ" };
		char numbers[12] = { " 0123456789" };


		cout << "Your ships" << endl << numbers << endl;


		for (int i = 0; i < FIELD_SIZE; i++)
		{
			cout << alf[i];
			for (int j = 0; j < FIELD_SIZE; j++)
			{
				cout << getUser().getField(i, j);
			}
			cout << "|" << endl;
		}


		cout << endl << "Computer ships" << endl << numbers << endl;
		for (int i = 0; i < FIELD_SIZE; i++)
		{
			cout << alf[i];
			for (int j = 0; j < FIELD_SIZE; j++)
			{
				if (getComputer().getField(i, j) == 'X')
					cout << " ";
				else
					cout << getComputer().getField(i, j);
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
	for_each(
		getUser().getShips().begin(), 
		getUser().getShips().end(),
		[yourAliveShips](const std::shared_ptr<Ship> Ship_) mutable// Lambda expression
	{
		if (Ship_->isAlive())
		{
			yourAliveShips++;
		}
	});


	int computerAliveShips = 0;
	//computers alive ships
	for_each(
		getComputer().getShips().begin(),
		getComputer().getShips().end(),
		[computerAliveShips](const std::shared_ptr<Ship> Ship_) mutable// Lambda expression
	{
		if (Ship_->isAlive())
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
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		cout << alf[i];
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			cout << getComputer().getField(i, j);
		}
		cout << endl;

	}


	// time and ships count
	cout << "Time: "
		<< static_cast<int>((clock() - getStartTime()) / CLOCKS_PER_SEC) / 60
		<< ":"




		<< static_cast<int>((clock() - getStartTime()) / CLOCKS_PER_SEC) % 60
		<< "Your Ships : " << yourAliveShips << endl
		<< "Computer Ships : " << computerAliveShips << endl;
}


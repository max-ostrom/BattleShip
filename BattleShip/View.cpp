#include <chrono>
#include <thread>
#include <string>
#include <algorithm>

#include <Windows.h>
#include <conio.h>

#include "View.h"

View::View(const IGame& game,const ITime& time) : game_(game), time_(time)
{
	update();
}
void View::update() const
{
	if (game_.getUser().isEndOfGame() || game_.getComputer().isEndOfGame())
	{
		endOfGame();
	}
	else
	{
		system("cls");
		char alf[] = { "ABCDEFGHIJ" };
		char numbers[12] = { " 0123456789" };


		cout << "Your ships" << endl << numbers << endl;


		for (int i = 0; i < STANDART_FIELD; i++)
		{
			cout << alf[i];
			for (int j = 0; j < STANDART_FIELD; j++)
			{
				cout << game_.getUser().getField(i, j);
			}
			cout << "|" << endl;
		}


		cout << endl << "Computer ships" << endl << numbers << endl;
		for (int i = 0; i < STANDART_FIELD; i++)
		{
			cout << alf[i];
			for (int j = 0; j < STANDART_FIELD; j++)
			{
				if (game_.getComputer().getField(i, j) == 'X')
					cout << " ";
				else
					cout << game_.getComputer().getField(i, j);
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
		game_.getUser().getShips().begin(),
		game_.getUser().getShips().end(),
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
		game_.getComputer().getShips().begin(),
		game_.getComputer().getShips().end(),
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
	for (int i = 0; i < STANDART_FIELD; i++)
	{
		cout << alf[i];
		for (int j = 0; j < STANDART_FIELD; j++)
		{
			cout << game_.getComputer().getField(i, j);
		}
		cout << endl;

	}


	// time and ships count
	cout << "Time: "
		<< static_cast<int>((clock() - time_.getStartTime()) / CLOCKS_PER_SEC) / 60
		<< ":"




		<< static_cast<int>((clock() - time_.getStartTime()) / CLOCKS_PER_SEC) % 60
		<< "Your Ships : " << yourAliveShips << endl
		<< "Computer Ships : " << computerAliveShips << endl;
}


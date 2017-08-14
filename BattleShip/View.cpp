#include <chrono>
#include <thread>
#include <string>

#include <Windows.h>
#include <conio.h>

#include "View.h"

View::View(GameModel* model) :model_(model)
{
	model->getComputer().addObserver(this);
	model->getUser().addObserver(this);
}


void View::update() const
{

	system("cls");
	char alf[11] = { "ABCDEFGHIJ" };
	char numbers[12] = { " 0123456789" };


	cout << "Your ships" << endl << numbers << endl;


	for (int i = 0; i < FIELDSIZE; i++)
	{
		cout << alf[i];
		for (int j = 0; j < FIELDSIZE; j++)
		{
			cout << model_.get()->getReadonlyUser().getField(i, j);
		}
		cout << "|" << endl;
	}


	cout << endl << "Computer ships" << endl << numbers << endl;
	for (int i = 0; i < FIELDSIZE; i++)
	{
		cout << alf[i];
		for (int j = 0; j < FIELDSIZE; j++)
		{
			if (model_.get()->getReadonlyComputer().getField(i, j) == 'X')
				cout << " ";
			else
				cout << model_.get()->getReadonlyComputer().getField(i, j);
		}
		cout << "|" << endl;
	}

	if (model_.get()->getReadonlyUser().isEndOfGame() || model_.get()->getReadonlyComputer().isEndOfGame())
	{
		endOfGame();
	}



}
void View::endOfGame() const
{
	this_thread::sleep_for(chrono::seconds(2));

	int yourAliveShips = 0;
	//players alive ships
	for each (auto item in model_.get()->getReadonlyUser().YourShips)
	{
		if (item->isAlive())
		{
			yourAliveShips++;
		}
	}


	int computerAliveShips = 0;
	//computers alive ships
	for each (auto item in model_.get()->getReadonlyComputer().YourShips)
	{
		if (item->isAlive())
		{
			computerAliveShips++;
		}
	}


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
			cout << model_.get()->getReadonlyComputer().getField(i, j);
		}
		cout << endl;

	}


	// time and ships count
	cout << "Time: "
		<< static_cast<int>((clock() - model_.get()->getStartTime()) / CLOCKS_PER_SEC) / 60
		<< ":"
		<< static_cast<int>((clock() - model_.get()->getStartTime()) / CLOCKS_PER_SEC) % 60
		<< "Your Ships : " << yourAliveShips << endl
		<< "Computer Ships : " << computerAliveShips << endl;
}

View::~View()
{
}

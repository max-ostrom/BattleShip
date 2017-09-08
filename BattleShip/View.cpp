#include <chrono>
#include <thread>
#include <string>
#include <algorithm>

#include <Windows.h>
#include <conio.h>

#include "View.h"

View::View(const IViewModel& game) : Model_(game)
{
	setStartTime(clock());
	update();
}
void View::update() const
{
	
	system("cls");
	char alf[] = { "ABCDEFGHIJ" };
	char numbers[] = { " 0123456789" };


	cout << "Computer ships" << endl << numbers << endl;


	for (int i = 0; i < STANDART_FIELD; i++)
	{
		cout << alf[i];
		for (int j = 0; j < STANDART_FIELD; j++)
		{
			cout << Model_.getUserField(i, j);
		}
		cout << "|" << endl;
	}


	cout << endl << "Your ships" << endl << numbers << endl;
	for (int i = 0; i < STANDART_FIELD; i++)
	{
		cout << alf[i];
		for (int j = 0; j < STANDART_FIELD; j++)
		{
			cout << Model_.getcomputerField(i, j);
		}
		cout << "|" << endl;
	}
	const int SECONDS_IN_MIN = 60;
	cout <<endl<< "Time: "
		<< static_cast<int>((clock() - getStartTime()) / CLOCKS_PER_SEC) / SECONDS_IN_MIN
		<< ":"
		<< static_cast<int>((clock() - getStartTime()) / CLOCKS_PER_SEC) % SECONDS_IN_MIN << endl;
}
void View::setStartTime(clock_t start)
{
	startGame_ = start;
}
const clock_t & View::getStartTime() const
{
	return startGame_;
}


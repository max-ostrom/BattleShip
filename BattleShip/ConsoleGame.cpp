#include "ConsoleGame.h"
#include "Constants.h"

#include <chrono>
#include <thread>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

using namespace std;

ConsoleGame::ConsoleGame()
{
}


void ConsoleGame::endOfGame(const clock_t& startGame) const
{
	this_thread::sleep_for(chrono::seconds(2));

	int yourAliveShips = 0;
	//players alive ships
	for each (auto item in this->You_.YourShips)
	{
		if (item->isAlive())
		{
			yourAliveShips++;
		}
	}


	int computerAliveShips = 0;
	//computers alive ships
	for each (auto item in Computer_.YourShips)
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
			cout << Computer_.getField(i, j);
		}
		cout << endl;

	}


	// time and ships count
	cout << "Time: "
		<< static_cast<int>((clock() - startGame) / CLOCKS_PER_SEC) / 60
		<< ":"
		<< static_cast<int>((clock() - startGame) / CLOCKS_PER_SEC) % 60
		<< "Your Ships : " << yourAliveShips << endl
		<< "Computer Ships : " << computerAliveShips << endl;
}

void ConsoleGame::reprintField() const
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
			cout << You_.getField(i, j);
		}
		cout << "|" << endl;
	}


	cout << endl << "Computer ships" << endl << numbers << endl;
	for (int i = 0; i < FIELDSIZE; i++)
	{
		cout << alf[i];
		for (int j = 0; j < FIELDSIZE; j++)
		{
			if (Computer_.getField(i, j) == 'X')
				cout << " ";
			else
				cout << Computer_.getField(i, j);
		}
		cout << "|" << endl;
	}


}
ConsoleGame::~ConsoleGame()
{
}

void ConsoleGame::run() 
{
	const clock_t startTime = clock();
	bool turn = true;
	int coordAtack[2];
	bool hitting = false;
	string choose;

	while (!You_.isEndOfGame() && !Computer_.isEndOfGame())
	{

		reprintField();

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

				} while (coordAtack[0]<0 || coordAtack[0]>10 || coordAtack[1]<0 || coordAtack[1]>10);
				break;
			}
			}



			You_.setEnemyField(coordAtack[0], coordAtack[1], Computer_);
			Computer_.setField(coordAtack[0], coordAtack[1]);


			// ход игрока
			if (Computer_.getField(coordAtack[0], coordAtack[1]) == '#')
			{
				if (Computer_.getField(coordAtack[0], coordAtack[1]) == '#')
				{
					for each (auto var in Computer_.YourShips)
					{
						for (int i = 0; i < var->getShipSize(); i++)
						{
							if (var->getX()[i] == coordAtack[0] && var->getY()[i] == coordAtack[1])
							{
								Computer_.isShipAlive(var);
							}
						}


					}
				}
				else
				{
					turn = false;
				}
			}


			// ход компьютера
			else
			{
				if (!hitting)
				{
					do {
						coordAtack[0] = rand() % 10;
						coordAtack[1] = rand() % 10;
					} while (You_.getEnemyField(coordAtack[0], coordAtack[1]) != ' ');
				}
				if (You_.getEnemyField(coordAtack[0], coordAtack[1]) == ' ')
				{
					You_.setField(coordAtack[0], coordAtack[1]);
					if (You_.getField(coordAtack[0], coordAtack[1]) == '#')
					{
						for each (auto var in You_.YourShips)
						{
							for (int i = 0; i < var->getShipSize(); i++)
							{
								if (var->getX()[i] == coordAtack[0] && var->getY()[i] == coordAtack[1])
								{
									You_.isShipAlive(var);
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
			endOfGame(startTime);
		}
	}
}
bool ConsoleGame::isKeyPressed(const int& key) const
{
	const unsigned int MSB = 0x8000;

	if (GetAsyncKeyState(key) && MSB)
	{
		return true;
	}

	return false;
}
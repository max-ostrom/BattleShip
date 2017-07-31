#include "Game.h"
#include <Windows.h>
#include <thread>
#include<mutex>
#include <chrono>
#include <string>
Game::Game()//главный цикл игры 
{
	//thread print(&Game::Reprintfield, *this);
	//print.detach();
	bool turn= true;
	int coordAtack[2];
	string choose;
	while (!EndOfComputerGame() || !EndOfYourGame())
	{
		
		system("cls");
		Reprintfield();
		if (turn)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 14,14 });
			
			cin >> coordAtack[0];
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 14,15 });
			cin >> coordAtack[1];
			you.SetEnemyField(coordAtack[0], coordAtack[1],computer);
			computer.SetField(coordAtack[0], coordAtack[1]);
			if (computer.GetField(coordAtack[0], coordAtack[1]) == '#')
			{
			}
			else
			{
				turn = false;
			}
		}
		else
		{
			coordAtack[0] = rand() % 10;
			coordAtack[1] = rand() % 10;
			if (you.GetEnemyField(coordAtack[0], coordAtack[1]) == ' ')
			{
				you.SetField(coordAtack[0], coordAtack[1]);
				if (you.GetField(coordAtack[0], coordAtack[1]) == '#')
				{
					
					for each (auto item in you.YourShips)
					{
						for (int i = 0; i < item.GetShipSize(); i++)
						{
							if (item.GetY()[i] == coordAtack[0] && item.GetX()[i] == coordAtack[1])
							{
								NearCell(item);
								break;
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


Game::~Game()
{
}

void Game::Reprintfield() // поток перерисовывающий поля
{
	
		
	
		system("cls");
		char alf[11] = { "ABCDEFGHIJ" };
	char numbers[12] = { " 1234567890" };
	cout << numbers << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << alf[i];
		for (int j = 0; j < 10; j++)
		{
			cout << you.GetField(i, j);
		}
		cout << endl;
	}
	cout << numbers << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << alf[i];
		for (int j = 0; j < 10; j++)
		{
			cout << you.GetEnemyField(i, j);
		}
		cout << endl;
	}
	cout << numbers << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << alf[i];
		for (int j = 0; j < 10; j++)
		{
			cout << computer.GetField(i, j);
		}
		cout << endl;
	
}
}

bool Game::EndOfYourGame()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (you.GetField(i,j)=='X')
				return false;
			
		}
	}
	return true;
}

bool Game::EndOfComputerGame()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (computer.GetField(i, j) == 'X')
				return false;

		}
	}
	return true;
	return false;
}

void Game::NearCell(Ship &s)
{
	for (int i = 0; i < s.GetShipSize(); i++)
	{	
		if (you.GetField(s.GetX()[i], s.GetY()[i]) == 'X')
		{
			you.SetField(s.GetX()[i], s.GetY()[i]);
		}
	}
}

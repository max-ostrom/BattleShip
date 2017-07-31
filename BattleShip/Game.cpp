	#include "Game.h"
	#include <Windows.h>
	#include <thread>
	#include<mutex>
	#include <chrono>
	#include <algorithm>
	#include <string>
	#include <conio.h>
	bool Game::IsKeyPressed(int key)
{
	const unsigned int MSB = 0x8000;
	if (GetAsyncKeyState(key) && MSB)
	{
		return true;
	}
	return false;
}
	Game::Game()//главный цикл игры 
	{
		clock_t start = clock();
		bool turn = true;
		int coordAtack[2];
		bool hitting = false;
		//thread timerThread(&Game::Timer, *this);
		//timerThread.detach();
		//	thread checkDestroyShips(&Game::NearCell, *this);
		while (!EndOfComputerGame() && !EndOfYourGame())
		{

			system("cls");
			Reprintfield();
			if (turn)
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 14,14 });
				cout << "At first write letter then number without Enter : "<<endl;
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
					while (!IsKeyPressed(32))
					{
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 60,17 });
						cout << static_cast<int>(clock() - startPause) / CLOCKS_PER_SEC;
						Sleep(1000);
					}
					break;
				}
				case 32:
					
				default:
					switch (_getch())
					{
					case 97: //a
					case 65: //A
					{
						cout << static_cast<char>(65);
						coordAtack[0] = 0;
						break; }
					case 98: //b
					case 66: //B
					{	cout << static_cast<char>(66);
					coordAtack[0] = 1;
					break;
					}
					case 99: //c
					case 67: //C
					{
						cout << static_cast<char>(67);
						coordAtack[0] = 2;
						break;
					}
					case 100: //d
					case 68: //D
					{
						cout << static_cast<char>(68);
						coordAtack[0] = 3;
						break;
					}
					case 101: //e
					case 69: //E
					{
						cout << static_cast<char>(69);
						coordAtack[0] = 4;
						break;
					}
					case 102: //f
					case 70: // F
					{
						cout << static_cast<char>(70);
						coordAtack[0] = 5;
						break;
					}
					case 103: // g
					case 71: //G
					{
						cout << static_cast<char>(71);
						coordAtack[0] = 6;
						break;
					}
					case 104: //h
					case 72: //H
					{
						cout << static_cast<char>(72);
						coordAtack[0] = 7;
						break;
					}
					case 105: //i
					case 73: //I
					{
						cout << static_cast<char>(73);
						coordAtack[0] = 8;
						break;
					}
					case 106: //j
					case 74: //J
					{
						cout << static_cast<char>(74);
						coordAtack[0] = 9;
						break;
					}
					default:
						coordAtack[0] = 0;
						break;
					}
					switch (_getch())
					{
					case 49:
					{	cout << static_cast<char>(49);
					coordAtack[1] = 0;
					break;
					}
					case 50:
					{
						cout << static_cast<char>(50);
						coordAtack[1] = 1;
						break;
					}
					case 51:
					{
						cout << static_cast<char>(51);
						coordAtack[1] = 2;
						break;
					}
					case 52:
					{	cout << static_cast<char>(52);
					coordAtack[1] = 3;
					break;
					}
					case 53:
					{
						cout << static_cast<char>(53);
						coordAtack[1] = 4;
						break;
					}
					case 54:
					{
						cout << static_cast<char>(54);
						coordAtack[1] = 5;
						break;
					}
					case 55:
					{
						cout << static_cast<char>(55);
						coordAtack[1] = 6;
						break;
					}
					case 56:
					{
						cout << static_cast<char>(56);
						coordAtack[1] = 7;
						break;
					}
					case 57:
					{
						cout << static_cast<char>(57);
						coordAtack[1] = 8;
						break;
					}
					case 48:
					{
						cout << static_cast<char>(48);
						coordAtack[1] = 9;
						break;
					}
					default: {
						coordAtack[1] = 0;
						break; }
					}
				}
				
				//		coordAtack[0] = 0;
					//	coordAtack[1] = 0;
				You_.SetEnemyField(coordAtack[0], coordAtack[1], Computer_);
				Computer_.SetField(coordAtack[0], coordAtack[1]);
				if (Computer_.GetField(coordAtack[0], coordAtack[1]) == '#')
				{
					if (Computer_.GetField(coordAtack[0], coordAtack[1]) == '#')
					{
						for each (auto var in Computer_.YourShips)
						{
							for (int i = 0; i < var->GetShipSize(); i++)
							{
								if (var->GetX()[i] == coordAtack[0] && var->GetY()[i] == coordAtack[1])
								{
									//NearCell(var,coordAtack[0],coordAtack[1]);
									FillNearestCell(var, Computer_);
								}
							}


						}
					}
					else
					{
						turn = false;
					}
				}
				else
				{
					if (!hitting)
					{
						do {
							coordAtack[0] = rand() % 10;
							coordAtack[1] = rand() % 10;
						} while (You_.GetEnemyField(coordAtack[0], coordAtack[1]) != ' ');
					}
					if (You_.GetEnemyField(coordAtack[0], coordAtack[1]) == ' ')
					{
						You_.SetField(coordAtack[0], coordAtack[1]);
						if (You_.GetField(coordAtack[0], coordAtack[1]) == '#')
						{
							for each (auto var in You_.YourShips)
							{
								for (int i = 0; i < var->GetShipSize(); i++)
								{
									if (var->GetX()[i] == coordAtack[0] && var->GetY()[i] == coordAtack[1])
									{
										//NearCell(var,coordAtack[0],coordAtack[1]);
										FillNearestCell(var, You_);
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
			this_thread::sleep_for(chrono::seconds(2));
			int yourAliveShips = 0;
			for each (auto item in You_.YourShips)
			{
				if (item->IsAlive())
				{
					yourAliveShips++;
				}
			}
			int computerAliveShips = 0;
			for each (auto item in Computer_.YourShips)
			{
				if (item->IsAlive())
				{
					computerAliveShips++;
				}
			}
			system("cls");
			char alf[11] = { "ABCDEFGHIJ" };
			char numbers[12] = { " 1234567890" };
			cout << "Computer ships"<<endl;
			cout << numbers;
			for (int i = 0; i < 10; i++)
			{
				cout << alf[i];
				for (int j = 0; j < 10; j++)
				{
					cout << Computer_.GetField(i, j);
				}
				cout << endl;

			}
			cout << "Time: " << static_cast<int>((clock()-start) / CLOCKS_PER_SEC) / 60<< ":"<< static_cast<int>((clock() - start) / CLOCKS_PER_SEC) %60 << "Your Ships : " << yourAliveShips << "Computer Ships : " << computerAliveShips;
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
				cout << You_.GetField(i, j);
			}
			cout << endl;
		}
		cout << numbers << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << alf[i];
			for (int j = 0; j < 10; j++)
			{
				if (Computer_.GetField(i, j) == 'X')
					cout << " ";
				else
					cout << Computer_.GetField(i, j);
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
				if (You_.GetField(i,j)=='X')
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
				if (Computer_.GetField(i, j) == 'X')
					return false;

			}
		}
		return true;
		return false;
	}
	//void Game::NearCell(Ship* s,int x, int y)
	//{
	//	bool isDestroy = true;
	//	for (int i = 0; i < s->GetShipSize(); i++)
	//	{
	//		if (You_.GetField(s->GetX()[i], s->GetY()[i]) == 'X')
	//			isDestroy = false;
	//	}
	//	if (isDestroy)
	//	{
	//		//FillNearestCell(s);
	//	}
	//	else 
	//	{
	//		if (s->GetShipSize() == 2)
	//		{
	//			if (x == 0 && s->GetY()[0] == 0)
	//			{
	//				if(You_.GetField(s->GetX()[0] + 1, s->GetY()[0]) == ' ')
	//					You_.SetField(s->GetX()[0] + 1, s->GetY()[0] );
	//				else if (You_.GetField(s->GetX()[0], s->GetY()[0] + 1) == ' ')
	//					You_.SetField(s->GetX()[0] , s->GetY()[0] + 1);
	//			}
	//			else if (x == 9 && s->GetY()[0] == 0)
	//			{
	//				if (You_.GetField(x - 1, s->GetY()[0]) == ' ')
	//					You_.SetField(x - 1, s->GetY()[0]);
	//				else if (You_.GetField(x, s->GetY()[0] + 1) == ' ')
	//					You_.SetField(x, s->GetY()[0] + 1);
	//			}
	//			else if (x == 0 && s->GetY()[1] == 9)
	//			{
	//				if (You_.GetField(x + 1, s->GetY()[0]) == ' ')
	//					You_.SetField(x + 1, s->GetY()[0]);
	//				else if (You_.GetField(x, s->GetY()[0] - 1) == ' ')
	//					You_.SetField(x, s->GetY()[0] - 1);
	//			}
	//			else if (x == 9 && s->GetY()[1] == 9)
	//			{
	//				if (You_.GetField(x - 1, s->GetY()[0]) == ' ')
	//					You_.SetField(x - 1, s->GetY()[0]);
	//				else if (You_.GetField(x, s->GetY()[0] - 1) == ' ')
	//					You_.SetField(x, s->GetY()[0] - 1);
	//			}
	//			else if (x == 0)
	//			{
	//				if (You_.GetField(x + 1, s->GetY()[0]) == ' ')
	//					You_.SetField(x + 1, s->GetY()[0]);
	//				else if (You_.GetField(x - 1, s->GetY()[0]) == ' ')
	//					You_.SetField(x - 1, s->GetY()[0]);
	//				else if (You_.GetField(x, s->GetY()[0] + 1) == ' ')
	//					You_.SetField(x, s->GetY()[0] + 1);
	//			}
	//			else if (x == 9)
	//			{
	//				if (You_.GetField(x + 1, s->GetY()[0]) == ' ')
	//					You_.SetField(x + 1, s->GetY()[0]);
	//				else if (You_.GetField(x - 1, s->GetY()[0]) == ' ')
	//					You_.SetField(x - 1, s->GetY()[0]);
	//				else if (You_.GetField(x, s->GetY()[0] - 1) == ' ')
	//					You_.SetField(x, s->GetY()[0] - 1);
	//			}
	//			else if (x == 9)
	//			{
	//				if (You_.GetField(x - 1, s->GetY()[0]) == ' ')
	//					You_.SetField(x - 1, s->GetY()[0]);
	//				else if (You_.GetField(x, s->GetY()[0] - 1) == ' ')
	//					You_.SetField(x, s->GetY()[0] - 1);
	//				else if (You_.GetField(x, s->GetY()[0] + 1) == ' ')
	//					You_.SetField(x, s->GetY()[0] + 1);
	//			}
	//			else if (x == 0)
	//			{
	//				if (You_.GetField(x + 1, s->GetY()[0]) == ' ')
	//					You_.SetField(x + 1, s->GetY()[0]);
	//				else if (You_.GetField(x, s->GetY()[0] - 1) == ' ')
	//					You_.SetField(x, s->GetY()[0] - 1);
	//				else if(You_.GetField(x, s->GetY()[0] + 1) == ' ')
	//					You_.SetField(x, s->GetY()[0] + 1);
	//			}
	//			else
	//			{
	//				if (You_.GetField(x - 1, s->GetY()[0]) == ' ')
	//					You_.SetField(x - 1, s->GetY()[0]);
	//				else if (You_.GetField(x + 1, s->GetY()[0] ) == ' ')
	//					You_.SetField(x + 1, y);
	//				else if (You_.GetField(x, y) == ' ')
	//					You_.SetField(x, y - 1);
	//				else if(You_.GetField(x, y +1 ) == ' ')
	//					You_.SetField(x, y + 1);
	//			}
	//		}
	//	
	//	}
	//}
	// WARNING 
	// Апасность лучшее не залазить 
	// не влезай убьёт
	void Game::FillNearestCell(Ship* item, Player& p)
	{	// забиваем соседние клетки однопалубного корабля
		if (item->GetShipSize() == 1)
		{
			item->Destroy();
			if (item->GetX()[0] == 0 && item->GetY()[0] == 0)
			{
				for (int i = 0; i < 2; i++)
				{
					for (int j = 0; j < 2; j++)
					{
						p.SetField(i, j);
					}
				}
			}
			else if (item->GetX()[0] == 9 && item->GetY()[0] == 0)
			{
				for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 1; i++)
				{
					for (int j = item->GetY()[0]; j < item->GetY()[0] + 2; j++)
					{
						p.SetField(i, j);
					}
				}
			}
			else if (item->GetX()[0] == 0 && item->GetY()[0] == 9)
			{
				for (int i = item->GetX()[0]; i < item->GetX()[0] + 2; i++)
				{
					for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 1; j++)
					{
						p.SetField(i, j);
					}
				}
			}
			else if (item->GetX()[0] == 9 && item->GetY()[0] == 9)
			{
				for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 1; i++)
				{
					for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 1; j++)
					{
						p.SetField(i, j);
					}
				}
			}
			else if (item->GetY()[0] == 0)
			{
				for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 2; i++)
				{
					for (int j = item->GetY()[0]; j < item->GetY()[0] + 2; j++)
					{
						p.SetField(i, j);
					}
				}
			}
			else if (item->GetY()[0] == 9)
			{
				for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 2; i++)
				{
					for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 1; j++)
					{
						p.SetField(i, j);
					}
				}
			}
			else if (item->GetX()[0] == 9)
			{
				for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 1; i++)
				{
					for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 2; j++)
					{
						p.SetField(i, j);
					}
				}
			}
			else if (item->GetX()[0] == 9)
			{
				for (int i = item->GetX()[0]; i < item->GetX()[0] + 2; i++)
				{
					for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 2; j++)
					{
						p.SetField(i, j);
					}
				}
			}
			else
				for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 2; i++)
				{
					for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 2; j++)
					{
						p.SetField(i, j);
					}
				}



		}
		// забиваем соседние клетки двухпалубного корабля
		if (item->GetShipSize() == 2 
			&& p.GetField(item->GetX()[0], item->GetY()[0]) == '#' 
			&& p.GetField(item->GetX()[1], item->GetY()[1]) == '#')
		{

			item->Destroy();
			//угол
			if (item->GetX()[0] == 0 && item->GetY()[0] == 0)
			{
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 2; j++)
					{
						if (item->GetX()[0] - item->GetX()[1] != 0)
						{
							p.SetField(i, j);
						}
						else
						{
							p.SetField(j, i);
						}
					}
				}
			}
			//угол
			else if (item->GetX()[1] == 9 && item->GetY()[0] == 0)
			{
				if (item->GetX()[0] - item->GetX()[1] != 0)
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 2; i++)
					{
						for (int j = item->GetY()[0]; j < item->GetY()[0] + 2; j++)
						{

							p.SetField(i, j);

						}
					}
				}
				else 
				{
					for (int i = item->GetX()[0] ; i < item->GetX()[0] + 2; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 2; j++)
						{

							p.SetField(i, j);

						}
					}
				}
			}
			//угол
			else if (item->GetX()[0] == 0 && item->GetY()[1] == 9)
			{
				if (item->GetX()[0] - item->GetX()[1] != 0)
				{
					for (int i = item->GetX()[0]; i < item->GetX()[0] + 3; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 1; j++)
						{

							p.SetField(i, j);

						}
					}
				}
				else 
				{
					for (int i = item->GetX()[0]-1; i < item->GetX()[0] + 1; i++)
					{
						for (int j = item->GetY()[0] ; j < item->GetY()[0] + 3; j++)
						{

							p.SetField(i, j);

						}
					}
				}
			}
			//угол
			else if (item->GetX()[1] == 9 && item->GetY()[1] == 9)
			{
				for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 2; i++)
				{
					for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 1; j++)
					{
						if (item->GetX()[0] - item->GetX()[1] != 0)
						{
							p.SetField(i, j);
						}
						else
						{
							p.SetField(j, i);
						}
					}
				}
			}
			//стенка
			else if (item->GetY()[0] == 0)
			{
				if (item->GetX()[0] - item->GetX()[1] != 0)
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 3; i++)
					{
						for (int j = item->GetY()[0]; j < item->GetY()[0] + 2; j++)
						{

							p.SetField(i, j);

						}
					}
				}
				else
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 2; i++)
					{
						for (int j = item->GetY()[0]; j < item->GetY()[0] + 3; j++)
						{
							p.SetField(i, j);

						}
					}
				}
				
			}
			//стенка
			else if (item->GetY()[1] == 9)
			{
				if (item->GetX()[0] - item->GetX()[1] != 0)
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 3; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 1; j++)
						{

							p.SetField(i, j);

						}
					}
				}
				else 
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 2; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 2; j++)
						{

							p.SetField(i, j);

						}
					}
				}
			}
			//стенка
			else if (item->GetX()[1] == 9)
			{
				if (item->GetX()[0] - item->GetX()[1] != 0)
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 2; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 2; j++)
						{

							p.SetField(i, j);

						}
					}
				}
				else 
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 2; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 3; j++)
						{

							p.SetField(i, j);

						}
					}
				}
			}
			//стенка
			else if (item->GetX()[0] == 0)
			{
				if (item->GetX()[0] - item->GetX()[1] != 0)
				{
					for (int i = item->GetX()[0] ; i < item->GetX()[0] + 3; i++)
					{
						for (int j = item->GetY()[0]-1 ; j < item->GetY()[0] + 2; j++)
						{

							p.SetField(i, j);

						}
					}
				}
				else 
				{
					for (int i = item->GetX()[0]   ; i < item->GetX()[0] + 2; i++)
					{
						for (int j = item->GetY()[0] -1 ; j < item->GetY()[0] + 3; j++)
						{
							p.SetField(i, j);

						}
					}
				}
			}
			else 
			{
				if (item->GetX()[0] - item->GetX()[1] != 0)
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 3; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 2; j++)
						{

							p.SetField(i, j);
						}
					}
				}
				else 
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 2; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 3; j++)
						{

							p.SetField(i, j);
						}
					}
				}
			}

		}
		// забиваем соседние клетки трёхпалубного корабля
		if (item->GetShipSize() == 3
			&& p.GetField(item->GetX()[0], item->GetY()[0]) == '#'
			&& p.GetField(item->GetX()[1], item->GetY()[1]) == '#'
			&& p.GetField(item->GetX()[2], item->GetY()[2]) == '#')
		{

			item->Destroy();
			if (item->GetX()[0] == 0 && item->GetY()[0] == 0)
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 2; j++)
					{
						if (item->GetX()[0] - item->GetX()[1] != 0)
						{
							p.SetField(i, j);
						}
						else
						{
							p.SetField(j, i);
						}
					}
				}
			}
			else if (item->GetX()[2] == 9 && item->GetY()[0] == 0)
			{
				if (item->GetX()[0] - item->GetX()[1] != 0)
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 3; i++)
					{
						for (int j = item->GetY()[0]; j < item->GetY()[0] + 2; j++)
						{

							p.SetField(i, j);

						}
					}
				}
				else 
				{
					for (int i = item->GetX()[0] ; i < item->GetX()[0] + 2; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 3; j++)
						{

							p.SetField(i, j);

						}
					}
				}
			}
			else if (item->GetX()[0] == 0 && item->GetY()[2] == 9)
			{
				if (item->GetX()[0] - item->GetX()[1] != 0)
				{
					for (int i = item->GetX()[0]; i < item->GetX()[0] + 4; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 1; j++)
						{

							p.SetField(i, j);

						}
					}
				}
				else 
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 1; i++)
					{
						for (int j = item->GetY()[0] ; j < item->GetY()[0] + 4; j++)
						{

							p.SetField(i, j);

						}
					}
				}
			}
			else if (item->GetX()[2] == 9 && item->GetY()[1] == 9)
			{
				for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 3; i++)
				{
					for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 1; j++)
					{
						if (item->GetX()[0] - item->GetX()[1] != 0)
						{
							p.SetField(i, j);
						}
						else
						{
							p.SetField(j, i);
						}
					}
				}
			}
			else if (item->GetY()[0] == 0)
			{
				if (item->GetX()[0] - item->GetX()[1] != 0)
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 4; i++)
					{
						for (int j = item->GetY()[0]; j < item->GetY()[0] + 2; j++)
						{

							p.SetField(i, j);

						}
					}
				}
				else
				{
					for (int i = item->GetX()[0]-1 ; i < item->GetX()[0] + 2; i++)
					{
						for (int j = item->GetY()[0] ; j < item->GetY()[0] + 4; j++)
						{

							p.SetField(i, j);

						}
					}
				}
			}
			else if (item->GetY()[2] == 9)
			{

				if (item->GetX()[0] - item->GetX()[1] != 0)
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 4; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 1; j++)
						{
							p.SetField(i, j);

						}
					}
				}
				else
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 2; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 3; j++)
						{

							p.SetField(i, j);

						}
					}
				}
			}
			else if (item->GetX()[2] == 9)
			{
				if (item->GetX()[0] - item->GetX()[1] != 0)
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 3; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 2; j++)
						{

							p.SetField(i, j);

						}
					}
				}
				else 
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 2; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 3; j++)
						{

							p.SetField(i, j);

						}
					}
				}
			}
			else if (item->GetX()[0] == 0)
			{
				if (item->GetX()[0] - item->GetX()[1] != 0)
				{
					for (int i = item->GetX()[0]; i < item->GetX()[0] + 4; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 2; j++)
						{

							p.SetField(i, j);

						}
					}
				}
				else
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 2; i++)
					{
						for (int j = item->GetY()[0] ; j < item->GetY()[0] + 4; j++)
						{

							p.SetField(i, j);

						}
					}
				}
			}
			else 
			{
				if (item->GetX()[0] - item->GetX()[1] != 0)
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 4; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 2; j++)
						{

							p.SetField(i, j);
						}

					}
				}
				else 
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 2; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 4; j++)
						{

							p.SetField(i, j);
						}

					}
				}
			}
		}
		
		// забиваем соседние клетки четырёхпалубного корабля
		if (item->GetShipSize() == 4
			&& p.GetField(item->GetX()[0], item->GetY()[0]) == '#'
			&& p.GetField(item->GetX()[1], item->GetY()[1]) == '#'
			&& p.GetField(item->GetX()[2], item->GetY()[2]) == '#'
			&& p.GetField(item->GetX()[3], item->GetY()[3]) == '#')
		{

			item->Destroy();
			if (item->GetX()[0] == 0 && item->GetY()[0] == 0)
			{
				for (int i = 0; i < 6; i++)
				{
					for (int j = 0; j < 2; j++)
					{
						if (item->GetX()[0] - item->GetX()[1] != 0)
						{
							p.SetField(i, j);
						}
						else
						{
							p.SetField(j, i);
						}
					}
				}
			}
			else if (item->GetX()[3] == 9 && item->GetY()[0] == 0)
			{
				if (item->GetX()[0] - item->GetX()[1] != 0)
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 5; i++)
					{
						for (int j = item->GetY()[0]; j < item->GetY()[0] + 2; j++)
						{

							p.SetField(i, j);

						}
					}
				}
				else 
				{
					for (int i = item->GetX()[0] ; i < item->GetX()[0] + 2; i++)
					{
						for (int j = item->GetY()[0] -1 ; j < item->GetY()[0] + 5; j++)
						{

							p.SetField(i, j);

						}
					}
				}
			}
			else if (item->GetX()[0] == 0 && item->GetY()[3] == 9)
			{
				if (item->GetX()[0] - item->GetX()[1] != 0)
				{
					for (int i = item->GetX()[0]; i < item->GetX()[0] + 5; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 1; j++)
						{

							p.SetField(i, j);

						}
					}
				}
				else 
				{
					for (int i = item->GetX()[0]-1; i < item->GetX()[0] + 1; i++)
					{
						for (int j = item->GetY()[0] ; j < item->GetY()[0] + 5; j++)
						{

							p.SetField(i, j);

						}
					}
				}
			}
			else if (item->GetX()[3] == 9 && item->GetY()[3] == 9)
			{
				for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 5; i++)
				{
					for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 1; j++)
					{
						if (item->GetX()[0] - item->GetX()[1] != 0)
						{
							p.SetField(i, j);
						}
						else
						{
							p.SetField(j, i);
						}
					}
				}
			}
			else if (item->GetY()[0] == 0)
			{
				if (item->GetX()[0] - item->GetX()[1] != 0)
				{
					for (int i = item->GetX()[0]-1; i < item->GetX()[0] + 5; i++)
					{
						for (int j = item->GetY()[0]; j < item->GetY()[0] + 2; j++)
						{

							p.SetField(i, j);

						}
					}
				}
				else
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 2; i++)
					{
						for (int j = item->GetY()[0]; j < item->GetY()[0] + 5; j++)
						{

							p.SetField(i, j);

						}
					}
				}
					
				
			}
			else if (item->GetY()[3] == 9)
			{
				if (item->GetX()[0] - item->GetX()[1] != 0)
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 5; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 1; j++)
						{
						
							p.SetField(i, j);
						
					}
				}
				}
				else 
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 2; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 4; j++)
						{

							p.SetField(i, j);

						}
					}
				}
			}
			else if (item->GetX()[3] == 9 )
			{
				if (item->GetX()[0] - item->GetX()[1] != 0)
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 5; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 2; j++)
						{

							p.SetField(i, j);

						}
					}
				}
				else 
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 2; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 5; j++)
						{

							p.SetField(i, j);

						}
					}
				}
			}
			else if (item->GetX()[0] == 0)
			{
				if (item->GetX()[0] - item->GetX()[1] != 0)
				{
					for (int i = item->GetX()[0]; i < item->GetX()[0] + 5; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 2; j++)
						{

							p.SetField(i, j);


						}
					}
				}
				else 
				{
					for (int i = item->GetX()[0]; i < item->GetX()[0] + 2; i++)
					{
						for (int j = item->GetY()[0]-1 ; j < item->GetY()[0] + 5; j++)
						{

							p.SetField(i, j);


						}
					}
				}
			}
			else
			{
				if (item->GetX()[0] - item->GetX()[1] != 0)
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 5; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 2; j++)
						{
							p.SetField(i, j);
						}
					}
				}
				else
				{
					for (int i = item->GetX()[0] - 1; i < item->GetX()[0] + 2; i++)
					{
						for (int j = item->GetY()[0] - 1; j < item->GetY()[0] + 5; j++)
						{
							p.SetField(i, j);
						}
					}
				}
		}
		}

	}

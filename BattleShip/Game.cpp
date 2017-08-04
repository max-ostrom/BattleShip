#include "Game.h"

#include <chrono>
#include <thread>
#include <string>

#include <Windows.h>
#include <conio.h>



bool Game::isKeyPressed(int key) const 
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
	clock_t startTime = clock();
	bool turn = true;
	int coordAtack[2]; // координаты атаки 
	bool hitting = false; // попал ли комьютер 
	while (!You_.isEndOfGame() && !Computer_.isEndOfGame())
	{
			
		reprintField();
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
				while (!isKeyPressed(32)) // выход из паузы по пробелу
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
				} // первая координата атаки
				// первая координата атаки
				switch (_getch())
				{
				case 49: //1
				{	cout << static_cast<char>(49);
				coordAtack[1] = 0;
				break;
				}
				case 50: //2
				{
					cout << static_cast<char>(50);
					coordAtack[1] = 1;
					break;
				}
				case 51: //3
				{
					cout << static_cast<char>(51);
					coordAtack[1] = 2;
					break;
				}
				case 52: //4
				{	cout << static_cast<char>(52);
				coordAtack[1] = 3;
				break;
				}
				case 53: //5
				{
					cout << static_cast<char>(53);
					coordAtack[1] = 4;
					break;
				}
				case 54: //6
				{
					cout << static_cast<char>(54);
					coordAtack[1] = 5;
					break;
				}
				case 55: //7
				{
					cout << static_cast<char>(55);
					coordAtack[1] = 6;
					break;
				}
				case 56: //8
				{
					cout << static_cast<char>(56);
					coordAtack[1] = 7;
					break;
				}
				case 57: //9
				{
					cout << static_cast<char>(57);
					coordAtack[1] = 8;
					break;
				}
				case 48: //0
				{
					cout << static_cast<char>(48);
					coordAtack[1] = 9;
					break;
				}
				default: {
					coordAtack[1] = 0;
					break; }
				} //
				// вторая координата атаки
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
									//NearCell(var,coordAtack[0],coordAtack[1]);
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



void Game::endOfGame(const clock_t startGame) const
{
	this_thread::sleep_for(chrono::seconds(2));
	// конец игры
	int yourAliveShips = 0;
	//подсчет живих кораблей игрока
	for each (auto item in You_.YourShips)
	{
		if (item->isAlive())
		{
			yourAliveShips++;
		}
	}
	int computerAliveShips = 0;
	//подсчет живих кораблей комьютера
	for each (auto item in Computer_.YourShips)
	{
		if (item->isAlive())
		{
			computerAliveShips++;
		}
	}
		
		
	system("cls");
	char alf[11] = { "ABCDEFGHIJ" };
	char numbers[12] = { " 1234567890" };
	cout << "Computer ships" << endl;
	cout << numbers<< endl;
	//отрисовка кораблей комьютера
	for (int i = 0; i < 10; i++)
	{
		cout << alf[i];
		for (int j = 0; j < 10; j++)
		{
			cout << Computer_.getField(i, j);
		}
		cout << endl;

	}
	// вывод времени игры и количества оставшихся кораблей
	cout << "Time: "
		<< static_cast<int>((clock() - startGame) / CLOCKS_PER_SEC) / 60
		<< ":" 
		<< static_cast<int>((clock() - startGame) / CLOCKS_PER_SEC) % 60 
		<< "Your Ships : " << yourAliveShips <<endl
		<< "Computer Ships : " << computerAliveShips <<endl;
}




void Game::reprintField() const  // поток перерисовывающий поля
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
			cout << You_.getField(i, j);
		}
		cout << endl;
	}
	cout << numbers << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << alf[i];
		for (int j = 0; j < 10; j++)
		{
			if (Computer_.getField(i, j) == 'X')
				cout << " ";
			else
				cout << Computer_.getField(i, j);
		}	
		cout << endl;
	}
	
		
}
#include <ctime>
#include<iostream>
#include "Player.h"
#include "Game.h"
using namespace std;

void AutoSet(char field[10][10], int  m, int n)
{//–асстановка четырехпалубного корабл€
	
	int l = rand() % 2;
	switch (l) {
	case 0://вертикальное положение
		m = rand() % 7;
		n = rand() % 10;
		while (field[m][n] == 'X' || field[m + 1][n] == 'X' || field[m + 2][n] == 'X' || field[m + 3][n] == 'X' ||
			field[m - 1][n - 1] == 'X' || field[m - 1][n] == 'X' || field[m - 1][n + 1] == 'X' || field[m][n - 1] == 'X' ||
			field[m][n + 1] == 'X' || field[m + 1][n - 1] == 'X' || field[m + 1][n + 1] == 'X' || field[m + 2][n - 1] == 'X' ||
			field[m + 2][n + 1] == 'X' || field[m + 3][n - 1] == 'X' || field[m + 3][n + 1] == 'X' || field[m + 4][n - 1] == 'X' ||
			field[m + 4][n] == 'X' || field[m + 4][n + 1] == 'X') {
			m = rand() % 7;
			n = rand() % 10;
		}
		field[m][n] = 'X';
		field[m + 1][n] = 'X';
		field[m + 2][n] = 'X';
		field[m + 3][n] = 'X';
		break;
	case 1://горизонтальное положение
		m = rand() % 10;
		n = rand() % 7;
		while (field[m][n] == 'X' || field[m][n + 1] == 'X' || field[m][n + 2] == 'X' || field[m][n + 3] == 'X' ||
			field[m - 1][n - 1] == 'X' || field[m - 1][n] == 'X' || field[m - 1][n + 1] == 'X' || field[m - 1][n + 2] == 'X' ||
			field[m - 1][n + 3] == 'X' || field[m - 1][n + 4] == 'X' || field[m][n - 1] == 'X' || field[m][n + 4] == 'X' ||
			field[m + 1][n - 1] == 'X' || field[m + 1][n] == 'X' || field[m + 1][n + 1] == 'X' || field[m + 1][n + 2] == 'X' ||
			field[m + 1][n + 3] == 'X' || field[m + 1][n + 4] == 'X') {
			m = rand() % 10;
			n = rand() % 7;
		}
		field[m][n] = 'X';
		field[m][n + 1] = 'X';
		field[m][n + 2] = 'X';
		field[m][n + 3] = 'X';
		break;
	}//switch
	 //–асстановка трехпалубных кораблей
	for (int i = 0; i<2; i++) {
		int n = rand() % 2;
		switch (n) {
		case 0://вертикальное положение корабл€
			m = rand() % 8;
			n = rand() % 10;
			while (field[m][n] == 'X' || field[m + 1][n] == 'X' || field[m + 2][n] == 'X' || field[m - 1][n - 1] == 'X' ||
				field[m - 1][n] == 'X' || field[m - 1][n + 1] == 'X' || field[m][n - 1] == 'X' || field[m][n + 1] == 'X' ||
				field[m + 1][n - 1] == 'X' || field[m + 1][n + 1] == 'X' || field[m + 2][n - 1] == 'X' || field[m + 2][n + 1] == 'X' ||
				field[m + 3][n - 1] == 'X' || field[m + 3][n] == 'X' || field[m + 3][n + 1] == 'X') {
				m = rand() % 8;
				n = rand() % 10;
			}
			field[m][n] = 'X';
			field[m + 1][n] = 'X';
			field[m + 2][n] = 'X';
			break;
		case 1:
			m = rand() % 10;
			n = rand() % 8;
			while (field[m][n] == 'X' || field[m][n + 1] == 'X' || field[m][n + 2] == 'X' || field[m - 1][n - 1] == 'X' ||
				field[m - 1][n] == 'X' || field[m - 1][n + 1] == 'X' || field[m - 1][n + 2] == 'X' || field[m - 1][n + 3] == 'X' ||
				field[m][n - 1] == 'X' || field[m][n + 3] == 'X' || field[m + 1][n - 1] == 'X' || field[m + 1][n] == 'X' ||
				field[m + 1][n + 1] == 'X' || field[m + 1][n + 2] == 'X' || field[m + 1][n + 3] == 'X') {
				m = rand() % 10;
				n = rand() % 8;
			}
			field[m][n] = 'X';
			field[m][n + 1] = 'X';
			field[m][n + 2] = 'X';
			break;
		}//switch
	}//for
	 //–асстановка двохпалубных кораблей
	for (int i = 0; i<3; i++) {
		int k = rand() % 2;
		switch (k) {
		case 0://вертикальное расположение корабл€
			m = rand() % 9;
			n = rand() % 10;
			while (field[m][n] == 'X' || field[m - 1][n - 1] == 'X' || field[m - 1][n] == 'X' || field[m - 1][n + 1] == 'X' ||
				field[m][n - 1] == 'X' || field[m][n + 1] == 'X' || field[m + 1][n - 1] == 'X' || field[m + 1][n] == 'X' ||
				field[m + 1][n + 1] == 'X' || field[m + 2][n - 1] == 'X' || field[m + 2][n] == 'X' || field[m + 2][n + 1] == 'X') {
				m = rand() % 9;
				n = rand() % 10;
			}
			field[m][n] = 'X';
			field[m + 1][n] = 'X';
			break;
		case 1://горизонтальное расположение корабл€
			m = rand() % 10;
			n = rand() % 9;
			while (field[m][n] == 'X' || field[m][n + 1] == 'X' || field[m - 1][n - 1] == 'X' || field[m - 1][n] == 'X' ||
				field[m - 1][n + 1] == 'X' || field[m - 1][n + 2] == 'X' || field[m][n - 1] == 'X' || field[m][n + 2] == 'X' ||
				field[m + 1][n - 1] == 'X' || field[m + 1][n] == 'X' || field[m + 1][n + 1] == 'X' || field[m + 1][n + 2] == 'X') {
				m = rand() % 10;
				n = rand() % 9;
			}
			field[m][n] = 'X';
			field[m][n + 1] = 'X';
			break;
		}
	}
	//–асстановка однопалубных кораблей
	for (int i = 0; i<4; i++) {
		m = rand() % 10;
		n = rand() % 10;
		while (field[m][n] == 'X' || field[m][n + 1] == 'X' || field[m][n - 1] == 'X' || field[m + 1][n] == 'X' || field[m - 1][n] == 'X'
			|| field[m + 1][n + 1] == 'X' || field[m + 1][n - 1] == 'X' || field[m - 1][n + 1] == 'X' || field[m - 1][n - 1] == 'X') {
			m = rand() % 10;
			n = rand() % 10;
		}
		field[m][n] = 'X';
	}

}
void main()
{
	new Game();

	
}
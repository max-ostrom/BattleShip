#include "ThreeDeckShip.h"



ThreeDeckShip::ThreeDeckShip(char field[10][10])
{
	int n = rand() % 2;
	switch (n) {
	case 0://вертикальное положение корабля
	{
		int m = rand() % 8;
		int n = rand() % 10;
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
		break; }
	case 1:
		int m = rand() % 10;
		int n = rand() % 8;
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
}

int ThreeDeckShip::GetShipSize()
{
	return 3;
}


ThreeDeckShip::~ThreeDeckShip()
{
}

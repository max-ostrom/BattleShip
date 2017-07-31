#include "FourDeckShip.h"



FourDeckShip::FourDeckShip(char field[10][10])
{
	int l = rand() % 2;
	switch (l) {
	case 0://вертикальное положение
	{
		int m = rand() % 7;
		int n = rand() % 10;
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
		break; }
	case 1://горизонтальное положение
		int m = rand() % 10;
		int n = rand() % 7;
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
}

int FourDeckShip::GetShipSize()
{
	return 4;
}


FourDeckShip::~FourDeckShip()
{
}

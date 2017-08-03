#include "DoubleDeckShip.h"



DoubleDeckShip::DoubleDeckShip(char field[10][10])
{
	coordsX_ = new int[2];
	coordsY_ = new int[2];
	srand(time(0));
	int k = rand() % 2;
	switch (k) {
	case 0://вертикальное расположение корабля
{
		int m = rand() % 9;
		int n = rand() % 10;
		while 
			(
			field[m][n] == 'X' || field[m - 1][n - 1] == 'X' || 
			field[m - 1][n] == 'X' || field[m - 1][n + 1] == 'X' ||
			field[m][n - 1] == 'X' || field[m][n + 1] == 'X' || 
			field[m + 1][n - 1] == 'X' || field[m + 1][n] == 'X' ||
			field[m + 1][n + 1] == 'X' || field[m + 2][n - 1] == 'X' || 
			field[m + 2][n] == 'X' || field[m + 2][n + 1] == 'X') 
		{
			m = rand() % 9;
			n = rand() % 10;
		}
		field[m][n] = 'X';
		field[m + 1][n] = 'X';
		coordsX_[0] = m;
		coordsX_[1] = m + 1;
		coordsY_[0] = n;
		coordsY_[1] = n;
		break;
	}
	case 1://горизонтальное расположение корабля
		int m = rand() % 10;
		int n = rand() % 9;
		while (
			field[m][n] == 'X' || field[m][n + 1] == 'X' || 
			field[m - 1][n - 1] == 'X' || field[m - 1][n] == 'X' ||
			field[m - 1][n + 1] == 'X' || field[m - 1][n + 2] == 'X' || 
			field[m][n - 1] == 'X' || field[m][n + 2] == 'X' ||
			field[m + 1][n - 1] == 'X' || field[m + 1][n] == 'X' || 
			field[m + 1][n + 1] == 'X' || field[m + 1][n + 2] == 'X') 
		{
			m = rand() % 10;
			n = rand() % 9;
		}
		field[m][n] = 'X';
		field[m][n + 1] = 'X';
		coordsX_[0] = m;
		coordsX_[1] = m;
		coordsY_[0] = n;
		coordsY_[1] = n+1;
		break;
	}
}

int DoubleDeckShip::getShipSize() const
{
	return 2;
}



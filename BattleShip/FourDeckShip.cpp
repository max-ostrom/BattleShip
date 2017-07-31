#include "FourDeckShip.h"



FourDeckShip::FourDeckShip(char field[10][10])
{
	coordsX_ = new int[4];
	coordsY_ = new int[4];
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
		coordsX_[0] = m;
		coordsX_[1] = m + 1;
		coordsX_[2] = m + 2;
		coordsX_[3] = m + 3;
		coordsY_[0] = n;
		coordsY_[1] = n;
		coordsY_[2] = n;
		coordsY_[3] = n;
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
		coordsX_[0] = m;
		coordsX_[1] = m;
		coordsX_[2] = m;
		coordsX_[3] = m;
		coordsY_[0] = n;
		coordsY_[1] = n+1;
		coordsY_[2] = n+2;
		coordsY_[3] = n+3;
		break;
	}//switch
}

int FourDeckShip::GetShipSize()
{
	return 4;
}


FourDeckShip::~FourDeckShip()
{
	delete(coordsX_);
	delete(coordsY_);
}

#include "DoubleDeckShip.h"



DoubleDeckShip::DoubleDeckShip(char field[FIELDSIZE][FIELDSIZE])
{
	coordsX_ = auto_ptr<int>(new int[SHIPSIZE]);
	coordsY_ = auto_ptr<int>(new int[SHIPSIZE]);

	srand(time(0));
	int k = rand() % 2;
	
	switch (k) {
	
	
	case 0://вертикальное расположение корабля
	{
		int m = rand() % 9;
		int n = rand() % 10;


		while 
			(isCellFreeVertical(field,m,n)) 
		{
			m = rand() % 9;
			n = rand() % 10;
		}



		field[m][n] = 'X';
		field[m + 1][n] = 'X';


		coordsX_.get()[0] = m;
		coordsX_.get()[1] = m + 1;
		coordsY_.get()[0] = n;
		coordsY_.get()[1] = n;
		break;
	}
	
	
	
	case 1://горизонтальное расположение корабля
		
		
		int m = rand() % 10;
		int n = rand() % 9;


		while 
			(isCellFreeHorizontal(field,m,n)) 
		{
			m = rand() % 10;
			n = rand() % 9;
		}


		field[m][n] = 'X';
		field[m][n + 1] = 'X';


		coordsX_.get()[0] = m;
		coordsX_.get()[1] = m;
		coordsY_.get()[0] = n;
		coordsY_.get()[1] = n+1;
		break;
	}
}

const int& DoubleDeckShip::getShipSize() const
{
	return SHIPSIZE;
}

bool DoubleDeckShip::isCellFreeHorizontal(const char field[FIELDSIZE][FIELDSIZE], const int m, const int n) const
{
	return field[m][n] == 'X' || field[m][n + 1] == 'X' ||
		field[m - 1][n - 1] == 'X' || field[m - 1][n] == 'X' ||
		field[m - 1][n + 1] == 'X' || field[m - 1][n + 2] == 'X' ||
		field[m][n - 1] == 'X' || field[m][n + 2] == 'X' ||
		field[m + 1][n - 1] == 'X' || field[m + 1][n] == 'X' ||
		field[m + 1][n + 1] == 'X' || field[m + 1][n + 2] == 'X';
}

bool DoubleDeckShip::isCellFreeVertical(const char field[FIELDSIZE][FIELDSIZE], const int m, const int n) const
{
	return field[m][n] == 'X' || field[m - 1][n - 1] == 'X' ||
		field[m - 1][n] == 'X' || field[m - 1][n + 1] == 'X' ||
		field[m][n - 1] == 'X' || field[m][n + 1] == 'X' ||
		field[m + 1][n - 1] == 'X' || field[m + 1][n] == 'X' ||
		field[m + 1][n + 1] == 'X' || field[m + 2][n - 1] == 'X' ||
		field[m + 2][n] == 'X' || field[m + 2][n + 1] == 'X';
}



#include "SingleDeckShip.h"



SingleDeckShip::SingleDeckShip(char field[FIELDSIZE][FIELDSIZE])
{
	coordsX_ = auto_ptr<int>(new int[SHIPSIZE]);
	coordsY_ = auto_ptr<int>(new int[SHIPSIZE]);


	srand(time(0));


	
	int m = rand() % 10;
	int n = rand() % 10;


	while (isCellFreeHorizontal(field, m, n))
	{
		m = rand() % 10;
		n = rand() % 10;
	}


	field[m][n] = 'X';


	coordsX_.get()[0] = m;
	coordsY_.get()[0] = n;
	
}
const int& SingleDeckShip::getShipSize() const
{
	return SHIPSIZE;
}

bool SingleDeckShip::isCellFreeHorizontal(const char field[FIELDSIZE][FIELDSIZE],const int m,const int n) const
{
	return field[m][n] == 'X' || field[m][n + 1] == 'X' ||
		field[m][n - 1] == 'X' || field[m + 1][n] == 'X' ||
		field[m - 1][n] == 'X' || field[m + 1][n + 1] == 'X' ||
		field[m + 1][n - 1] == 'X' || field[m - 1][n + 1] == 'X' ||
		field[m - 1][n - 1] == 'X';
}

bool SingleDeckShip::isCellFreeVertical(const char field[FIELDSIZE][FIELDSIZE], const int m, const int n) const
{
	return field[m][n] == 'X' || field[m][n + 1] == 'X' ||
		field[m][n - 1] == 'X' || field[m + 1][n] == 'X' ||
		field[m - 1][n] == 'X' || field[m + 1][n + 1] == 'X' ||
		field[m + 1][n - 1] == 'X' || field[m - 1][n + 1] == 'X' ||
		field[m - 1][n - 1] == 'X';
}


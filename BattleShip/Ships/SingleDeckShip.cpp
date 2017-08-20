#include "SingleDeckShip.h"



SingleDeckShip::SingleDeckShip(char field[FIELD_SIZE][FIELD_SIZE])
{
	coordsX_ = shared_ptr<int>(new int[SHIP_SIZE_]);
	coordsY_ = shared_ptr<int>(new int[SHIP_SIZE_]);


	srand(time(0));


	
	int m = rand() % FIELD_SIZE - SHIP_SIZE_ + 1;
	int n = rand() % FIELD_SIZE - SHIP_SIZE_ + 1;


	while (isCellFreeHorizontal(field, m, n))
	{
		m = rand() % FIELD_SIZE - SHIP_SIZE_ + 1;
		n = rand() % FIELD_SIZE - SHIP_SIZE_ + 1;
	}


	field[m][n] = 'X';


	coordsX_.get()[0] = m;
	coordsY_.get()[0] = n;
	
}
const int& SingleDeckShip::getShipSize() const
{
	return SHIP_SIZE_;
}

bool SingleDeckShip::isCellFreeHorizontal(const char field[FIELD_SIZE][FIELD_SIZE],const int m,const int n) const
{
	return field[m][n] == 'X' || field[m][n + 1] == 'X' ||
		field[m][n - 1] == 'X' || field[m + 1][n] == 'X' ||
		field[m - 1][n] == 'X' || field[m + 1][n + 1] == 'X' ||
		field[m + 1][n - 1] == 'X' || field[m - 1][n + 1] == 'X' ||
		field[m - 1][n - 1] == 'X';
}

bool SingleDeckShip::isCellFreeVertical(const char field[FIELD_SIZE][FIELD_SIZE], const int m, const int n) const
{
	return field[m][n] == 'X' || field[m][n + 1] == 'X' ||
		field[m][n - 1] == 'X' || field[m + 1][n] == 'X' ||
		field[m - 1][n] == 'X' || field[m + 1][n + 1] == 'X' ||
		field[m + 1][n - 1] == 'X' || field[m - 1][n + 1] == 'X' ||
		field[m - 1][n - 1] == 'X';
}


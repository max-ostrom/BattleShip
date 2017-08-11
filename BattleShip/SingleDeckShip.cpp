#include "..\BattleShip\Ships\SingleDeckShip.h"



SingleDeckShip::SingleDeckShip(char field[FIELDSIZE][FIELDSIZE])
{
	coordsX_ = shared_ptr<int>(new int[SHIPSIZE]);
	coordsY_ = shared_ptr<int>(new int[SHIPSIZE]);


	srand(time(0));


	
	int m = rand() % FIELDSIZE - SHIPSIZE + 1;
	int n = rand() % FIELDSIZE - SHIPSIZE + 1;


	while (isCellFreeHorizontal(field, m, n))
	{
		m = rand() % FIELDSIZE - SHIPSIZE + 1;
		n = rand() % FIELDSIZE - SHIPSIZE + 1;
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


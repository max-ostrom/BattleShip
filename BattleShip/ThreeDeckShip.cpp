#include "..\BattleShip\Ships\ThreeDeckShip.h"



ThreeDeckShip::ThreeDeckShip(char field[FIELDSIZE][FIELDSIZE])
{
	coordsX_ = shared_ptr<int>(new int[SHIPSIZE]);
	coordsY_ = shared_ptr<int>(new int[SHIPSIZE]);


	int n = rand() % 2;

	switch (n) {

	case 0://vertical
	{
		int m = rand() % FIELDSIZE - SHIPSIZE + 1;
		int n = rand() % FIELDSIZE;


		while (isCellFreeVertical(field,m,n)) 
		{
			m = rand() % FIELDSIZE - SHIPSIZE + 1;
			n = rand() % FIELDSIZE;
		}


		field[m][n] = 'X';
		field[m + 1][n] = 'X';
		field[m + 2][n] = 'X';


		coordsX_.get()[0] = m;
		coordsX_.get()[1] = m+1;
		coordsX_.get()[2] = m+2;


		coordsY_.get()[0] = n;
		coordsY_.get()[1] = n;
		coordsY_.get()[2] = n;
		break; }
	case 1://horizontal
		int m = rand() % FIELDSIZE;
		int n = rand() % FIELDSIZE - SHIPSIZE + 1;


		while (isCellFreeHorizontal(field,m,n))
		{
			m = rand() % FIELDSIZE;
			n = rand() % FIELDSIZE - SHIPSIZE +1;
		}


		field[m][n] = 'X';
		field[m][n + 1] = 'X';
		field[m][n + 2] = 'X';


		coordsX_.get()[0] = m;
		coordsX_.get()[1] = m ;
		coordsX_.get()[2] = m ;


		coordsY_.get()[0] = n;
		coordsY_.get()[1] = n+1;
		coordsY_.get()[2] = n+2;
		break;
	}//switch
}

const int& ThreeDeckShip::getShipSize() const
{
	return SHIPSIZE;
}

bool ThreeDeckShip::isCellFreeHorizontal(const char field[FIELDSIZE][FIELDSIZE], const int m, const int n) const
{
	return field[m][n] == 'X' || field[m][n + 1] == 'X' ||
		field[m][n + 2] == 'X' || field[m - 1][n - 1] == 'X' ||
		field[m - 1][n] == 'X' || field[m - 1][n + 1] == 'X' ||
		field[m - 1][n + 2] == 'X' || field[m - 1][n + 3] == 'X' ||
		field[m][n - 1] == 'X' || field[m][n + 3] == 'X' ||
		field[m + 1][n - 1] == 'X' || field[m + 1][n] == 'X' ||
		field[m + 1][n + 1] == 'X' || field[m + 1][n + 2] == 'X' ||
		field[m + 1][n + 3] == 'X';
}

bool ThreeDeckShip::isCellFreeVertical(const char field[FIELDSIZE][FIELDSIZE], const int m, const int n) const
{
	return field[m][n] == 'X' || field[m + 1][n] == 'X' ||
		field[m + 2][n] == 'X' || field[m - 1][n - 1] == 'X' ||
		field[m - 1][n] == 'X' || field[m - 1][n + 1] == 'X' ||
		field[m][n - 1] == 'X' || field[m][n + 1] == 'X' ||
		field[m + 1][n - 1] == 'X' || field[m + 1][n + 1] == 'X' ||
		field[m + 2][n - 1] == 'X' || field[m + 2][n + 1] == 'X' ||
		field[m + 3][n - 1] == 'X' || field[m + 3][n] == 'X' ||
		field[m + 3][n + 1] == 'X';
}



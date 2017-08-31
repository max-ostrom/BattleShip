#include "ThreeDeckShip.h"



ThreeDeckShip::ThreeDeckShip(char field[STANDART_FIELD][STANDART_FIELD])
{
	coordsX_ = shared_ptr<int>(new int[SHIP_SIZE_]);
	coordsY_ = shared_ptr<int>(new int[SHIP_SIZE_]);


	int n = rand() % 2;

	switch (n) {

	case 0://vertical
	{
		int m = rand() % (STANDART_FIELD - SHIP_SIZE_ + 1);
		int n = rand() % STANDART_FIELD;


		while (isCellFreeVertical(field,m,n)) 
		{
			m = rand() % (STANDART_FIELD - SHIP_SIZE_ + 1);
			n = rand() % STANDART_FIELD;
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
		int m = rand() % STANDART_FIELD;
		int n = rand() % (STANDART_FIELD - SHIP_SIZE_ + 1);


		while (isCellFreeHorizontal(field,m,n))
		{
			m = rand() % STANDART_FIELD;
			n = rand() % (STANDART_FIELD - SHIP_SIZE_ + 1);
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
	return SHIP_SIZE_;
}

bool ThreeDeckShip::isCellFreeHorizontal(const char field[STANDART_FIELD][STANDART_FIELD], const int m, const int n) const
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

bool ThreeDeckShip::isCellFreeVertical(const char field[STANDART_FIELD][STANDART_FIELD], const int m, const int n) const
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



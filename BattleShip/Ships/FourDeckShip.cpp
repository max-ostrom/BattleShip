#include "FourDeckShip.h"



FourDeckShip::FourDeckShip(char field[FIELD_SIZE][FIELD_SIZE])
{
	coordsX_ = shared_ptr<int>(new int[SHIP_SIZE_]);
	coordsY_ = shared_ptr<int>(new int[SHIP_SIZE_]);


	int l = rand() % 2;
	
	
	switch (l) {
	
	case 0://vertical
	{
		int m = rand() % (FIELD_SIZE - SHIP_SIZE_ + 1);
		int n = rand() % FIELD_SIZE;
		
		
		while (isCellFreeVertical(field,m,n)) 		
		{
			m = rand() % (FIELD_SIZE - SHIP_SIZE_ + 1);
			n = rand() % FIELD_SIZE;
		}
		
		
		field[m][n] = 'X';
		field[m + 1][n] = 'X';
		field[m + 2][n] = 'X';
		field[m + 3][n] = 'X';
		
		
		coordsX_.get()[0] = m;
		coordsX_.get()[1] = m + 1;
		coordsX_.get()[2] = m + 2;
		coordsX_.get()[3] = m + 3;
	
		
		coordsY_.get()[0] = n;
		coordsY_.get()[1] = n;
		coordsY_.get()[2] = n;
		coordsY_.get()[3] = n;
		break; }
	
	
	case 1://horizontal
		
		
		int m = rand() % FIELD_SIZE;
		int n = rand() % (FIELD_SIZE - SHIP_SIZE_ + 1);
		
		
		while (isCellFreeHorizontal(field,m,n))
		{
			m = rand() % FIELD_SIZE;
			n = rand() % (FIELD_SIZE - SHIP_SIZE_ + 1);
		}


		field[m][n] = 'X';
		field[m][n + 1] = 'X';
		field[m][n + 2] = 'X';
		field[m][n + 3] = 'X';


		coordsX_.get()[0] = m;
		coordsX_.get()[1] = m;
		coordsX_.get()[2] = m;
		coordsX_.get()[3] = m;


		coordsY_.get()[0] = n;
		coordsY_.get()[1] = n+1;
		coordsY_.get()[2] = n+2;
		coordsY_.get()[3] = n+3;
		break;
	}//switch
}

const int& FourDeckShip::getShipSize() const
{
	return SHIP_SIZE_;
}

bool FourDeckShip::isCellFreeHorizontal(const char field[FIELD_SIZE][FIELD_SIZE], const int m, const int n) const
{
	return field[m][n] == 'X' || field[m][n + 1] == 'X' ||
		field[m][n + 2] == 'X' || field[m][n + 3] == 'X' ||
		field[m - 1][n - 1] == 'X' || field[m - 1][n] == 'X' ||
		field[m - 1][n + 1] == 'X' || field[m - 1][n + 2] == 'X' ||
		field[m - 1][n + 3] == 'X' || field[m - 1][n + 4] == 'X' ||
		field[m][n - 1] == 'X' || field[m][n + 4] == 'X' ||
		field[m + 1][n - 1] == 'X' || field[m + 1][n] == 'X' ||
		field[m + 1][n + 1] == 'X' || field[m + 1][n + 2] == 'X' ||
		field[m + 1][n + 3] == 'X' || field[m + 1][n + 4] == 'X';
}

bool FourDeckShip::isCellFreeVertical(const char field[FIELD_SIZE][FIELD_SIZE], const int m, const int n) const
{
	return field[m][n] == 'X' || field[m + 1][n] == 'X' ||
		field[m + 2][n] == 'X' || field[m + 3][n] == 'X' ||
		field[m - 1][n - 1] == 'X' || field[m - 1][n] == 'X' ||
		field[m - 1][n + 1] == 'X' || field[m][n - 1] == 'X' ||
		field[m][n + 1] == 'X' || field[m + 1][n - 1] == 'X' ||
		field[m + 1][n + 1] == 'X' || field[m + 2][n - 1] == 'X' ||
		field[m + 2][n + 1] == 'X' || field[m + 3][n - 1] == 'X' ||
		field[m + 3][n + 1] == 'X' || field[m + 4][n - 1] == 'X' ||
		field[m + 4][n] == 'X' || field[m + 4][n + 1] == 'X';
}





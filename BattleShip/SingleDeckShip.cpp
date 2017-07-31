#include "SingleDeckShip.h"



SingleDeckShip::SingleDeckShip(char field[10][10])
{
	coordsX_ = new int[1];
	coordsY_ = new int[1];
	srand(time(0));
	for (int i = 0; i<1; i++) {
		int m = rand() % 10;
		int n = rand() % 10;
		while (field[m][n] == 'X' || field[m][n + 1] == 'X' || field[m][n - 1] == 'X' || field[m + 1][n] == 'X' || field[m - 1][n] == 'X'
			|| field[m + 1][n + 1] == 'X' || field[m + 1][n - 1] == 'X' || field[m - 1][n + 1] == 'X' || field[m - 1][n - 1] == 'X') {
			m = rand() % 10;
			n = rand() % 10;
		}
		field[m][n] = 'X';
		coordsX_[0] = m;
		coordsY_[0] = n;
	}
}
int SingleDeckShip::GetShipSize()
{
	return 1;
}
SingleDeckShip::~SingleDeckShip()
{
	delete(coordsX_);
	delete(coordsY_);
}

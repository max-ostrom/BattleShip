#include "ViewModel.h"



ViewModel::ViewModel()
{
	for (int i = 0; i < STANDART_FIELD; i++)
	{
		for (int j = 0; j < STANDART_FIELD; j++)
		{
			userField_[i][j] = ' ';
			computerField_[i][j] = ' ';
		}
	}
}


ViewModel::~ViewModel()
{
}

void ViewModel::setUserField(const int i, const int j, const char symb)
{
	userField_[i][j] = symb;
}

void ViewModel::setComputerField(const int i, const int j, const char symb)
{
	computerField_[i][j] = symb;
}

char ViewModel::getUserField(const int i, const int j) const
{
	return userField_[i][j];
}

char ViewModel::getcomputerField(const int i, const int j) const
{
	return computerField_[i][j];
}

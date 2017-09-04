#pragma once
#include "Constants.h"
class ViewModel
{
public:
	ViewModel();
	virtual ~ViewModel();
	void setUserField(const int i, const int j,const char symb);
	void setComputerField(const int i, const int j, const char symb);
	char getUserField(const int i, const int j);
	char getcomputerField(const int i, const int j);
private:
	char userField_[STANDART_FIELD][STANDART_FIELD];
	char computerField_[STANDART_FIELD][STANDART_FIELD];
};


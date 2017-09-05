#pragma once

#include "Constants.h"
#include "IViewModel.h"

class ViewModel final :
	public IViewModel
{
public:
	ViewModel();
	virtual ~ViewModel();
	void setUserField(const int i, const int j,const char symb) override;
	void setComputerField(const int i, const int j, const char symb) override;
	char getUserField(const int i, const int j)const override;
	char getcomputerField(const int i, const int j)const override ;
private:
	char userField_[STANDART_FIELD][STANDART_FIELD];
	char computerField_[STANDART_FIELD][STANDART_FIELD];
};


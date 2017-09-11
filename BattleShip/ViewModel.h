#ifndef ViewModel_H
#define ViewModel_H

#include "Constants.h"
#include "IViewModel.h"

class ViewModel final :
	public IViewModel
{
public:
	ViewModel();
	virtual ~ViewModel();

	void setUserField
	(const int i_index, const int j_index,const char symb) override;

	void setComputerField
	(const int i_index, const int j_index, const char symb) override;

	char getUserField(const int i_index, const int j_index)const override;
	char getcomputerField(const int i_index, const int j_index)const override ;
private:
	char userField_[STANDART_FIELD][STANDART_FIELD];
	char computerField_[STANDART_FIELD][STANDART_FIELD];
};
#endif

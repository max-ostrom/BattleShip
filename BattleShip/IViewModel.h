#pragma once
#include "Observable.h"
class IViewModel 

{
public:
	virtual void setUserField(const int i, const int j, const char symb) = 0;
	virtual void setComputerField(const int i, const int j, const char symb) = 0;
	virtual char getUserField(const int i, const int j) const = 0;
	virtual char getcomputerField(const int i, const int j) const = 0;
	virtual ~IViewModel()
	{
	}
};


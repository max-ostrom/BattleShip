#pragma once
#include <memory>

#include "../Constants.h"

class Ship// abstract
{
protected:
	bool is_Alive_ = true;

	std::shared_ptr<int> coordsX_;
	std::shared_ptr<int> coordsY_;
public:
	virtual const int& getShipSize() const = 0 ;
	
	bool isAlive()const ;
	void destroy();

	virtual int* getX() const;
	virtual int* getY() const;
private:
	virtual bool isCellFreeHorizontal(const char field[FIELDSIZE][FIELDSIZE], const int m, const int n) const = 0;
	virtual bool isCellFreeVertical(const char field[FIELDSIZE][FIELDSIZE], const int m, const int n) const = 0;
};


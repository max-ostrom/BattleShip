#pragma once
#include <memory>
class Ship// abstract
{
protected:
	bool is_Alive_ = true;

	std::auto_ptr<int> coordsX_;
	std::auto_ptr<int> coordsY_;
public:
	virtual int getShipSize() const = 0 ;

	bool isAlive()const ;
	void destroy();

	virtual int* getX() const;
	virtual int* getY() const;

};


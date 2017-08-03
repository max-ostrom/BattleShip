#pragma once
class Ship// abstract
{
protected:
	bool is_Alive_ = true;

	int* coordsX_;
	int* coordsY_;
public:
	virtual int getShipSize() const = 0 ;

	bool isAlive()const ;
	void destroy();

	virtual int* getX() const;
	virtual int* getY() const;
	virtual ~Ship();
};


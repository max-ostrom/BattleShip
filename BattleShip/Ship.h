#pragma once
// interface
class IShip abstract
{
protected:
	bool is_Alive_ = true;
	int* coordsX_;
	int* coordsY_;
public:
	virtual int getShipSize() = 0;
	bool isAlive() { return is_Alive_; }
	void destroy() { is_Alive_ = false; }
	virtual int* getX() { return coordsX_; }
	virtual int* getY() { return coordsY_; }
};


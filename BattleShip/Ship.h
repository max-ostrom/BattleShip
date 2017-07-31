#pragma once
class Ship 
{
public:
	virtual int GetShipSize() { return 0; };
	bool IsAlive() { return isAlive; }
	void Destroy() { isAlive = false; }
	virtual int* GetX() { return coordsX_; }
	virtual int* GetY() { return coordsY_; }

	
protected:
	bool isAlive = true;
	int* coordsX_;
	int* coordsY_;
};


#pragma once
class Ship 
{
public:
	virtual int GetShipSize() { return 0; };
	bool Is_Alive() { return IsAlive; }
	void Dead() { IsAlive = false; }
	virtual int* GetX() { return coordsX; }
	virtual int* GetY() { return coordsY; }
protected:
	bool IsAlive = true;
	int* coordsX;
	int* coordsY;
};


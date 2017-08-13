#ifndef Ship_H
#define Ship_H

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
	virtual ~Ship();
	bool isAlive()const ;
	void destroy();

	virtual std::shared_ptr<int> getX() const;
	virtual std::shared_ptr<int> getY() const;
private:
	virtual bool isCellFreeHorizontal(const char field[FIELDSIZE][FIELDSIZE], const int m, const int n) const = 0;
	virtual bool isCellFreeVertical(const char field[FIELDSIZE][FIELDSIZE], const int m, const int n) const = 0;
};
#endif

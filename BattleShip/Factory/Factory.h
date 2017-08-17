#ifndef Factory_H
#define Factory_H
#include "..\UnionHeader.h"

#include <new>
#include <memory>
class IFactory
{
public:
	virtual std::shared_ptr<Ship>  createShip(char field[FIELD_SIZE][FIELD_SIZE]) = 0;
	virtual ~IFactory() {};
};
#endif

#ifndef IController_H
#define IController_H

class IController
{
public:

	virtual void run() = 0;
	virtual void input(vector<int>& coordAtack) = 0;
	virtual ~IController()
	{
	}
};
#endif

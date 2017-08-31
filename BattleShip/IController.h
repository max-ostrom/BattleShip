#pragma once
class IController
{
public:

	virtual void run() = 0;
	virtual void input(vector<int>& coordAtack) = 0;
	virtual ~IController()
	{
	}
};


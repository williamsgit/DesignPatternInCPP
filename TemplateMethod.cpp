/*
Author  : Williams Ma
Date    : 2016-6-15
Desc    : Template Method Design Pattern
*/

#include <iostream>
using namespace std;

class BaseClass
{
public:
	void Operation()
	{
		FirstStep();
		SecondStep();
		ThirdStep();
	}

protected:
	virtual void FirstStep() = 0;
	virtual void SecondStep() = 0;
	virtual void ThirdStep() = 0;
};

class SubClassOne : public BaseClass
{
protected:
	void FirstStep()
	{
		cout<<"One: FirstStep!"<<endl;
	}

	void SecondStep()
	{
		cout<<"One: SecondStep!"<<endl;
	}

	void ThirdStep()
	{
		cout<<"One: ThirdStep!"<<endl;
	}
};

class SubClassTwo : public BaseClass
{
protected:
	void FirstStep()
	{
		cout<<"Two: FirstStep!"<<endl;
	}

	void SecondStep()
	{
		cout<<"Two: SecondStep!"<<endl;
	}

	void ThirdStep()
	{
		cout<<"Two: ThirdStep!"<<endl;
	}
};

int main()
{
	BaseClass * pBase = NULL;
	pBase = new SubClassOne();
	pBase->Operation();

	delete pBase;
	pBase = NULL;

	pBase = new SubClassTwo();
	pBase->Operation();

	delete pBase;
	pBase = NULL;

	return 0;
}
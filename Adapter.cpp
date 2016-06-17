/*
Author  :  Williams Ma
Date    :  2016-6-17
Desc    :  Adapter Design Pattern
*/

#include <iostream>
using namespace std;

class Target
{
public:
	Target()
	{
		cout<<"Target constructor"<<endl;
	}

	virtual ~Target()
	{
		cout<<"Target destructor"<<endl;
	}

	virtual void Request()
	{
		cout<<"Target::Request"<<endl;
	}
};

class Adaptee
{
public:
	Adaptee()
	{
		cout<<"Adaptee constructor"<<endl;
	}

	virtual ~Adaptee()
	{
		cout<<"Adaptee destructor"<<endl;
	}

	void SpecificRequest()
	{
		cout<<"Adaptee::Request"<<endl;
	}
};

//Object Adapter
class Adapter : public Target
{
public:
	Adapter(Adaptee * pAdaptee)
	{
		cout<<"Adapter constructor"<<endl;
		this->m_pAdaptee = pAdaptee;
	}

	virtual ~Adapter()
	{
		cout<<"Adapter destructor"<<endl;
	}

	void Request()
	{
		this->m_pAdaptee->SpecificRequest();
	}

private:
	Adaptee * m_pAdaptee;
};

int main()
{
	Adaptee * pAdaptee = new Adaptee();
	Target * pTarget = new Adapter(pAdaptee);
	pTarget->Request();

	if(pAdaptee)
	{
		delete pAdaptee;
		pAdaptee = NULL;
	}

	if(pTarget)
	{
		delete pTarget;
		pTarget = NULL;
	}

	return 0;
}
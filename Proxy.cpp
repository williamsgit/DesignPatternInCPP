/*
Author   :  Williams Ma
Date     :  2016-6-17
Desc     :  Proxy Design Pattern
*/

#include <iostream>
using namespace std;

class Subject
{
public:
	Subject()
	{
		cout<<"Subject constructor"<<endl;
	}

	virtual ~Subject()
	{
		cout<<"Subject destructor"<<endl;
	}

	virtual void Request() = 0;
};

class RealSubject : public Subject
{
public:
	RealSubject()
	{
		cout<<"RealSubject constructor"<<endl;
	}

	~RealSubject()
	{
		cout<<"RealSubject destructor"<<endl;
	}

	void Request()
	{
		cout<<"RealSubject's Request"<<endl;
	}
};

class Proxy : public Subject
{
public:
	Proxy(RealSubject * pSubject)
	{
		cout<<"Proxy constructor"<<endl;
		this->m_pSubject = pSubject;
	}

	~Proxy()
	{
		cout<<"Proxy destructor"<<endl;
	}

	void Request()
	{
		this->m_pSubject->Request();
	}

protected:
	RealSubject * m_pSubject;
};

int main()
{
	RealSubject * pRealSubject = new RealSubject();
	Subject * pSubject = new Proxy(pRealSubject);
	pSubject->Request();

	if(pSubject)
	{
		delete pSubject;
		pSubject = NULL;
	}

	if(pRealSubject)
	{
		delete pRealSubject;
		pRealSubject = NULL;
	}

	return 0;
}


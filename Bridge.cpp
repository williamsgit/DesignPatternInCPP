/*
Author  :  Williams Ma
Date    :  2016-6-17
Desc    :  Bridge Design Pattern
*/

#include <iostream>
using namespace std;

class Implementor
{
public:
	virtual void Operation() = 0;
};

class FirstImplementor : public Implementor
{
public:
	void Operation()
	{
		cout<<"FirstImplementor: Operation"<<endl;
	}
};

class SecondImplementor : public Implementor
{
public:
	void Operation()
	{
		cout<<"SecondImpelementor: Operation"<<endl;
	}
};

class Abstraction
{
public:
	Abstraction(Implementor * pImplementor)
	{
		this->m_pImplementor = pImplementor;
		cout<<"Abstraction constructor"<<endl;
	}

	virtual ~Abstraction()
	{
		cout<<"Abstraction destructor"<<endl;
	}

	virtual void OperationImpl() = 0;

protected:
	Implementor * m_pImplementor;
};

class RefinedAbstraction : public Abstraction
{
public:
	RefinedAbstraction(Implementor * pImplementor):Abstraction(pImplementor)
	{
		cout<<"RefinedAbstraction constructor"<<endl;
	}

	~RefinedAbstraction()
	{
		cout<<"RefinedAbstraction destructor"<<endl;
	}

	void OperationImpl()
	{
		this->m_pImplementor->Operation();
	}
};

int main()
{
	Implementor * pSecondImplementor = new SecondImplementor();
	Abstraction * pAbstraction = new RefinedAbstraction(pSecondImplementor);
	pAbstraction->OperationImpl();
	return 0;
}
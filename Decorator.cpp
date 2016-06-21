/*
Author  :  Williams Ma
Date    :  2016-6-21
Desc    :  Decorator Design Pattern
*/

#include <iostream>
#include <string>
using namespace std;

class Component
{
public:
	Component(string name)
	{
		this->name = name;
	}

	virtual ~Component(){}
	virtual void Operation() = 0;

	string GetName()
	{
		return this->name;
	}
protected:
	string name;
};

class ConcreteComponent : public Component
{
public:
	ConcreteComponent(string name):Component(name)
	{
	}

	~ConcreteComponent(){}

	void Operation()
	{
		cout<<name<<endl;
	}
};

class Decorator : public Component
{
public:
	Decorator(string name,Component * pComponent):Component(name)
	{
		this->m_pComponent = pComponent;
	}

	virtual ~Decorator(){}

	void Operation()
	{
		cout<<m_pComponent->GetName()<<" Decorated with "<<this->GetName()<<endl;
		this->m_pComponent->Operation();
	}

protected:
	Component * m_pComponent;
};

class DecoratorA : public Decorator
{
public:
	DecoratorA(string name,Component * pComponent):Decorator(name,pComponent)
	{
	}

	~DecoratorA()
	{
	}
};

class DecoratorB : public Decorator
{
public:
	DecoratorB(string name,Component * pComponent):Decorator(name,pComponent)
	{
	}

	~DecoratorB()
	{
	}
};

class DecoratorC : public Decorator
{
public:
	DecoratorC(string name,Component * pComponent):Decorator(name,pComponent)
	{
	}

	~DecoratorC()
	{
	}
};

int main()
{
	Component * pComponent  = new ConcreteComponent("Component");
	Component * pDecoratorA = new DecoratorA("DecoratorA",pComponent);
	Component * pDecoratorB = new DecoratorB("DecoratorB",pDecoratorA);
	Component * pDecoratorC = new DecoratorC("DecoratorC",pDecoratorB);
	
	pDecoratorC->Operation();

	if(pDecoratorC)
	{
		delete pDecoratorC;
		pDecoratorC = NULL;
	}

	if(pDecoratorB)
	{
		delete pDecoratorB;
		pDecoratorB = NULL;
	}

	if(pDecoratorA)
	{
		delete pDecoratorA;
		pDecoratorA = NULL;
	}

	if(pComponent)
	{
		delete pComponent;
		pComponent = NULL;
	}

    return 0;
}
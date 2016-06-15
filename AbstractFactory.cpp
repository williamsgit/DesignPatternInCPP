/*
Author  : Williams Ma
Date    : 2016-6-15
Desc    : Abstract Factory Design Pattern
*/

#include <iostream>
using namespace std;

class ProductA
{
public:
	virtual void Show() = 0;
};

class ProductA1 : public ProductA
{
public:
	void Show()
	{
		cout<<"ProductA1 Show"<<endl;
	}
};

class ProductA2 : public ProductA
{
public:
	void Show()
	{
		cout<<"ProductA2 Show"<<endl;
	}
};

class ProductB
{
public:
	virtual void Display() = 0;
};

class ProductB1 : public ProductB
{
public:
	void Display()
	{
		cout<<"ProductB1 Display"<<endl;
	}
};

class ProductB2 : public ProductB
{
public:
	void Display()
	{
		cout<<"ProductB2 Display"<<endl;
	}
};

class Factory
{
public:
	virtual ProductA* CreateProductA() = 0;
	virtual ProductB* CreateProductB() = 0;
};

class FirstFactory : public Factory
{
public:
	ProductA* CreateProductA()
	{
		return new ProductA1();
	}

	ProductB* CreateProductB()
	{
		return new ProductB1();
	}
};

class SecondFactory : public Factory
{
public:
	ProductA* CreateProductA()
	{
		return new ProductA2();
	}

	ProductB* CreateProductB()
	{
		return new ProductB2();
	}
};

void CleanUp(void * ptr)
{
	delete ptr;
	ptr = NULL;
}

int main()
{
	Factory * pFirstFactory = new FirstFactory();
	ProductA* pProductFirstA = pFirstFactory->CreateProductA();
	ProductB* pProductFirstB = pFirstFactory->CreateProductB();
	pProductFirstA->Show();
	pProductFirstB->Display();

	Factory * pSecondFactory = new SecondFactory();
	ProductA* pProductSecondA = pSecondFactory->CreateProductA();
	ProductB* pProductSecondB = pSecondFactory->CreateProductB();
	pProductSecondA->Show();
	pProductSecondB->Display();

	CleanUp(pFirstFactory);
	CleanUp(pProductFirstA);
	CleanUp(pProductFirstB);

	CleanUp(pSecondFactory);
	CleanUp(pProductSecondA);
	CleanUp(pProductSecondB);

	return 0;
}
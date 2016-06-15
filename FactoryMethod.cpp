/*
Author  : Williams Ma
Date    : 2016-6-15
Desc    : Factory Method Design Pattern
*/

#include <iostream>
using namespace std;

class Product
{
public:
	virtual void Show() = 0;
};

class ProductA : public Product
{
public:
	void Show()
	{
		cout<<"I'm ProductA"<<endl;
	}
};

class ProductB : public Product
{
public:
	void Show()
	{
		cout<<"I'm ProductB"<<endl;
	}
};

class Factory
{
public:
	virtual Product* CreateProduct() = 0;
};

class FactroyA : public Factory
{
public:
	Product* CreateProduct()
	{
		return new ProductA();
	}
};

class FactoryB : public Factory
{
public:
	Product* CreateProduct()
	{
		return new ProductB();
	}
};

void CleanUp(void * ptr)
{
	delete ptr;
	ptr = NULL;
}

int main()
{
	Factory * pFactory = NULL;
	Product * pProduct = NULL;

	pFactory = new FactroyA();
	pProduct = pFactory->CreateProduct();
	pProduct->Show();

	CleanUp(pFactory);
	CleanUp(pProduct);

	pFactory = new FactoryB();
	pProduct = pFactory->CreateProduct();
	pProduct->Show();

	CleanUp(pFactory);
	CleanUp(pProduct);
	
	return 0;
}
/*
Author : Williams Ma
Date   : 2016-6-15
Desc   : Simple Factory Disign Pattern
*/

#include <iostream>
using namespace std;

enum ProductType
{
	PRODUCTA,
	PRODCUTB,
	PRODUCTC
};

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

class ProductC : public Product
{
public:
	void Show()
	{
		cout<<"I'm ProductC"<<endl;
	}
};

class Factory
{
public:
	Product * CreateProduct(ProductType type)
	{
		switch (type)
		{
		case PRODUCTA:
			return new ProductA();
			break;

		case PRODCUTB:
			return new ProductB();
			break;

		case PRODUCTC:
			return new ProductC();
			break;

		default:
			return NULL;
			break;
		}
	}
};

int main()
{
	Factory * pFactory = new Factory();
	Product* pProductA = NULL;
	Product* pProductB = NULL;
	Product* pProductC = NULL;
	
	pProductA = pFactory->CreateProduct(PRODUCTA);
	if(pProductA)
		pProductA->Show();

	pProductB = pFactory->CreateProduct(PRODCUTB);
	if(pProductB)
		pProductB->Show();

	pProductC = pFactory->CreateProduct(PRODUCTC);
	if(pProductC)
		pProductC->Show();

	if(pFactory != NULL)
	{
		delete pFactory;
		pFactory = NULL;
	}

	if(pProductA != NULL)
	{
		delete pProductA;
		pProductA = NULL;
	}

	if(pProductB != NULL)
	{
		delete pProductB;
		pProductB = NULL;
	}

	if(pProductC != NULL)
	{
		delete pProductC;
		pProductC = NULL;
	}
}
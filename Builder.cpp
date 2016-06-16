/*
Author  :  Williams Ma
Date    :  2016-6-16
Desc    :  Builder Design Pattern
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product
{
public:
	void AddPart(string part)
	{
		m_allParts.push_back(part);
	}

	void Show()
	{
		vector<string>::iterator iterBegin = m_allParts.begin();
		while(iterBegin != m_allParts.end())
		{
			cout<<*iterBegin<<" ";
			++iterBegin;
		}
		cout<<endl;
	}

private:
	vector<string>  m_allParts;
};

class Builder
{
public:
	virtual void BuildFirstPart() = 0;
	virtual void BuildSecondPart() = 0;
	Product GetProduct()
	{
		return m_product;
	}
protected:
	Product m_product;
};

class FirstBuilder : public Builder
{
public:
	void BuildFirstPart()
	{
		this->m_product.AddPart("A");
	}

	void BuildSecondPart()
	{
		this->m_product.AddPart("B");
	}
};

class SecondBuilder : public Builder
{
	void BuildFirstPart()
	{
		this->m_product.AddPart("One");
	}

	void BuildSecondPart()
	{
		this->m_product.AddPart("Two");
	}
};

class Director
{
public:
	Director(Builder * pBuilder)
	{
		this->m_builder = pBuilder;
	}

	void SetBuilder(Builder * pBuilder)
	{
		this->m_builder = pBuilder;
	}

	void CreateProduct()
	{
		this->m_builder->BuildFirstPart();
		this->m_builder->BuildSecondPart();
	}

	Product GetProduct()
	{
		return this->m_builder->GetProduct();
	}
private:
	Builder * m_builder;
};

void CleanUp(void * ptr)
{
	delete ptr;
	ptr = NULL;
}

int main()
{
	Builder * pFirstBuilder = new FirstBuilder();
	Director director(pFirstBuilder);
	director.CreateProduct();
	director.GetProduct().Show();

	Builder * pSecondBuilder = new SecondBuilder();
	director.SetBuilder(pSecondBuilder);
	director.CreateProduct();
	director.GetProduct().Show();

	CleanUp(pFirstBuilder);
	CleanUp(pSecondBuilder);

	return 0;
}
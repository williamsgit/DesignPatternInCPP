/*
Author  :  Williams Ma
Date    :  2016-6-16
Desc    :  Prototype Design Pattern
*/

#include <iostream>
using namespace std;

class Prototype
{
public:
	virtual Prototype* Clone() = 0;
};

class ConcretePrototype : public Prototype
{
public:
	ConcretePrototype(const char * str)
	{
		this->m_pStr = new char[strlen(str)+1]; 
		strcpy(this->m_pStr,str);
		m_pStr[strlen(str)] = '\0';
	}

	ConcretePrototype(const ConcretePrototype& concretePrototype)
	{
		this->m_pStr = new char[strlen(concretePrototype.m_pStr)+1];
		strcpy(this->m_pStr,concretePrototype.m_pStr);
		this->m_pStr[strlen(concretePrototype.m_pStr)] = '\0';
	}

	Prototype* Clone()
	{
		return new ConcretePrototype(*this);
	}

	void SetString(const char * str)
	{
		strcpy(this->m_pStr,str);
	}

	char* GetString()
	{
		return this->m_pStr;
	}

private:
	char * m_pStr;
};

int main()
{
	ConcretePrototype * pFirstObj = new ConcretePrototype("hello");
	cout<<"current value in original obj: "<<pFirstObj->GetString()<<endl;
	ConcretePrototype * pSecondObj = (ConcretePrototype*)(pFirstObj->Clone());
	cout<<"current value in copy obj: "<<pSecondObj->GetString()<<endl;

	pFirstObj->SetString("Code");
	cout<<"current value in original obj: "<<pFirstObj->GetString()<<endl;
	cout<<"current value in copy obj: "<<pSecondObj->GetString()<<endl;

	return 0;
}
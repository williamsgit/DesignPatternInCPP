/*
Author  :  Williams Ma
Date    :  2016-6-21
Desc    :  Composite Design Pattern
*/

#include <iostream>
#include <string>
#include <list>
using namespace std;

class Component
{
public:
	Component(string name)
	{
		this->name = name;
	}

	virtual ~Component()
	{
	}

	virtual void AddComponent(Component * pComponent) = 0;

	virtual void RemoveComponent(Component * pComponent) = 0;

	virtual void Display() = 0;
protected:
	string name;
};

class Leaf : public Component
{
public:
	Leaf(string name):Component(name)
	{
	}
	
	~Leaf()
	{
	}

	void AddComponent(Component * pComponent)
	{
	}

	void RemoveComponent(Component * pComponent)
	{
	}

	void Display()
	{
		cout<<this->name<<" ";
	}
};

class Composite : public Component
{
public:
	Composite(string name):Component(name)
	{
	}

	~Composite()
	{
	}

	void AddComponent(Component * pComponent)
	{
		this->m_vecComponents.push_back(pComponent);
	}

	void RemoveComponent(Component * pComponent)
	{
		this->m_vecComponents.remove(pComponent);
	}

	void Display()
	{
		list<Component*>::iterator iter = this->m_vecComponents.begin();
		static int index = 1;
		cout<<name<<" ";

		while(iter != this->m_vecComponents.end())
		{
			cout<<"\n"<<string(index,' ');
			(*iter)->Display();
			++iter;
		}

		++index;
	}

private:
	list<Component *> m_vecComponents;
};

int main()
{
	Component * pRoot = NULL;

	pRoot = new Composite("Xi'an OF");
	
	Component * pVSP = new Composite("VSP");
	Component * pDIS = new Leaf("DIS");
	Component * pOFFICE = new Leaf("OFFICE");

	Component * pIDE = new Leaf("IDE");
	Component * pDIAGNOSTIC = new Composite("Diagnostic");

	Component * pDEV = new Leaf("DEV");
	Component * pTEST = new Leaf("TEST");

	pRoot->AddComponent(pVSP);
	pRoot->AddComponent(pOFFICE);
	pRoot->AddComponent(pDIS);

	pVSP->AddComponent(pIDE);
	pVSP->AddComponent(pDIAGNOSTIC);

	pDIAGNOSTIC->AddComponent(pDEV);
	pDIAGNOSTIC->AddComponent(pTEST);

	pRoot->Display();

	return 0;
}
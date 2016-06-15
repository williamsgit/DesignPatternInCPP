/*
Author  : Williams Ma
Date    : 2016-6-15
Desc    : Observer Design Pattern
*/

#include <iostream>
#include <list>
using namespace std;

class Observer;

class Subject
{
public:
	virtual void Attach(Observer * pObserver) = 0;
	virtual void Detach(Observer * pObserver) = 0;
	virtual void SetValue(int value) = 0;
	virtual void Notify() = 0;

protected:
	int m_value; 
	list<Observer*> m_observerList;
};

class ConcreateSubject : public Subject
{
public:
	void Attach(Observer * pObserver)
	{
		m_observerList.push_back(pObserver);
	}

	void Detach(Observer * pObserver)
	{
		m_observerList.remove(pObserver);
	}

	void SetValue(int value)
	{
		m_value = value;
	}

	void Notify();
};

class Observer
{
public:
	virtual void Update(int value) = 0;
};

void ConcreateSubject::Notify()
{
	list<Observer*>::iterator startIter = m_observerList.begin();
	while(startIter != m_observerList.end())
	{
		(*startIter)->Update(m_value);
		startIter++;
	}
}

class ObserverA : public Observer
{
public:
	void Update(int value)
	{
		cout<<"Updated with value of "<<value<<endl;
	}
};

class ObserverB : public Observer
{
public:
	void Update(int value)
	{
		cout<<"Updated with value of "<<value<<endl;
	}
};

class ObserverC : public Observer
{
public:
	void Update(int value)
	{
		cout<<"Updated with value of "<<value<<endl;
	}
};

void CleanUp(void * ptr)
{
	delete ptr;
	ptr = NULL;
}

int main()
{
	Subject * pSubject = new ConcreateSubject();
	Observer* pObserverA = new ObserverA();
	Observer* pObserverB = new ObserverB();
	Observer* pObserverC = new ObserverC();

	pSubject->Attach(pObserverA);
	pSubject->Attach(pObserverB);
	pSubject->Attach(pObserverC);

	pSubject->SetValue(5);
	pSubject->Notify();

	pSubject->Detach(pObserverB);
	pSubject->SetValue(20);
	pSubject->Notify();

	return 0;
}


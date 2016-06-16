/*
Author  :  Williams Ma
Date    :  2016-6-16
Desc    :  Singleton Design Pattern
*/

#include <iostream>
#include <mutex>
using namespace std;

class Singleton
{
public:
	~Singleton()
	{
		cout<<"Singleton destructor"<<endl;
	}

	static Singleton* GetInstance()
	{
		if(m_instance == NULL)
		{
			locker.lock();
			
			if(m_instance == NULL)
				m_instance = new Singleton();
			
			locker.unlock();
		}

		return m_instance; 
	}

	int GetValue()
	{
		return m_value;
	}

private:
	Singleton()
	{
		m_value = 20;
	}

	class GC
	{
	public:
		~GC()
		{
			if(m_instance)
			{
				delete m_instance;
				m_instance = NULL;
			}
		}
	};

	int m_value;
	static Singleton* m_instance;
	static mutex locker;
	static GC gc;
};

Singleton* Singleton::m_instance = NULL;
mutex Singleton::locker;
Singleton::GC Singleton::gc; 

int main()
{
	Singleton* pSingleton = Singleton::GetInstance();
	cout<<pSingleton->GetValue()<<endl;

	return 0;
}
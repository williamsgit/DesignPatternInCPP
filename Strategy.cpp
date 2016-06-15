/*
Author  : Williams Ma
Date    : 2016-6-15
Desc    : Strategy Design Pattern
*/

#include <iostream>
using namespace std;

class Strategy
{
public:
	virtual void Operation() = 0;
	virtual ~Strategy(){}
};

class StrategyA : public Strategy
{
public:
	void Operation()
	{
		cout<<"I'm Strategy A."<<endl;
	}

	~StrategyA()
	{
		cout<<"StrategyA destructor"<<endl;
	}
};

class StrategyB : public Strategy 
{
public:
	void Operation()
	{
		cout<<"I'm Strategy B."<<endl;
	}

	~StrategyB()
	{
		cout<<"StrategyB destructor"<<endl;
	}
};

class StrategyC : public Strategy
{
public:
	void Operation()
	{
		cout<<"I'm Strategy C."<<endl;
	}

	~StrategyC()
	{
		cout<<"StrategyC destructor"<<endl;
	}
};

class Context
{
public:
	Context(Strategy * pStrategy)
	{
		this->m_pStrategy = pStrategy;
	}

	~Context()
	{
		if(m_pStrategy)
		{
			delete m_pStrategy;
			m_pStrategy = NULL;
		}
	}

	void ContextOperation()
	{
		if(m_pStrategy)
		{
			this->m_pStrategy->Operation();
		}
	}

private:
	Strategy* m_pStrategy;
};

void CleanUp(void * ptr)
{
	delete ptr;
	ptr = NULL;
}

enum StrategyType
{
	STRATEGYA,
	STRATEGYB,
	STRATEGYC
};

class Factory
{
public:
	Strategy* CreateStrategy(StrategyType type)
	{
		switch (type)
		{
		case STRATEGYA:
			return new StrategyA();
			break;

		case STRATEGYB:
			return new StrategyB();
			break;

		case STRATEGYC:
			return new StrategyC();
			break;

		default:
			return NULL;
			break;
		}
	}
};

int main()
{
	Context * pContext = NULL;
	Factory * pFactory = new Factory();

	pContext = new Context(pFactory->CreateStrategy(STRATEGYA));
	pContext->ContextOperation();

	pContext = new Context(pFactory->CreateStrategy(STRATEGYB));
	pContext->ContextOperation();

	pContext = new Context(pFactory->CreateStrategy(STRATEGYC));
	pContext->ContextOperation();

	CleanUp(pContext);
	CleanUp(pFactory);

	return 0;
}
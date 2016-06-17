/*
Author  :  Williams Ma
Date    :  2016-6-17
Desc    :  Facade Design Pattern
*/

#include <iostream>
using namespace std;

class SyntaxSystem
{
public:
	void ParseSyntax()
	{
		cout<<"start to parse the syntax"<<endl;
	}
};

class MiddleSystem
{
public:
	void GenerateMiddleCode()
	{
		cout<<"start to gennerate the middle code"<<endl;
	}
};

class AssemblySystem
{
public:
	void GenerateAssemblyCode()
	{
		cout<<"start to generate the assembly code"<<endl;
	}
};

class LinkSystem
{
public:
	void Link()
	{
		cout<<"start to link the code"<<endl;
	}
};

class Facade
{
public:
	void Build()
	{
		cout<<"start to build the whole project"<<endl;
		this->syntaxSystem.ParseSyntax();
		this->middleSystem.GenerateMiddleCode();
		this->assemblySystem.GenerateAssemblyCode();
		this->linkSystem.Link();
	}

protected:
	SyntaxSystem syntaxSystem;
	MiddleSystem middleSystem;
	AssemblySystem assemblySystem;
	LinkSystem linkSystem;
};

int main()
{
	Facade *pFacade = new Facade();
	pFacade->Build();

	if(pFacade)
	{
		delete pFacade;
		pFacade = NULL;
	}

	return 0;
}
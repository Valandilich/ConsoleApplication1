#pragma once
#include<iostream>
using namespace std;
class Base
{
	int m_nBase;
	virtual  void vfun()
	{
		cout << "call Base vfun()" << endl; 
	}
};

class A :public Base
{
	int m_nA;
public:
	void vfun()
	{
		cout << "call A vfun()" << endl;
	}
};

class B :public Base
{
	int m_nB;
public:
	void vfun()
	{
		cout << "call B vfun()" << endl;
	}
};

class C :public A, public B
{
	int m_nC;
public:
	void vfun()
	{
		cout << "call C vfun" << endl;
	}
};


#pragma once
using namespace std;
struct MyLinkNodeS
{
	int value;
	MyLinkNodeS* next;
	MyLinkNodeS()
	{
		value = 0;
		next = 0;
	}
};

class MyLinkList
{
private:
	MyLinkNodeS Head;

public:
	bool AddNode(int a);
	bool RemoveNode(int a);
};
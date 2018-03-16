#pragma once
#include<vector>
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
	MyLinkNodeS* Head;

public:
	MyLinkList() { Head = NULL; }
	bool AddNode(int offset, int value);
	int RemoveNode(int offset);
	bool Reverse();
	void MakeList(vector<int> &input);
};
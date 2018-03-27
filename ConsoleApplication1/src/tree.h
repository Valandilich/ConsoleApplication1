#pragma once
#include<vector>
using namespace std;



struct MyTreeNodeS
{
	int value;
	MyTreeNodeS* Left;
	MyTreeNodeS* Right;
	bool isNULL;
	MyTreeNodeS()
	{
		value = 0;
		isNULL = true;
		Left = Right = nullptr;
	}
	~MyTreeNodeS()
	{
		if (Left)
			delete Left;
		if (Right)
			delete Right;
		Left = Right = nullptr;
	}
};

class MyTreeS
{
public:
	MyTreeS() {};
	~MyTreeS() {};
	MyTreeNodeS & GetRoot() { return Root; };
	bool MakeTree(vector<int> inputList);
	vector<int> preTravel();
	vector<int> midTravel();
	vector<int> postTravel();
	vector<int> SerialOutPut();
	int MaxDeep();
	int MinDeep();
	int NodeNumber();
	void  Rebuild_MidPre(vector<int> &Mid, vector<int>&Pre);
	void Rebuild_MidPost(vector<int> &Mid, vector<int> &Post);
	MyTreeNodeS* getTheLowestRoot(int a, int b);
	void Mirror();
private:
	MyTreeNodeS* getTheLowestRoot_sub(MyTreeNodeS* r, int a, int b);
	MyTreeNodeS* Rebuild_MidPre_Sub(vector<int> &Mid, vector<int>&Pre);
	MyTreeNodeS* Rebuild_MidPost_Sub(vector<int> &Mid, vector<int>&Post);
	void preTravel_sub(MyTreeNodeS * r, vector<int>& re);
	void midTravel_sub(MyTreeNodeS * r, vector<int>& re);
	void postTravel_sub(MyTreeNodeS * r, vector<int>& re);
	void Mirror_sub(MyTreeNodeS * r);
	int MaxDeep_Sub(MyTreeNodeS* root);
	int MinDeep_Sub(MyTreeNodeS* root);
	int NodeNumber_Sub(MyTreeNodeS* root);
private:
	MyTreeNodeS Root;
};
bool isSubTree(MyTreeS &A, MyTreeS &B);
bool isSubTree_sub(MyTreeNodeS* A, MyTreeNodeS* B);


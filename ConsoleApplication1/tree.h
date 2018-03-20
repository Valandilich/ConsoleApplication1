#pragma once
#include<vector>
using namespace std;
template<typename T>
struct MyTreeNode
{
	T Value;
	MyTreeNode* left;
	MyTreeNode* right;
};

template<typename TT>
class MyTree
{
public:
	MyTree();
	~MyTree();
	MyTreeNode<TT>& GetRoot();
	bool MakeTree(vector<TT> inputList);
	vector<TT> preTravel();
	vector<TT> midTravel();
	vector<TT> postTravel();
private:
	MyTreeNode<TT> Root;
};

template<typename TT>
inline MyTreeNode<TT>& MyTree<TT>::GetRoot()
{
	return &Root;
	// TODO: 在此处插入 return 语句
}

template<typename TT>
inline bool MyTree<TT>::MakeTree(vector<TT> inputList)
{
	vector<MyTreeNode<TT>>  optQueue;
	optQueue.push_back(Root);
	vector<TT>::iterator it = inputList.begin();
	while (it != inputList.end())
	{
		;
	}
	
	return false;
}



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
		Left = Right = NULL;
	}
	~MyTreeNodeS()
	{
		if (Left)
			delete Left;
		if (Right)
			delete Right;
		Left = Right = NULL;
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
private:
	MyTreeNodeS Root;
};
bool isSubTree(MyTreeS &A, MyTreeS &B);
bool isSubTree_sub(MyTreeNodeS* A, MyTreeNodeS* B);


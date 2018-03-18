#pragma once
#include<vector>
using namespace std;

struct RBTreeNode
{
	int value;
	RBTreeNode* Left;
	RBTreeNode* Right;
	RBTreeNode* Parent;
	bool isRed;
	RBTreeNode(RBTreeNode& nil)
	{
		value = 0;
		Left = Right = Parent = &nil;
		isRed = true;
	}
};

class RBTree
{
private:
	RBTreeNode NIL;
	RBTreeNode* Root;
private:
	RBTreeNode* Tree_Min_Node();
	RBTreeNode* Tree_Max_Node();
	void Tree_Insert_Fix(RBTreeNode* z);
	void Tree_Delete_Fix(RBTreeNode* z);
	void Node_Left_Rotate(RBTreeNode* z);
	void Node_Right_Rotate(RBTreeNode* z);

public:
	void Insert(RBTreeNode*);
	void Delete(RBTreeNode*);
	RBTreeNode* Find(int n);
};
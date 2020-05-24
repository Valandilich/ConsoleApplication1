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
	int left_sub_node_num;
	int right_sub_node_num;
	RBTreeNode(RBTreeNode& nil)
	{
		value = 0;
		Left = Right = Parent = &nil;
		isRed = true;
	}
	RBTreeNode(int val)
	{
		value = val;
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
	RBTreeNode* Find_in(RBTreeNode* p, int n);
public:
	bool Insert(int data);
    bool Delete(int data);
	RBTreeNode* Find(int n);
};
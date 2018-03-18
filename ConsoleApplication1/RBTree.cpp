#include "stdafx.h"
#include "RBTree.h"

RBTreeNode * RBTree::Tree_Min_Node()
{
	RBTreeNode* p = Root;
	if (p == &NIL)
		return NULL;
	while (p != &NIL)
	{
		p = p->Left;
	}
	return p;
}

RBTreeNode * RBTree::Tree_Max_Node()
{
	RBTreeNode* p = Root;
	if (p == &NIL)
		return NULL;
	while (p->Right != &NIL)
	{
		p = p->Right;
	}
	return p;
}




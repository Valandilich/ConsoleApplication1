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

void RBTree::Node_Left_Rotate(RBTreeNode * z)
{
	RBTreeNode* p = z->Parent;
	RBTreeNode* a = z;
	RBTreeNode* c = a->Right;
	if (p != &NIL)
	{
		if (a == p->Left)
			p->Left = c;
		else
			p->Right = c;
	}
	else
	{
		Root = c;
	}
	a->Parent = c;
	c->Parent = p;

	a->Right = c->Left;
	if(a->Right!=&NIL)
		a->Right->Parent = a;
	c->Left = a;
}

void RBTree::Node_Right_Rotate(RBTreeNode*z)
{
	RBTreeNode* p = z->Parent;
	RBTreeNode* a = z;
	RBTreeNode* b = a->Left;
	if (p != &NIL)
	{
		if (a == p->Left)
			p->Left = b;
		else
			p->Right = b;
	}
	else
	{
		Root = b;
	}
	a->Parent = b;
	b->Parent = p;

	a->Left = b->Right;
	b->Right = a;
	if (a->Left != &NIL)
		a->Left->Parent = a;

}

RBTreeNode* RBTree::Find_in(RBTreeNode * p, int n)
{
	if (p == &NIL)
		return NULL;
	if (p->value == n)
		return p;
	if (n> p->value)
	{
		return Find_in(p->Right, n);
	}
	else
	{
		return Find_in(p->Left, n);
	}
}

RBTreeNode * RBTree::Find(int n)
{
	RBTreeNode* p = Root;
	return Find_in(p, n);
}



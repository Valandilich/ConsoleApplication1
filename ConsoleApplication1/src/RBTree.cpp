
#include "RBTree.h"

RBTreeNode * RBTree::Tree_Min_Node()
{
	RBTreeNode* p = Root;
	if (p == &NIL)
		return nullptr;
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
		return nullptr;
	while (p->Right != &NIL)
	{
		p = p->Right;
	}
	return p;
}

void RBTree::Node_Left_Rotate(RBTreeNode * z)
{
	RBTreeNode* parent = z->Parent;
	RBTreeNode* current = z;
	RBTreeNode* current_right = current->Right;
	curent_right -> Parent = parent;
	{
		current -> Right = current_right -> Left;
		current -> right_sub_node_num = curent_right -> left_sub_node_num;
	}
	if(parent != &NIL){
		Root = curent_right;
	} else if(current == parent->Left){
		parent -> Left = current_right;
	} else {
		parent -> Right = current_right;
	}
	curent_right -> Left = current;
	curent_right -> left_sub_node_num = (curent_right -> Left -> left_sub_node_num +
										curent_right -> Left -> left_sub_node_num + 1);
	curent -> Parent = curent_right;
}

void RBTree::Node_Right_Rotate(RBTreeNode*z)
{
	RBTreeNode* parent = z->Parent;
	RBTreeNode* current = z;
	RBTreeNode* current_left = current->Left;
	{
		current -> Left = current_left -> Right;
		current -> left_sub_node_num = curent_left -> right_sub_node_num;
	}
	if(parent != &NIL){
		Root = current_left;
	} else if(current == parent->Left){
		parent -> Left = current_left;
	} else {
		parent -> Right = current_left;
	}
	current_left -> Right = current;
	current_left -> left_sub_node_num = (current_left -> Left -> left_sub_node_num +
										current_left -> Left -> left_sub_node_num + 1);
	curent -> Parent = current_left;
}

void RBTree::Tree_Insert_Fix(RBTreeNode* node){
	while (node->Parent->isRed == true)
		{
			if (node->Parent == node->Parent->Parent->Left)   //  
			{
				RBTreeNode* uncle = node->Parent->Parent->Right;
				if (uncle->isRed == true)   //插入情况1，z的叔叔y是红色的。  
				{
					node->Parent->isRed = false;
					uncle->isRed = false;
					node->Parent->Parent->isRed = true;
					node = node->Parent->Parent;
				}
				else if (uncle->isRed == false)  //插入情况2：z的叔叔y是黑色的，。  
				{
					if (node == node->Parent->Right) //且z是右孩子  
					{
						node = node->Parent;
						Node_Left_Rotate(node);
					}
					//else                 //插入情况3：z的叔叔y是黑色的，但z是左孩子。  
					//{  
					node->Parent->isRed = false;
					node->Parent->Parent->isRed = true;
					Node_Right_Rotate(node->Parent->Parent);
					//}
				}
			}
			else //这部分是针对为插入情况1中，z的父亲现在作为祖父的右孩子了的情况，而写的。  
				//15 else (same as then clause with "Right" and "Left" exchanged)  
			{
				RBTreeNode* uncle = node->Parent->Parent->Left;
				if (uncle->isRed == true)
				{
					node->Parent->isRed = false;
					uncle->isRed = false;
					uncle->Parent->isRed = true;
					node = node->Parent->Parent;
				}
				else if (uncle->isRed == false)
				{
					if (node == node->Parent->Left)
					{
						node = node->Parent;
						Node_Right_Rotate(node);     //与上述代码相比，左旋改为右旋  
					}
					//else  
					//{  
					node->Parent->isRed = false;
					node->Parent->Parent->isRed = true;
					Node_Left_Rotate(node->Parent->Parent);   //右旋改为左旋，即可。  
					//}  
				}
			}
		}
		m_root->isRed = false;
}

void RBTree::Tree_Delete_Fix(RBTreeNode* node){
	while (node != m_root && node->isRed == false)
		{
			if (node == node->Parent->Left)
			{
				RB_Node* brother = node->Parent->Right;
				if (brother->isRed == true)   //情况1：x的兄弟w是红色的。  
				{
					brother->isRed = false;
					node->Parent->isRed = true;
					Node_Left_Rotate(node->Parent);
				}
				else     //情况2：x的兄弟w是黑色的，  
				{
					if (brother->Left->isRed == false && brother->Right->isRed == false)
						//且w的俩个孩子都是黑色的。  
					{
						brother->isRed = true;
						node = node->Parent;
					}
					else if (brother->Right->isRed == false)
						//情况3：x的兄弟w是黑色的，w的右孩子是黑色（w的左孩子是红色）。  
					{
						brother->isRed = true;
						brother->Left->isRed = false;
						Node_Right_Rotate(brother);
					}
					//else if(brother->Right->isRed == true)  
					//情况4：x的兄弟w是黑色的，且w的右孩子时红色的。  
					//{  
					brother->isRed = node->Parent->isRed;
					node->Parent->isRed = false;
					brother->Right->isRed = false;
					Node_Left_Rotate(node->Parent);
					node = m_root;
					//}  
				}
			}
			else  //下述情况针对上面的情况1中，node作为右孩子而阐述的。  
				//22        else (same as then clause with "Right" and "Left" exchanged)  
				//同样，原理一致，只是遇到左旋改为右旋，遇到右旋改为左旋，即可。其它代码不变。  
			{
				RB_Node* brother = node->Parent->Left;
				if (brother->isRed == true)
				{
					brother->isRed = false;
					node->Parent->isRed = true;
					Node_Right_Rotate(node->Parent);
				}
				else
				{
					if (brother->Left->isRed == false && brother->Right->isRed == false)
					{
						brother->isRed = true;
						node = node->Parent;
					}
					else if (brother->Left->isRed == false)
					{
						brother->isRed = true;
						brother->Right->isRed = false;
						Node_Left_Rotate(brother);
					}
					//else if(brother->Left->isRed==true)  
					//{  
					brother->isRed = node->Parent->isRed;
					node->Parent->isRed = false;
					brother->Left->isRed = false;
					Node_Right_Rotate(node->Parent);
					node = m_root;
					//}  
				}
			}
		}
		m_nullNode->Parent = m_root;   //最后将node置为根结点，  
		node->isRed = false;    //并改为黑色。
}

bool RBTree::Insert(int data){
	RBTreeNode* insert_point = &NIL;
	RBTreeNode* index = Root;
	while(index != &NIL){
		insert_point = index;
		if(data < index -> value){
			index = index -> left;
			insert_point -> left_sub_node_num ++;
		} else if(data >= index -> value){
			index = index -> right;
			insert_point -> right_sub_node_num ++;
		} else {
			while(insert_point != NIL){
				if(insert_point -> Parent){
					if(insert_point == include_point->Left){
						insert_point -> Parent -> left_sub_node_num --;
					} else {
						insert_point -> Parent -> right_sub_node_num --;
					}
				} else {
					break;
				}
			}
			return false;
		}
		RBTreeNode* insert_node = new RBTreeNode(data);
		if(insert_point == &NIL){
			Root = insert_node;
			Root -> Parent = &NIL;
			NIL.Left = Root;
			NIL.Right = Root;
			NIL.Parent = Root;
		} else {
			if(insert_node -> value < insert_point -> value){
				insert_point -> Left = insert_node;
			} else {
				insert_point -> Right = insert_node;
			}
			insert_node -> Parent = insert_point;
		}
		Tree_Insert_Fix(insert_node);
	}
}
RBTreeNode* RBTree::Find_in(RBTreeNode * p, int n)
{
	if (p == &NIL)
		return nullptr;
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




#include "tree.h"

bool MyTreeS::MakeTree(vector<int> inputList)
{
	vector<MyTreeNodeS*>OptQueue;
	OptQueue.push_back(&Root);
	vector<int>::iterator it = inputList.begin();
	while (!inputList.empty())
	{
		it = inputList.begin();
		if (*it != -1)
		{
			(*OptQueue.begin())->value = *it;
			(*OptQueue.begin())->isNULL = false;
		}	
		else
		{
			(*OptQueue.begin())->value = *it;
			(*OptQueue.begin())->isNULL = true;
		}
		if (OptQueue.size() < inputList.size())
		{
			(*OptQueue.begin())->Left = new MyTreeNodeS;
			OptQueue.push_back((*OptQueue.begin())->Left);
		}
		if (OptQueue.size() < inputList.size())
		{
			(*OptQueue.begin())->Right = new MyTreeNodeS;
			OptQueue.push_back((*OptQueue.begin())->Right);
		}
		OptQueue.erase(OptQueue.begin());
		inputList.erase(it);
	}
	vector<MyTreeNodeS*>::iterator itt = OptQueue.begin();
	//while (itt != OptQueue.end())
	//{
	//	delete(*itt);
	//	itt++;
	//}
	OptQueue.clear();
	pruning(&Root);
	return true;
}
void MyTreeS:: preTravel_sub(MyTreeNodeS* r, vector<int>& re)
{
	if (!r)
		return;
	if (r->isNULL)
	{
		re.push_back(0);
		return;
	}
	re.push_back(r->value);
	preTravel_sub(r->Left, re);
	preTravel_sub(r->Right, re);
	return;
	
}
vector<int> MyTreeS::preTravel()
{
	vector<int> result;
	MyTreeNodeS* r = &Root;
	if (!r->isNULL)
		result.push_back(Root.value);
	else
		return result;
	preTravel_sub(r->Left, result);
	preTravel_sub(r->Right, result);

	return result;
}
void MyTreeS:: midTravel_sub(MyTreeNodeS* r, vector<int>&re)
{
	if (!r)
		return;
	midTravel_sub(r->Left, re);
	if (r->isNULL)
	{
		re.push_back(0);
		return;
	}
	re.push_back(r->value);
	midTravel_sub(r->Right, re);
	return;
}
vector<int> MyTreeS::midTravel()
{
	vector<int> result;
	MyTreeNodeS* r = &Root;
	midTravel_sub(r->Left, result);
	if (r->isNULL)
		return result;
	result.push_back(r->value);
	midTravel_sub(r->Right, result);
	return result;
}

void MyTreeS::postTravel_sub(MyTreeNodeS* r, vector<int>& re)
{
	if (!r)
		return;
	postTravel_sub(r->Left, re);
	postTravel_sub(r->Right, re);
	if (r->isNULL)
		re.push_back(0);
	else
		re.push_back(r->value);
	return;
}
vector<int> MyTreeS::postTravel()
{
	vector<int>result;
	MyTreeNodeS*r = &Root;
	if (r->isNULL)
		return result;
	postTravel_sub(r->Left, result);
	postTravel_sub(r->Right, result);
	result.push_back(r->value);
	return result;
}

vector<int> MyTreeS::SerialOutPut()
{
	vector<int> result;
	vector<MyTreeNodeS*>optQueue;
	MyTreeNodeS* r = &Root;
	optQueue.push_back(r);
	while (!optQueue.empty())
	{
		vector<MyTreeNodeS*>::iterator it = optQueue.begin();

		result.push_back((*it)->value);
		if((*it)->Left)
			optQueue.push_back((*it)->Left);
		else
		{
			(*it)->Left = new MyTreeNodeS;
			optQueue.push_back((*it)->Left);
		}
		it = optQueue.begin();
		if ((*it)->Right)
			optQueue.push_back((*it)->Right);
		else
		{
			(*it)->Right = new MyTreeNodeS;
			optQueue.push_back((*it)->Right);
		}
		optQueue.erase(optQueue.begin());
		if (AllEmpty(optQueue))
			break;
	}
	pruning(r);
	return result;
}

int MyTreeS::MaxDeep()
{
	MyTreeNodeS* r = &Root;
	return MaxDeep_Sub(r);
}

int MyTreeS::MinDeep()
{
	MyTreeNodeS* r = &Root;
	return MinDeep_Sub(r);;
}

int MyTreeS::NodeNumber()
{
	MyTreeNodeS* r = &Root;
	return NodeNumber_Sub(r);
}

void MyTreeS::Rebuild_MidPre(vector<int>& Mid, vector<int>& Pre)
{
	MyTreeNodeS* r = Rebuild_MidPre_Sub(Mid, Pre);
	Root.value = r->value;
	Root.Left = r->Left;
	Root.Right = r->Right;
	Root.isNULL = r->isNULL;
	return;
}

void MyTreeS::Rebuild_MidPost(vector<int>& Mid, vector<int>& Post)
{
	vector<int>::reverse_iterator itM = Mid.rbegin();
	vector<int>::reverse_iterator itP = Post.rbegin();
	vector<int> rMid;
	vector<int> rPost;
	while (itM != Mid.rend() && itP != Post.rend())
	{
		rMid.push_back(*itM);
		rPost.push_back(*itP);
		itM++;
		itP++;
	}
	MyTreeNodeS* r = Rebuild_MidPost_Sub(rMid, rPost);
	Root.value = r->value;
	Root.Left = r->Left;
	Root.Right = r->Right;
	Root.isNULL = r->isNULL;
	return;
}

MyTreeNodeS * MyTreeS::getTheLowestRoot(int a, int b)
{
	MyTreeNodeS* r = &Root;
	return getTheLowestRoot_sub(r, a, b);
}

MyTreeNodeS * MyTreeS::getTheLowestRoot_sub(MyTreeNodeS* r, int a, int b)
{
	if (!r)
		return nullptr;
	else if (r->value == a)
		return r;
	else if (r->value == b)
		return r;
	MyTreeNodeS* L = getTheLowestRoot_sub(r->Left, a, b);
	MyTreeNodeS* R = getTheLowestRoot_sub(r->Right, a, b);
	if (L && !R)
		return L;
	else if (!L&&R)
		return R;
	else if (L&& R)
		return r;
	else
		return nullptr;
}

bool isSubTree(MyTreeS & A, MyTreeS & B)
{
	if (B.GetRoot().isNULL || A.GetRoot().isNULL)
		return false;
	return isSubTree_sub(&(A.GetRoot()), &(B.GetRoot())) ||
		isSubTree_sub(A.GetRoot().Left, &(B.GetRoot())) ||
		isSubTree_sub(A.GetRoot().Right,  &(B.GetRoot()));
	return false;
}

MyTreeNodeS* MyTreeS::Rebuild_MidPre_Sub(vector<int>& Mid, vector<int>& Pre)
{
	if (Mid.size() < 1 || Pre.size() < 1)
	{
		return nullptr;
	}
	if (Mid.size() != Pre.size())
		return nullptr;
	vector<int> LMid;
	vector<int> LPre;
	vector<int> RMid;
	vector<int> RPre;
	int i = 0;
	while (Mid.at(i) != Pre.at(0) && i<Mid.size())
	{
		LMid.push_back(Mid.at(i));
		LPre.push_back(Pre.at(i + 1));
		i++;
	}
	MyTreeNodeS* r = new MyTreeNodeS();
	r->value = Pre.at(0);
	r->isNULL = false;
	i+=1;
	while (i < Pre.size() && i<Mid.size())
	{
		RPre.push_back(Pre.at(i));
		RMid.push_back(Mid.at(i));
		i++;
	}
	r->Left = Rebuild_MidPre_Sub(LMid, LPre);
	r->Right = Rebuild_MidPre_Sub(RMid, RPre);
	return r;
}

void MyTreeS::Mirror_sub(MyTreeNodeS*r)
{
	if (!r)
		return;
	Mirror_sub(r->Left);
	Mirror_sub(r->Right);
	MyTreeNodeS* temp = r->Left;
	r->Left = r->Right;
	r->Right = temp;
	return;
}
int MyTreeS::MaxDeep_Sub(MyTreeNodeS * root)
{
	if (!root)
		return 0;
	int Left = MaxDeep_Sub(root->Left);
	int Right = MaxDeep_Sub(root->Right);
	return Left>Right?(Left+1):(Right+1);
}
int MyTreeS::MinDeep_Sub(MyTreeNodeS * root)
{
	if (!root)
		return 0;
	int Left = MaxDeep_Sub(root->Left);
	int Right = MaxDeep_Sub(root->Right);
	return Left < Right ? (Left + 1) : (Right + 1);
}
int MyTreeS::NodeNumber_Sub(MyTreeNodeS * root)
{
	if (!root)
		return 0;
	int Left = NodeNumber_Sub(root->Left);
	int Right = NodeNumber_Sub(root->Right);
	return Left + Right +1;
}
bool MyTreeS::isBallence_Sub(MyTreeNodeS * root)
{
	if (!root)
		return true;
	bool isL = isBallence_Sub(root->Left);
	bool isR = isBallence_Sub(root->Right);
	if (!isL || !isR)
		return false;
	int L = MaxDeep_Sub(root->Left);
	int R = MaxDeep_Sub(root->Right);
	if (L - R > 1 || R - L > 1)
		return false;
	return true;
}
bool MyTreeS::isComplete_Sub(MyTreeNodeS * root)
{
	if (!root)
		return true;
	bool LC = isComplete_Sub(root->Left);
	bool LR = isComplete_Sub(root->Right);
	if (!LC || !LR)
		return false;
	if (root->Right && !root->Left)
		return false;
	bool B = isBallence_Sub(root);
	return B;
}
bool MyTreeS::pruning(MyTreeNodeS * root)
{
	if (root->isNULL)
		return false;
	else
	{
		if (!root->Left)
			;
		else if(!(root->Left->isNULL))
			pruning(root->Left);
		else
		{
			delete (root->Left);
			root->Left = NULL;
		}
		if (!root->Right)
			;
		else if(!(root->Right->isNULL))
			pruning(root->Right);
		else
		{
			delete (root->Right);
			root->Right = NULL;
		}
	}
	return true;
}
bool MyTreeS::AllEmpty(vector<MyTreeNodeS*>& vqueue)
{
	vector<MyTreeNodeS*>::iterator it = vqueue.begin();
	while (it != vqueue.end())
	{
		if (!((*it)->isNULL))
			return false;
		it++;
	}
	return true;
}
bool isSubTree_sub(MyTreeNodeS * A, MyTreeNodeS * B)
{
	if (!B)
		return true;
	if (!A)
		return false;
	if (A->value == B->value)
		return (isSubTree_sub(A->Left, B->Left) && isSubTree_sub(A->Right, B->Right));
	return false;
}
bool isSame(MyTreeS & A, MyTreeS & B)
{
	if (B.GetRoot().isNULL || A.GetRoot().isNULL)
		return false;
	return isSame_Sub(&(A.GetRoot()), &(B.GetRoot()));
}
bool isSame_Sub(MyTreeNodeS * A, MyTreeNodeS * B)
{
	if(A->value != B->value)
		return false;
	bool SameLeft = isSame_Sub(A->Left, B->Left);
	if (!SameLeft)
		return false;
	bool SameRight = isSame_Sub(A->Right,B->Right);
	if (!SameRight)
		return false;
	return true;
}
void MyTreeS::Mirror()
{
	MyTreeNodeS* r = &Root;
	if (r->isNULL)
		return;
	Mirror_sub(r);
	return;
}

bool MyTreeS::isBallence()
{
	MyTreeNodeS* r = &Root;
	return isBallence_Sub(r);
}

bool MyTreeS::isComplete()
{
	MyTreeNodeS* r = &Root;
	return isComplete_Sub(r);
}

MyTreeNodeS* MyTreeS::Rebuild_MidPost_Sub(vector<int>& Mid, vector<int>& Post)
{
	if (Mid.size() < 1 || Post.size() < 1)
	{
		return nullptr;
	}
	if (Mid.size() != Post.size())
		return nullptr;
	vector<int> LMid;
	vector<int> LPre;
	vector<int> RMid;
	vector<int> RPre;
	int i = 0;
	while (Mid.at(i) != Post.at(0) && i<Mid.size())
	{
		RMid.push_back(Mid.at(i));
		RPre.push_back(Post.at(i + 1));
		i++;
	}
	MyTreeNodeS* r = new MyTreeNodeS();
	r->value = Post.at(0);
	r->isNULL = false;
	i += 1;
	while (i < Post.size() && i<Mid.size())
	{
		LPre.push_back(Post.at(i));
		LMid.push_back(Mid.at(i));
		i++;
	}
	r->Left = Rebuild_MidPost_Sub(LMid, LPre);
	r->Right = Rebuild_MidPost_Sub(RMid, RPre);
	return r;
}

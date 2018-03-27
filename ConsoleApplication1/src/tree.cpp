
#include "tree.h"

bool MyTreeS::MakeTree(vector<int> inputList)
{
	vector<MyTreeNodeS*>OptQueue;
	OptQueue.push_back(&Root);
	vector<int>::iterator it = inputList.begin();
	while (!inputList.empty())
	{
		it = inputList.begin();
		(*OptQueue.begin())->value = *it;
		(*OptQueue.begin())->isNULL = false;
		if(OptQueue.size()<inputList.size())
		{
			(*OptQueue.begin())->Left = new MyTreeNodeS;
			OptQueue.push_back((*OptQueue.begin())->Left);
		}
		if (OptQueue.size()<inputList.size())
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
		if ((*it)->isNULL)
			break;
		result.push_back((*it)->value);
		if((*it)->Left)
			optQueue.push_back((*it)->Left);
		it = optQueue.begin();
		if ((*it)->Right)
			optQueue.push_back((*it)->Right);
		optQueue.erase(optQueue.begin());
	}
	return result;
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
void MyTreeS::Mirror()
{
	MyTreeNodeS* r = &Root;
	if (r->isNULL)
		return;
	Mirror_sub(r);
	return;
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

#include "stdafx.h"
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
void preTravel_sub(MyTreeNodeS* r, vector<int>& re)
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
void midTravel_sub(MyTreeNodeS* r, vector<int>&re)
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

void postTravel_sub(MyTreeNodeS* r, vector<int>& re)
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

void Mirror_sub(MyTreeNodeS*r)
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
void MyTreeS::Mirror()
{
	MyTreeNodeS* r = &Root;
	if (r->isNULL)
		return;
	Mirror_sub(r);
	return;
}

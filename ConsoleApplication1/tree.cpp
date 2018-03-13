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

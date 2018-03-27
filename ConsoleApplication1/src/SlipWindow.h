#pragma once
#include <vector>
using namespace std;

int max(vector<int> a)
{
	vector<int>::iterator it = a.begin();
	int maxxx = *it;
	while (it != a.end())
	{
		if (maxxx < *it)
			maxxx = *it;
		it++;
	}
	return maxxx;
}
vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
	vector<int> reresult;
	if (num.size() < size)
		return reresult;
	vector<int> window;
	vector<int>::const_iterator itnum = num.begin();
	while (window.size() < size)
	{
		window.push_back(*itnum);
		itnum++;
	}
	if (window.empty())
		return reresult;
	reresult.push_back(max(window));
	while (itnum != num.end())
	{
		window.push_back(*itnum);
		window.erase(window.begin());
		reresult.push_back(max(window));
		itnum++;
	}
	return reresult;
}
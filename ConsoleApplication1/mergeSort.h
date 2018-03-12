#pragma once
#include<vector>
using namespace std;
bool split(vector<int>&input, vector<int>&left, vector<int>&right)
{
	int l = input.size();
	for (int i = 0; i < l / 2; i++)
	{
		left.push_back(input[i]);
	}
	for (int i = l / 2; i < l; i++)
	{
		right.push_back(input[i]);
	}
	return true;
}

bool MyMerge(vector<int> &input, vector<int>&left, vector<int>&right)
{
	input.clear();
	vector<int>::iterator itleft = left.begin();
	vector<int>::iterator itright = right.begin();
	while (itleft != left.end() && itright != right.end())
	{
		if (*itleft <= *itright)
		{
			input.push_back(*itleft);
			itleft++;
		}
		else
		{
			input.push_back(*itright);
			itright++;
		}
	}
	while (itleft != left.end())
	{
		input.push_back(*itleft);
		itleft++;
	}
	while (itright != right.end())
	{
		input.push_back(*itright);
		itright++;
	}
	return true;
}
bool mergeSort(vector<int> &input)
{
	if (input.size() < 2)
		return false;
	vector<int>left;
	vector<int>right;
	split(input, left, right);
	mergeSort(left);
	mergeSort(right);

	MyMerge(input, left, right);
	return true;
}


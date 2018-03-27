#pragma once
#include<vector>
using namespace std;
//bool split(vector<int>&input, vector<int>&left, vector<int>&right)
//{
//	int l = input.size();
//	for (int i = 0; i < l / 2; i++)
//	{
//		left.push_back(input[i]);
//	}
//	for (int i = l / 2; i < l; i++)
//	{
//		right.push_back(input[i]);
//	}
//	return true;
//}
//
//bool MyMerge(vector<int> &input, vector<int>&left, vector<int>&right)
//{
//	input.clear();
//	vector<int>::iterator itleft = left.begin();
//	vector<int>::iterator itright = right.begin();
//	while (itleft != left.end() && itright != right.end())
//	{
//		if (*itleft <= *itright)
//		{
//			input.push_back(*itleft);
//			itleft++;
//		}
//		else
//		{
//			input.push_back(*itright);
//			itright++;
//		}
//	}
//	while (itleft != left.end())
//	{
//		input.push_back(*itleft);
//		itleft++;
//	}
//	while (itright != right.end())
//	{
//		input.push_back(*itright);
//		itright++;
//	}
//	return true;
//}
//bool mergeSort(vector<int> &input)
//{
//	if (input.size() < 2)
//		return false;
//	vector<int>left;
//	vector<int>right;
//	split(input, left, right);
//	mergeSort(left);
//	mergeSort(right);
//
//	MyMerge(input, left, right);
//	return true;
//}
//
vector<int> merge(vector<int> &Left, vector<int> &Right)
{
	vector<int>result;
	vector<int>::iterator itL = Left.begin();
	vector<int>::iterator itR = Right.begin();
	while (itL != Left.end() && itR != Right.end())
	{
		if (*itL <= *itR)
		{
			result.push_back(*itL);
			itL++;
		}
		else
		{
			result.push_back(*itR);
			itR++;
		}
	}
	while (itL != Left.end())
	{
		result.push_back(*itL);
		itL++;
	}
	while (itR != Right.end())
	{
		result.push_back(*itR);
		itR++;
	}
	return result;
}
vector<int> mergesort(vector<int> &input, int head, int tail)
{
	vector<int>result;
	if (tail - head < 1)
	{
		result.push_back(input[head]);
		return result;
	}
		
	int mid = (tail + head) / 2;
	vector<int> Left = mergesort(input, head, mid);
	vector<int> Right = mergesort(input, mid + 1, tail);
	result = merge(Left, Right);
	return result;
}
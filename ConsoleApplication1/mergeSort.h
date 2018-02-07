#pragma once
#include<vector>
using namespace std;
vector<int> mergeSort(vector<int> input)
{
	if (input.size() < 2)
		return input;
	int l = input.size();
	vector<int>left;
	vector<int>right;
	for (int i = 0; i < l/2; i++)
	{
		left.push_back(input[i]);
	}
	for (int i = l / 2; i < l; i++)
	{
		right.push_back(input[i]);
	}
	left = mergeSort(left);
	right = mergeSort(right);

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
	return input;
}

void swap(vector<int> &arr, int a, int b)
{
	int t = arr[a];
	arr[a] = arr[b];
	arr[b] = t;
}
void QuickSort(vector<int> &input, int head, int tail)
{
	if (head >= tail)
		return;
	int p = head;
	int q = tail;
	while (p < q)
	{
		while (p<=tail && input[head] >= input[p])
			p++;
		while (q>=head && input[head] < input[q])
			q--;
		if (p < q)
		{
			swap(input, p, q);
			p++;
			q--;
		}
	}
	if (input[head] > input[p])
		swap(input, head, p);
	else
		swap(input, head, p - 1);
	QuickSort(input, head, p-1);
	QuickSort(input, p + 1, tail);
}
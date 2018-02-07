#pragma once
#include<vector>
using namespace std;

int heap_go_left(int i)
{
	return(i + 1) * 2 -1;
}

int heap_go_right(int i)
{
	return(i + 1) * 2;
}

int heap_go_parent(int i)
{
	return (i-1)/2;
}
void heap_shiftdown(vector<int> &a, int i)
{
	int L = heap_go_left(i);
	int R = heap_go_right(i);
	int Largest;
	if (L < a.size() && a[L] > a[i])
		Largest = L;
	else
		Largest = i;
	if (R<a.size() && a[R]>a[Largest])
		Largest = R;
	if (Largest != i)
	{
		int tt = a[Largest];
		a[Largest] = a[i];
		a[i] = tt;
		heap_shiftdown(a, Largest);
	}
}

void heap_insert(vector<int> &a, int i)
{
	a.push_back(i);
	int curr = a.size() - 1;
	while (curr != 0 && a[curr] > a[heap_go_parent(curr)])
	{
		int tt = a[curr];
		a[curr] = a[heap_go_parent(curr)];
		a[heap_go_parent(curr)] = tt;
		curr = heap_go_parent(curr);
	}
}
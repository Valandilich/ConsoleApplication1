#pragma once
#include<vector>
using namespace std;

bool MySwap(vector<int> &inPut, int a, int b)
{
	if (a > inPut.size() - 1 || b > inPut.size() - 1)
		return false;
	int t = inPut[a];
	inPut[a] = inPut[b];
	inPut[b] = t;
}
int Devide(vector<int> &inPut, int head, int tail)
{
	int mid = inPut.at(head);
	int m_head = head;
	int m_tail = tail;
	while (m_head < m_tail)
	{
		while (m_head <= m_tail && inPut.at(m_head) <= mid)
			m_head++;
		while (m_head < m_tail && inPut.at(m_tail) > mid)
			m_tail--;
		if (!(m_head < m_tail))
			break;
		MySwap(inPut, m_head, m_tail);
		m_head++;
		m_tail--;
	}
	if (m_head>tail || mid < inPut.at(m_head))
		return m_head - 1;
	else
		return m_head;
}

void quickSort(vector<int> &inPut,int head,int tail)
{
	if (tail-head<1)
		return;
	int m_head = Devide(inPut, head, tail);
	MySwap(inPut, m_head, head);
	quickSort(inPut, head, m_head-1);
	quickSort(inPut, m_head+1, tail);
	return;
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
		while (p <= tail && input[head] >= input[p])
			p++;
		while (q >= head && input[head] < input[q])
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
	QuickSort(input, head, p - 1);
	QuickSort(input, p + 1, tail);
}
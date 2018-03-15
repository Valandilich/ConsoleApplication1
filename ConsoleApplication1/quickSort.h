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
	return true;
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

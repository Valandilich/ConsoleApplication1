#pragma once
#include<vector>
using namespace std;
void quickSort(vector<int> &inPut,int head,int tail)
{
	if (tail-head<1)
		return;
	int mid = inPut.at(head);
	int m_head = head;
	int m_tail = tail;
	while (m_head < m_tail)
	{
		while (inPut.at(m_head) <=mid&&m_head < m_tail)
			m_head++;
		while (inPut.at(m_tail) > mid &&m_head < m_tail)
			m_tail--;
		if (!(m_head < m_tail))
			break;
		int t = inPut[m_head];
		inPut[m_head] = inPut[m_tail];
		inPut[m_tail] = t;
		m_head++;
		m_tail--;
	}
	if (inPut[m_head] > mid)
		m_head--;
	int t = inPut[m_head];
	inPut[m_head] = inPut[head];
	inPut[head] = t;
	quickSort(inPut, head, m_head-1);
	quickSort(inPut, m_head+1, tail);
	return;
}
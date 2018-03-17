#pragma once
#include<vector>
using namespace std;

//bool MySwap(vector<int> &inPut, int a, int b)
//{
//	if (a > inPut.size() - 1 || b > inPut.size() - 1)
//		return false;
//	int t = inPut[a];
//	inPut[a] = inPut[b];
//	inPut[b] = t;
//	return true;
//}
//int Devide(vector<int> &inPut, int head, int tail)
//{
//	int mid = inPut.at(head);
//	int m_head = head;
//	int m_tail = tail;
//	while (m_head < m_tail)
//	{
//		while (m_head <= m_tail && inPut.at(m_head) <= mid)
//			m_head++;
//		while (m_head < m_tail && inPut.at(m_tail) > mid)
//			m_tail--;
//		if (!(m_head < m_tail))
//			break;
//		MySwap(inPut, m_head, m_tail);
//		m_head++;
//		m_tail--;
//	}
//	if (m_head>tail || mid < inPut.at(m_head))
//		return m_head - 1;
//	else
//		return m_head;
//}
//void quickSort(vector<int> &inPut,int head,int tail)
//{
//	if (tail-head<1)
//		return;
//	int m_head = Devide(inPut, head, tail);
//	MySwap(inPut, m_head, head);
//	quickSort(inPut, head, m_head-1);
//	quickSort(inPut, m_head+1, tail);
//	return;
//}
bool myswap(vector<int>& input, int a, int b)
{
	int l = input.size() - 1;
	if (a > l || b > l)
		return false;
	int temp = input.at(a);
	input[a] = input[b];
	input[b] = temp;
	return true;
}

int mydevide(vector<int>& input, int head, int tail)
{
	int mid = input.at(head);
	int m_head = head;
	int m_tail = tail;
	while (m_head < m_tail)
	{
		while (m_head < m_tail&&input.at(m_head) <= mid)
			m_head++;
		while (m_head < m_tail&&input.at(m_tail) > mid)
			m_tail--;
		if (input.at(m_head) > input.at(m_tail))
		{
			myswap(input, m_head, m_tail);
			m_head++;
			m_tail--;
		}
	}
	if (input.at(m_head) > mid)
	{
		myswap(input, head, m_head - 1);
		return m_head - 1;
	}
	else
	{
		myswap(input, head, m_head);
		return m_head;
	}
}

void myquicksort(vector<int> &input, int head, int tail)
{
	if (tail - head < 1)
		return;
	int mid = mydevide(input, head, tail);
	myquicksort(input, head, mid - 1);
	myquicksort(input, mid + 1, tail);
	return;
}
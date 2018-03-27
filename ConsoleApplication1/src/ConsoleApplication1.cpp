// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "mergeSort.h"
#include <stdio.h>
#include <iostream>
#include<vector>
#include<map>
#include<string>
#include <algorithm>
#include "SlipWindow.h"
#include "heap.h"
#include "quickSort.h"
#include "tree.h"
#include <functional>
#include "search.h"
#include "LinkList.h"
#include "virtual.h"
#include "myString.h"
#include"KMP.h"
using namespace std;
typedef map<char, vector<char>> SPEPAIR;


//vector<char> makeStr2Vec(string instr)
//{
//	vector<char> outstr;
//	int l = instr.length() ;
//	for (int i = 0; i < l; i++)
//	{
//		outstr.push_back(instr[i]);
//	}
//	return outstr;
//}
//SPEPAIR split_string(vector<char>input)
//{
//	SPEPAIR res;
//	int l = input.size();
//	for(int i = 0; i < l; i++)
//	{ 
//		char f = input[i];
//		vector<char> tail;
//		for (int j = 0; j < l; j++)
//		{
//			if (i == j)
//				continue;
//			else
//			{
//				tail.push_back(input[j]);
//			}
//		}
//		res.insert(pair<char, vector<char>>(f, tail));
//	}
//	return res;
//}
//vector<string> Permutation(vector<char> T)
//{
//	vector<string> resu;
//	if (T.size() < 1)
//		return resu;
//	SPEPAIR Pairs = split_string(T);
//	SPEPAIR::iterator it = Pairs.begin();
//	while (it != Pairs.end())
//	{
//		vector<string> resultsubstr = Permutation(it->second);
//		vector<string>::iterator itt = resultsubstr.begin();
//		if (itt == resultsubstr.end())
//		{
//			string ttemp = "";
//			char tttt = it->first;
//			ttemp += tttt;
//			resu.push_back(ttemp);
//		}
//		else
//		{
//			while (itt != resultsubstr.end())
//			{
//				string ttemp = it->first + (*itt);
//				resu.push_back(ttemp);
//				itt++;
//			}
//		}
//		it++;
//	}
//	return resu;
//}
//bool meanSmall(int a, int b)
//{
//	double meanA = 0;
//	int i = 0;
//	while (a > 0)
//	{
//		meanA += a % 10;
//		a /= 10;
//		i++;
//	}
//
//	double meanB = 0;
//	int j = 0;
//	while (b > 0)
//	{
//		meanB += b % 10;
//		b /= 10;
//		j++;
//	}
//	meanA /= i;
//	meanB /= j;
//	return meanA < meanB;
//}
//int GetUglyNumber_Solution(int index) {
//	int N = 1;
//	for (long i = 2;; i++)
//	{
//		long j = i;
//		while (j % 2 == 0)
//		{
//			j /= 2;
//		}
//		while (j % 3 == 0)
//		{
//			j /= 3;
//		}
//		while (j % 5 == 0)
//		{
//			j /= 5;
//		}
//		if (j == 1)
//			N++;
//		if (N == index)
//			return i;
//	}
//}
int main()
{
 	vector<int> a = { 4,1,5,2,9,8,7,6,3};
	vector<int> n;
	string s = "abeacdabcde";
	int *nn = new int[s.length()];
	getNext(s.c_str(), nn);
	for (int i = 0; i < s.length(); i++)
	{
		n.push_back(nn[i]);
	}

 	MyTreeS ATree;
 	ATree.MakeTree(a);
	MyTreeNodeS* re = ATree.getTheLowestRoot(6,7);
 	//vector<int>b = ATree.preTravel();
 	//vector<int>c = ATree.midTravel();
 	//vector<int>d = ATree.postTravel();
 	//vector<int>e = ATree.SerialOutPut();
 	//MyTreeS BTree;
 	//BTree.MakeTree(b);
 	//MyTreeS CTree;
 	//CTree.Rebuild_MidPost(c, d);
 	//vector<int>BB = BTree.SerialOutPut();
 	//vector<int>CC = CTree.SerialOutPut();
	//bool bbb = isSubTree(ATree, BTree);
	//MyLinkList AList;
	//AList.MakeList(a);
	//AList.RemoveNode(0);
	//vector<int>c = AList.ListPrint();
	//AList.Reverse();
	return 0;
}


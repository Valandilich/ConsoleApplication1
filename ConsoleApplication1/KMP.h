#pragma once
#include <string>
using namespace std;
void getNext(const char *p, int *next)
{
	int j, k;
	next[0] = -1;
	j = 0;
	k = -1;
	while (j<strlen(p) - 1)
	{
		if (k == -1 || p[j] == p[k])    //匹配的情况下,p[j]==p[k]
		{
			j++;
			k++;
			next[j] = k;
		}
		else                   //p[j]!=p[k]
			k = next[k];
	}
}

int KMPMatch(char *s, char *p)
{
	int *next;
	int i, j;
	i = 0;
	j = 0;
	next = new int[strlen(p)];
	getNext(p, next);
	while (i<strlen(s))
	{
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];       //消除了指针i的回溯
		}
		if (j == strlen(p))
			return i - strlen(p);
	}
	return -1;
}
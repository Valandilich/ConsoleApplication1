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
		if (k == -1 || p[j] == p[k])    //ƥ��������,p[j]==p[k]
		{
			j++;
			k++;
			next[j] = k;
		}
		else                   //p[j]!=p[k]
			k = next[k];
	}
}
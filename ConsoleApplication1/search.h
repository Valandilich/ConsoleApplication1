#pragma once
#include<vector>
using namespace std;

int BinarySearch(vector<int>& input, int head, int tail, int &Num)
{
	if (tail - head < 1)
	{
		if (input.at(head) != Num  && input.at(tail) != Num)
			return -1;
		else
			return tail;
	}
	int mid = (tail + head)/2;
	int result = -1;
	if (input.at(mid) == Num)
		result = mid;
	else if (input.at(mid) > Num)
		result = BinarySearch(input, head, mid - 1, Num);
	else
		result = BinarySearch(input, mid + 1, tail, Num);
	return result;
}

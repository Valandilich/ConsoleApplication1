#include<vector>
#include <algorithm>
using namespace std;
class Solution
{
	vector<int> DataStream;
public:
	void Insert(int num)
	{
		// write code here
		DataStream.push_back(num);
	}

	double GetMedian()
	{
		// write code here
		sort(DataStream.begin(), DataStream.end(), less<int>());
		if ((DataStream.size() & 1) == 1)
			return DataStream.at(DataStream.size() / 2);
		else
			return (DataStream.at(DataStream.size()) + DataStream.at(DataStream.size() + 1)) / 2;
	}
};
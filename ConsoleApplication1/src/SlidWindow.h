#include <iostream>
#include <set>
#include <vector>
#include  <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <sys/time.h>
using std::vector;
using std::cout;
using std::endl;
using std::unordered_map;
using std::unordered_set;
int getPosD(vector<int>& A, int head, int tail, int key) {
	if (tail - head < 1 && A[head] != key) {
		if (A[head] < key) {
			return head + 1;
		}
		else {
			return head;
		}
	}
	else if (A[head] == key) {
		return head;
	}
	int mid = ((tail - head) >> 1) + head;
	if (A[mid] == key && A[mid - 1] != key) {
		return mid;
	}
	else if (A[mid] >= key) {
		return getPosD(A, head, mid, key);
	}
	else {
		return getPosD(A, mid + 1, tail, key);
	}
}
int getPos(vector<int> A, int n, int val) {
	// write code here
	return getPosD(A, 0, n - 1, val);
}
int64_t UNow() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000UL + tv.tv_usec;
}
bool DataCreator(std::vector<int>& data, int n)
{
	data.clear();
	data.reserve(n);
	for (int i = 0; i < n; i++)
		data.push_back(i);
	std::random_shuffle(data.begin(), data.end());
	return true;
}

class TheWindow {
public:
	TheWindow() :win_size_(100) {};
	TheWindow(int size) :win_size_(size) {};
	bool append(int num_) {
		if (window_.size() >= win_size_) {
			int old = window_.front();
			sortor_.erase(old);
			window_.pop();
		}
		window_.push(num_);
		sortor_.insert(num_);
	}
	int get_xth(int xth) {
		if (xth > window_.size())
			return -1;
		else {
			std::set<int>::iterator it = sortor_.begin();
			for (int i = 0; i < xth; i++) {
				it++;
			}
			return *it;
		}
	}
	void PrintSorter() {
		for (auto it : sortor_) {
			cout << it << ",";
		}
		cout << endl;
	}
private:
	size_t win_size_;
	std::queue<int> window_;
	std::set<int> sortor_;
};


class TheWindow2 {
public:
	TheWindow2() :win_size_(100) {};
	TheWindow2(int size) :win_size_(size) {};
	bool append(int num_) {
		if (window_.size() >= win_size_) {
			int old = window_.front();
			int offset = getPosD(sortor_, 0, sortor_.size() - 1, old);
			sortor_.erase(sortor_.begin() + offset);
			window_.pop();
		}
		window_.push(num_);
		if (sortor_.empty()) {
			sortor_.push_back(num_);
		}
		else {
			auto offset = getPosD(sortor_, 0, sortor_.size() - 1, num_);
			sortor_.insert(sortor_.begin() + offset, num_);
		}

	}
	int get_xth(int xth) {
		if (xth > sortor_.size() - 1) {
			return -1;
		}
		else {
			return sortor_[xth];
		}
	}
	void PrintSorter() {
		for (auto it : sortor_) {
			cout << it << ",";
		}
		cout << endl;
	}
private:
	size_t win_size_;
	std::queue<int> window_;
	std::vector<int> sortor_;
};


int test() {
	int c = 0;
	uint64_t t3 = 0;
	uint64_t t4 = 0;
	for (int cc = 0; cc < 1; cc++)
	{
		std::vector<int> testData;
		DataCreator(testData, 10000000);

		auto t31 = UNow();
		TheWindow tw1(10);
		for (auto it : testData) {
			tw1.append(it);
		}
		t3 += UNow() - t31;
		auto t41 = UNow();
		TheWindow2 tw2(10);
		for (auto it : testData) {
			tw2.append(it);
		}
		t4 += UNow() - t41;
		//tw1.PrintSorter();
		//tw2.PrintSorter();
	}
	cout << t1 << " " << t2 << " " << t3 << " " << t4 << endl;
	return 0;
}

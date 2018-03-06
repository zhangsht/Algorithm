#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>

using namespace std;

struct Interval {
	int start, end;
	Interval(int _start, int _end) :
		start(_start), end(_end) {}
};

class Solution {
public:
	vector<int> findRightInterval(vector<Interval>& intervals) {
		int n = intervals.size();
		map<int, int> time;
		vector<int> res;

		for (int i = 0; i < n; i++) {
			time[intervals[i].start] = i;
		}

		for (int i = 0; i < n; i++) {
			auto it = time.lower_bound(intervals[i].end);
			if (it == time.end()) {
				res.push_back(-1);
			} else {
				res.push_back(it->second);
			}
		}
		return res;
	}
};

//int main() {
//	Solution s;
//	Interval in(1, 2);
//	vector<Interval> v;
//	v.push_back(in);
//	vector<int> res =  s.findRightInterval(v);
//	for (int i = 0; i < res.size(); i++) {
//		cout << res[i] << ' ';
//	}
//	system("pause");
//	return 0;
//}
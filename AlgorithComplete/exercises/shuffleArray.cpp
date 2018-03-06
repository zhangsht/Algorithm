#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	Solution(vector<int> nums) : v(nums) {
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return v;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> ans = v;
		for (int i = 0, len = v.size(); i < len; i++) {
			int j = rand() % len;
			swap(ans[i], ans[j]);
		}
		return ans;
	}
private:
	vector<int> v;
};


class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		if (nums.empty() || minStack.top() >= x) minStack.push(x);

		nums.push(x);
	}

	void pop() {
		if (!nums.empty()) {
			if (nums.top() == minStack.top()) {
				minStack.pop();
			}
			nums.pop();
		}
	}

	int top() {
		return nums.top();
	}

	int getMin() {
		return minStack.top();
	}
private:
	stack<int> nums;
	stack<int> minStack;
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(nums);
* vector<int> param_1 = obj.reset();
* vector<int> param_2 = obj.shuffle();
*/
//
//int main() {
//	/*vector<int> nums;
//	nums.push_back(1);
//	nums.push_back(2);
//	nums.push_back(3);
//
//	Solution obj = Solution(nums);
//	vector<int> param_1 = obj.reset();
//	for (int a : param_1) cout << a << ' ';
//	cout << endl;
//	vector<int> param_2 = obj.shuffle();
//	for (int a : param_2) cout << a << ' ';
//	cout << endl;*/
//
//    MinStack  sta = MinStack();
//	sta.push(-2);
//	cout << sta.top() << endl;
//
//	sta.push(0);
//	cout << sta.top() << endl;
//
//	sta.push(-3);
//	cout << sta.top() << endl;
//	cout << "push end\n";
//
//	cout << sta.top() << endl;
//	cout << sta.getMin() << endl;
//	sta.pop();
//	cout << sta.top() << endl;
//	cout << sta.getMin() << endl;
//	return 0;
//}
#include "common.h"

class Solution {
public:
	// sqrt
	int mySqrt(int x) {
		if (x <= 1) {
			return x;
		}

		long r = x;
		while (r * r > x) {
			r = (r + x / r) / 2;
		}
		return r;
	}

	// Sort Colors
	void sortColors(vector<int>& nums) {
		if (nums.size() <= 1) {
			return;
		}

		int low = 0;
		int mid = 0;
		int high = nums.size() - 1;
		while (mid <= high) {
			int tmp;
			if (nums[mid] == 1) {
				mid++;
			} else if (nums[mid] == 0) {
				tmp = nums[low];
				nums[low] = 0;
				nums[mid] = tmp;
				low++;
				mid++;
			} else {
				tmp = nums[high];
				nums[high] = 2;
				nums[mid] = tmp;
				high--;
			}
		}
		return;
	}

	//valid soduku
	bool isValidSudoku(vector<vector<char>>& board) {
		int usedRow[9][9] = { 0 };
		int usedCol[9][9] = { 0 };
		int usedBox[9][9] = { 0 };
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					int num = board[i][j] - '1';
					int box = i / 3 * 3 + j / 3;
					if (usedRow[i][num] || usedCol[j][num] || usedBox[box][num]) {
						return false;
					}

					usedRow[i][num] = usedCol[j][num] = usedBox[box][num] = 1;
				}
			}
		}
		return true;
	}

	// subsets
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;

		sort(nums.begin(), nums.end());

		vector<int> tmp;
		getRow(0, nums, tmp, result);

		return result;
	}

	//Pascal's Triangle
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result;
		if (numRows <= 0) {
			return result;
		}

		vector<int> row;
		row.push_back(int(1));
		result.push_back(row);

		for (int i = 1; i < numRows; i++) {
			vector<int> row;
			row.push_back(int(1));

			for (int j = 1; j < i + 1; j++) {
				int a = result[i - 1][j - 1];
				int b = 0;
				if (result[i - 1].size() > j) {
					b = result[i - 1][j];
				}
				row.push_back(a + b);
			}

			result.push_back(row);
		}
		return result;
	}

	// Pascal's Triangle II
	vector<int> getRow(int rowIndex) {
		if (rowIndex < 0) {
			return vector<int>();
		}
		vector<int> A(rowIndex + 1, 0);
		A[0] = 1;
		for (int i = 1; i <= rowIndex; i++) {
			for (int j = i; j >= 1; j--) {
				A[j] += A[j - 1];
			}
		}
		return A;
	}

	// Course Schedule
	bool canFinish1(int numCourses, vector<pair<int, int>>& prerequisites) {
		//unordered_set<int> neighbour;
		vector<unordered_set<int>> graph(numCourses);
		for (auto p : prerequisites) {
			graph[p.second].insert(p.first);
		}

		vector<int> degree(numCourses, 0);
		for (auto g : graph) {
			for (int neigh : g) {
				degree[neigh]++;
			}
		}

		for (int i = 0; i < numCourses; i++) {
			int j = 0;
			for (; j < numCourses; j++) {
				if (!degree[j]) {
					break;
				}
			}
			if (j == numCourses) {
				return false;
			}

			degree[j] = -1;
			for (int x : graph[j]) {
				degree[x]--;
			}
		}

		return true;
	}

	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		//unordered_set<int> neighbour;
		vector<unordered_set<int>> graph(numCourses);
		for (auto p : prerequisites) {
			graph[p.second].insert(p.first);
		}

		vector<bool> onPath(numCourses, false), visited(numCourses, false);
		for (int i = 0; i < numCourses; i++) {
			if (!visited[i] && dfs_existed_cycle(graph, i, onPath, visited)) {
				return false;
			}
		}
		
		return true;
	}

	bool isPalindrome(string s) {
		for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
			while (!isalnum(s[i]) && i < j) {
				i++;
			}
			while (!isalnum(s[j]) && i < j) {
				j--;
			}

			if (toupper(s[i]) != toupper(s[j])) {
				return false;
			}
		}

		return true;
		/*string newS = "";
		for (char c : s) {
			if (isalnum(c)) {
				newS += tolower(c);
			}
		}
		if (newS.size() <= 1) {
			return true;
		}

		for (int i = 0; i < newS.size(); i++) {
			if (newS[i] != newS[newS.size() - 1 - i]) {
				return false;
			}
		}
		return true;*/
	}

	// judge string palindrome if you can remove at most one char
	bool validPalindrome(string s) {
		for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
			// not equal£¬discard char at index i or j
			if (s[i] != s[j]) {
				return isValidPalindrome(s, i, j - 1) || isValidPalindrome(s, i + 1, j);
			}
		}
		return true;
	}

	// Rotate an array of n elements to the right by k steps.
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		if (k <= 0 || n <= 1) {
			return;
		}
		vector<int> result(n);
		k %= n;
		for (int i = 0; i < n; i++) {
			int j = (i + k) % n;
			result[j] = nums[i];
		}
		for (int i = 0; i < n; i++) {
			nums[i] = result[i];
		}
		return;
	}

	// find the one that is missing from the array
	int missingNumber(vector<int>& nums) {
		/*int n = nums.size();
		if (n == 0) {
			return 0;
		}
		if (n == 1) {
			return !nums[0];
		}

		sort(nums.begin(), nums.end());
		int i = 0;
		for (; i <n - 1; i++) {
			if (nums[i] + 1 != nums[i + 1]) {
				return nums[i] + 1;
			}
		}
		return nums[n - 1] + 1 == n ? nums[n - 1] + 1 : 0;*/

		
		// total = (n + 1) * n / 2;
		// sum = ((n + 1) * n - result * 2) / 2;
		// result = total - sum;
		int n = nums.size();
		long total = (n + 1) * n / 2;
		long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += nums[i];
		}

		return total - sum;
	}

	// Given a singly linked list, determine if it is a palindrome.
	bool isPalindrome(ListNode* head) {
		tmp = head;
		return check(tmp);
	}

	// Given an integer, write a function to determine if it is a power of three

	bool isPowerOfThree(int n) {
		int const Max3PowerInt = 1162261467;
		if (n < 1 || n > Max3PowerInt) {
			return false;
		}

		
		return Max3PowerInt % n == 0;
	}

	//Island Perimeter
	int islandPerimeter(vector<vector<int>>& grid) {
		int count = 0;
		int n = 0;

		if ((grid.size() == 0) || (grid[0].size() == 0)) {
			return 0;
		}

		int h = grid.size();
		int w = grid[0].size();
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				if (grid[i][j] == 1) {
					n++;
					for (int k = 0; k < 4; k++) {
						int x = i + move[k][0];
						int y = j + move[k][1];
						if ((x >= 0 && x < w) && (y >= 0 && y < h) && (grid[x][y] == 1)) {
							count++;
						}
					}
				}
			}
		}

		return (n * 2 - count) * 2;
	}

	//
	int kthSmallest(TreeNode* root, int k) {
		if (root == NULL) {
			return -1;
		}

		traverse(root, k);
		return result;
		// kthSmallest(root->left, k);
	}

	// Perfect Squares
	int numSquares(int n) {
		if (n <= 0) {
			return 0;
		}
		vector<int> v(n + 1, INT_MAX);
		v[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j * j <= i; j++) {
				v[i] = min(v[i], v[i - j * j] + 1);
			}
		}
		return v.back();
	}

	/*
	Given an encoded message containing digits, determine the total number of ways to decode it.
	*/
	int numDecodings(string s) {
		int len = s.size();
		if (len == 0 || s[0] == '0') {
			return 0;
		}
		
		if (len == 1) {
			return 1;
		}

		int result = 0;
		int fn_1 = 1, fn_2 = 1;
		for (int i = 1; i < len; i++) {
			int tem = fn_1;
			if (isOneCharValid(s[i]) && isTwoCharsValid(s[i - 1], s[i])) {
				result = fn_1 + fn_2;
			} else if (!isOneCharValid(s[i]) && isTwoCharsValid(s[i - 1], s[i])) {
				result = fn_2;
			} else if (isOneCharValid(s[i]) && !isTwoCharsValid(s[i - 1], s[i])) {
				result = fn_1;
			} else {
				return 0;
			}
			fn_1 = result;
			fn_2 = tem;
			result = 0;
		}
		return fn_1;
	}

	/*
	return the inorder traversal of its nodes' values iteratively
	*/
	vector<int> inorderTraversal(TreeNode* root) {
		/*TreeNode* pre = NULL;*/
		TreeNode* cur = root;
		vector<int> nodes;
		while (cur != NULL) {
			if (cur->left == NULL) {
nodes.push_back(cur->val);
cur = cur->right;
			} else {
			TreeNode* pre = cur->left;
			while (pre->right != NULL && pre->right != cur) {
				pre = pre->right;
			}

			if (pre->right == NULL) {
				pre->right = cur;
				cur = cur->left;
			} else {
				pre->right = NULL;
				nodes.push_back(cur->val);
				cur = cur->right;
			}
			}
		}
		return nodes;
	}

	/*
	Write a function to compute the fewest number of coins that you need to make up that amount.
	*/
	int coinChange(vector<int>& coins, int amount) {
		/*if (coins.size() <= 0 || amount <= 0) {
			return -1;
		}

		sort(coins.begin(), coins.end());
		int num = 0;
		for (int i = coins.size() - 1; i >= 0; i--) {
			if (amount >= coins[i]) {
				num += amount / coins[i];
				amount %= coins[i];
			}
		}
		return amount == 0 ? num : -1;*/
		long MAX = amount + 1;
		vector<long> dp(amount + 1, MAX);
		dp[0] = 0;
		for (int i = 1; i <= amount; i++) {
			for (int j = 0; j < coins.size(); j++) {
				if (coins[j] <= i) {
					dp[i] = min(dp[i], dp[i - coins[j]] + 1);
				}
			}
		}

		return dp[amount] > amount ? -1 : dp[amount];
	}

	void wiggleSort(vector<int>& nums) {
		int n = nums.size();
		auto pMid = nums.begin() + n / 2;
		nth_element(nums.begin(), pMid, nums.end());
		int mid = *pMid;

#define A(i) nums[(1 + 2 * (i)) % (n | 1)]
		int i = 0;
		int j = n - 1;
		int k = 0;
		while (k <= j) {
			if (A(k) < mid) {
				swap(A(j--), A(k));
			} else if (A(k) > mid) {
				swap(A(k++), A(i++));
			} else {
				k++;
			}
		}

		return;
	}

	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		vector<string> head, tail, *pHead, *pTail;
		head.push_back(beginWord);
		tail.push_back(endWord);
		int step = 2;
		while (!head.empty() && !tail.empty()) {
			if (head.size() <= tail.size()) {
				pHead = &head;
				pTail = &tail;
			} else {
				pHead = &tail;
				pTail = &head;
			}
			vector<string> temp;
			for (auto it = pHead->begin(); it != pHead->end(); it++) {
				string word = *it;
				wordList.erase(find(wordList.begin(), wordList.end(), word));
				for (int i = 0; i < word.size(); i++) {
					char letter = word[i];
					for (int j = 0; j < 26; j++) {
						word[i] = 'a' + j;
						if (find(pTail->begin(), pTail->end(), word) != pTail->end()) {
							return step;
						}

						if (find(wordList.begin(), wordList.end(), word) != wordList.end()) {
							temp.push_back(word);
							wordList.erase(find(wordList.begin(), wordList.end(), word));
						}
					}
					word[i] = letter;
				}
			}
			step++;
			swap(*pHead, temp);
		}
		return 0;
	}
	/*
	* Course Schedule II
	*/
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> topoSort(numCourses);
		vector<unordered_set<int>> graph(numCourses);
		make_graph(prerequisites, graph);
		vector<bool> onpath(numCourses, false);
		vector<bool> visited(numCourses, false);
		
		for (int i = 0; i < numCourses; i++) {
			if (!visited[i] && dfs(i, topoSort, prerequisites, graph, onpath, visited)) {
				return {};
			}
		}
		reverse(topoSort.begin(), topoSort.end());
		return topoSort;
	}

	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int> outputs(len, 1);
		int temp_s = 1;
		int temp_e = 1;
		for (int i = 0; i < len; i++) {
			outputs[i] *= temp_s;
			temp_s *= nums[i];

			outputs[len - 1 - i] *= temp_e;
			temp_e *= nums[len - 1 - i];
		}
		return outputs;
	}

	/*
	*  the k most frequent elements
	*/
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		for (int a : nums) {
			m[a]++;
		}

		priority_queue<pair<int, int> > pQueue;
		for (auto p : m) {
			pQueue.push({ p.second, p.first });
		}
		vector<int> res(k);
		for (int i = 0; i < k; i++) {
			res[i] = pQueue.top().second;
			pQueue.pop();
		}

		return res;
	}

	/*
	Odd Even Linked List
	*/
	ListNode* oddEvenList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}

		ListNode *peven = head->next, *podd = head, *peven_head = peven;
		while (peven && peven->next) {
			podd->next = peven->next;
			podd = podd->next;

			peven->next = podd->next;
			peven = peven->next;
		}
		podd->next = peven_head;
		return head;
	}

	/*
	* find duplicate
	*/
	int findDuplicate(vector<int>& nums) {
		// int len = nums.size();
		// for (int i = 0; i < len; i++) {
		//     for (int j = i + 1; j < len; j++) {
		//         if (nums[i] == nums[j]) {
		//             return nums[i];
		//         }
		//     }
		// }

		int fast = nums[nums[0]];
		int slow = nums[0];
		while (fast != slow) {
			slow = nums[slow];
			fast = nums[nums[fast]];
		}
		fast = 0;
		while (fast != slow) {
			slow = nums[slow];
			fast = nums[fast];
		}
		return slow;
	}

	/*
	* find the kth smallest element in the matrix
	*/
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		int left = matrix[0][0];
		int right = matrix[n - 1][n - 1];

		while (left < right) {
			int mid = left + (right - left) / 2;
			int number = 0;
			for (int i = 0; i < n; i++) {
				int count = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
				number += count;
			}

			if (number < k) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		return left;
	}

private:
	void make_graph(vector<pair<int, int>>& prerequisites, vector<unordered_set<int>>& graph) {
		for (auto pre : prerequisites) {
			graph[pre.second].insert(pre.first);
		}
		return;
	}

	bool dfs(int node, vector<int>& topoSort, vector<pair<int, int>>& prerequisites,
		vector<unordered_set<int>>& graph, vector<bool>& onpath, vector<bool>& visited) {
		if (visited[node]) {
			return false;
		}

		onpath[node] = visited[node] = true;
		for (int neigh : graph[node]) {
			if (onpath[neigh] || dfs(neigh, topoSort, prerequisites, graph, onpath, visited)) {
				return true;
			}
		}
		topoSort.push_back(node);
		onpath[node] = false;
		return false;
	}

	bool isOneCharValid(char a) {
		return a != '0';
	}

	bool isTwoCharsValid(char a, char b) {
		return a == '1' || (a == '2' && b <= '6');
	}

	void getRow(int start, vector<int>& nums, vector<int>& tmp, vector<vector<int>>& result) {
		result.push_back(tmp);

		for (int i = start; i < nums.size(); i++) {
			tmp.push_back(nums[i]);
			getRow(i + 1, nums, tmp, result);
			tmp.pop_back();
		}
		return;
	}

	// Course Schedule
	bool dfs_existed_cycle(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited) {
		if (visited[node]) {
			return false;
		}

		onpath[node] = visited[node] = true;

		for (int neigh : graph[node]) {
			if (onpath[neigh] || dfs_existed_cycle(graph, neigh, onpath, visited)) {
				return true;
			}
		}
		return onpath[node] = false;
	}

	// validPalindrome
	bool isValidPalindrome(const string& s, int i, int j) {
		for (; i < j; i++, j--) {
			if (s[i] != s[j]) {
				return false;
			}
		}
		return true;
	}

	// Given a singly linked list, determine if it is a palindrome.
	ListNode* tmp;
	bool check(ListNode *p) {
		if (p == NULL) {
			return true;
		}

		bool isPld = check(p->next) && (tmp->val == p->val);
		tmp = tmp->next;
		return isPld;
	}

	// Island Perimeter
	int move[4][2] = { {-1, 0},{ 1, 0 },{ 0, 1 } ,{ 0, -1 } };

	int count = 0;
	int result = -1;
	void traverse(TreeNode* root, int k) {
		if (root == NULL) {
			return;
		}
		traverse(root->left, k);
		if (count == k) {
			return;
		}
		count++;
		if (count == k) {
			result = root->val;
			return;
		}

		traverse(root->right, k);
	}
};
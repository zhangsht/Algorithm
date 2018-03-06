#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <map>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 typedef pair<int, int> PAIR;
 int cmp(const PAIR &x, const PAIR &y)
 {
	 return x.second > y.second;
 }
 //拆成相同的子问题，递归统计子树和情况，然后排序取最值
class Solution {
public:
	vector<int> findFrequentTreeSum(TreeNode *root) {
		map<int, int> result;
		calculateSubtree(result, root);

		//对计算结果排序
		vector<PAIR> pair_vec;
		for (map<int, int>::iterator map_iter = result.begin(); map_iter != result.end(); ++map_iter)
		{
			pair_vec.push_back(make_pair(map_iter->first, map_iter->second));
		}
		sort(pair_vec.begin(), pair_vec.end(), cmp);

		vector<int> mostFrequent;
	
		//取最值
		for (vector<PAIR>::iterator curr = pair_vec.begin(); curr != pair_vec.end(); ++curr)
		{
			if (curr == pair_vec.begin()) {
				mostFrequent.push_back(curr->first);
			}
			else if (curr->second == (pair_vec.begin())->second) {
				mostFrequent.push_back(curr->first);
			}
			else {
				break;
			}
		}

		return mostFrequent;
	}

	int calculateSubtree(map<int, int>& result, TreeNode* root) {
		//子树为空，对结果0作用
		if (root == NULL) return 0;
		//叶子节点直接加入子树和
		if (root->right == NULL && root->left == NULL) {
			result[root->val]++;
			return root->val;
		}
		int total = root->val + calculateSubtree(result, root->left) + calculateSubtree(result, root->right);
		result[total]++;
		return total;
	}
};

//int main() {
//
//	TreeNode root(5);
//	TreeNode leftNode(2);
//	TreeNode rightNode(-5);
//	root.left = &leftNode;
//	root.right = &rightNode;
//	Solution s;
//	vector<int> ans = s.findFrequentTreeSum(&root);
//	
//	for (auto a : ans) {
//		
//		cout << a << ' ';
//	}
//	return 0;
//}
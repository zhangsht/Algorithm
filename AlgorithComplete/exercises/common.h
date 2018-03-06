#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <limits.h>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;     
	TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif


#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

const int TREE_SIZE = 9;
const int n = 5;
bool visited[n][n] = { 0 };
int stepArray[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
const int mazeArray[n][n] = { { 0, 0, 0, 0, 0 }, {1, 0, 1, 0, 1}, {0, 0, 0, 0, 0}, {0, 1, 1, 1, 0},
{1, 0, 1, 0, 0} };
//
//struct Node {
//	int self;
//	Node* left;
//	Node* right;
//};
//
//void DFS() {
//	stack<Node*> visited, unvisited;
//	Node nodes[TREE_SIZE];
//	Node* current;
//	for (int i = 0; i < TREE_SIZE; i++) {
//		nodes[i].self = i;
//		int child = i * 2 + 1;
//		if (child < TREE_SIZE) {
//			nodes[i].left = &nodes[child];
//		} else {
//			nodes[i].left = NULL;
//		}
//
//		child++;
//
//		if (child < TREE_SIZE) {
//			nodes[i].right = &nodes[child];
//		} else {
//			nodes[i].right = NULL;
//		}
//	}
//
//	unvisited.push(&nodes[0]);
//	while (!unvisited.empty()) {
//		current = unvisited.top();
//		unvisited.pop();
//		if (current->right != NULL) {
//			unvisited.push(current->right);
//		}
//		if (current->left != NULL) {
//			unvisited.push(current->left);
//		}
//		visited.push(current);
//		cout << current->self << endl;
//	}
//}

struct Node {
	int x, y;
	int step;
	Node(int _x, int _y, int _step):
		x(_x), y(_y), step(_step) {}
};

int BFS() {
	Node node(0, 0, 0);
	queue<Node> q;
	q.push(node);
	

	while (!q.empty()) {
		node = q.front();
		q.pop();

		if (node.x == n - 1 && node.y == n - 1) {
			return node.step;
		}
		visited[node.x][node.y] = 1;
		for (int i = 0; i < 4; i++) {
			int x = node.x + stepArray[i][0];
			int y = node.y + stepArray[i][1];

			if (x >= 0 && y >= 0 && x < n && y < n && !visited[x][y] && mazeArray[x][y] == 0) {
				visited[x][y] = 1;
				Node next(x, y, node.step + 1);
				q.push(next);
			}
		}
	}
	return -1;
}

//int main() {
//	//DFS();
//	cout << BFS() << endl;
//	system("pause");
//	return 0;
//}
#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdio>

using namespace std;

#define M 6
#define N 6

bool bpm(bool bpGraph[M][N], int u, bool seen[], int matchR[]) {
	for (int v = 0; v < N; v++) {
		if (bpGraph[u][v] && !seen[v]) {
			seen[v] = true;

			if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR)) {
				matchR[v] = u;
				return true;
			}
 		}
	}
	return false;
}

int maxBPM(bool bpGrap[M][N]) {
	int matchR[N];
	memset(matchR, -1, sizeof(matchR));

	int result = 0;
	for (int u = 0; u < M; u++) {
		bool seen[N];
		memset(seen, 0, sizeof(seen));

		if (bpm(bpGrap, u, seen, matchR)) {
			result++;
		}
	}

	return result;
}

//int main() {
//	bool bpgGrap[M][N] = { { 0, 1, 1, 0, 0, 0 },
//						{ 1, 0, 0, 1, 0, 0 },
//						{ 0, 0, 1, 0, 0, 0 },
//						{ 0, 0, 1, 1, 0, 0 },
//						{ 0, 0, 0, 0, 0, 0 },
//						{ 0, 0, 0, 0, 0, 1 }
//						};
//	cout << "Maximum number of applications that can get job is " << maxBPM(bpgGrap);
//	system("pause");
//	return 0;
//}
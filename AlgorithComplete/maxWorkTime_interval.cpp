//#include <iostream>
//#include <stack>
//#include <algorithm> 
//#include <cstdio>
//#include <queue>
//#include <utility> 
//
//using namespace std;
//
//const int MAX_N = 100000;
//int N, S[MAX_N], T[MAX_N];
//int dp[MAX_N];
//
//pair<int, int> intv[MAX_N];


//class Solution {
//public:
//	void solve() {
//		for (int i = 0; i < N; i++) {
//			intv[i].first = T[i];
//			intv[i].second = S[i];
//		}
//		sort(intv, intv + N);
//		dp[0] = intv[0].first - intv[0].second;
//
//		for (int i = 0; i < N; i++) {
//			int max;
//			int nonOverlap = lower_bound(intv, intv[i].second) - 1;
//			if (nonOverlap >= 0) max = dp[nonOverlap] + intv[i].first - intv[i].second;
//			else max = intv[i].first - intv[i].second;
//			dp[i] = max > dp[i - 1] ? max : dp[i - 1];
//		}
//		printf("%d\n", dp[N - 1]);
//	}
//};

//int main() {
//
//	system("pause");
//	return 0;
//}
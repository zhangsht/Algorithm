#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100000;

int N, s[MAX], t[MAX];

pair<int, int> itv[MAX];

//int main() {
//	cin >> N;
//	int i;
//	for (int i = 0; i < N; i++) {
//		cin >> itv[i].second >> itv[i].first;
//	}
//
//	sort(itv, itv + N);
//
//	int current = -1, ans = 0;
//	for (i = 0; i < N; i++) {
//		if (current < itv[i].second) {
//			ans++;
//			current = itv[i].first;
//		}
//	}
//
//	cout << ans << endl;
//
//	return 0;
//}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int dp[210000];

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        return 0;
    }
    
    int total = 0;
    int tmp = 0;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        tmp /= 1024;
        v.push_back(tmp);
        total += tmp;
    }
    
    for (int i = 0; i < n; i++) {
    	for (int j = total / 2; j >= v[i]; j--) {
    		dp[j] = max(dp[j - v[i]] + v[i], dp[j]);
		}
	}
    cout << ((total - dp[total / 2]) * 1024) << endl;
    return 0;
}

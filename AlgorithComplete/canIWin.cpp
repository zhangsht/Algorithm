#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//	int maxSubArray(vector<int>& nums) {
//		int sum = 0, ans = nums[0];
//		for (int i = 0; i < nums.size(); i++) {
//			sum += nums[i];
//			ans = max(ans, sum);
//			sum = max(0, sum);
//		}
//		return ans;
//	}
//};

class Solution {
public:
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		if (maxChoosableInteger >= desiredTotal) {
			return true;
		}
		if (desiredTotal > (1 + maxChoosableInteger) * maxChoosableInteger / 2) {
			return false;
		}
		unsigned int used = (1 << maxChoosableInteger) - 1;
		return play(desiredTotal, used, maxChoosableInteger);
	}

private:
	unordered_map<unsigned int, bool> cache;
	bool play(int target, unsigned int used, int size) {
		if (cache.find(used) != cache.end()) {
			return cache[used];
		}

		if (target - 1 < size && ((1 << target - 1) < used)) {
			cache[used] = true;
			return true;
		}

		int bit = 1;
		for (int i = 0; i < size; i++, bit <<= 1) {
			if ((used & bit) == 0) continue;
			used ^= bit;
			if (!play(target - i - 1, used, size)) {
				used |= bit;
				cache[used] = true;
				return true;
			}
			used |= bit;
		}

		cache[used] = false;
		return false;
	}
};

//int main() {
//	unsigned int bit = 1 << 1;
//	unsigned int bit2 = 1 << 2;
//	int bit3 = 1 << 3;
//	int bit4 = 1 << 4;
//	cout << (bit & bit2) << endl;
//	cout << (bit3 & bit4) << endl;
//	return 0;
//}
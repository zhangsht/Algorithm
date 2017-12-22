#include <vector>
using namesapce std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	int n = nums.size();
        if (n <= 1) {
        	return;
        }

        int i = 0;
        while (nums[i] != 0) {
        	i++;
        }

        k = 1;
        moveKStenp(nums, i + 1);

        // for (int i = k; i > 0; i--) {
        // 	nums[n - 1 - k] = 0;
        // }
        return;
    }
private:
	void moveKStenp(vector<int>& nums, int start) {
		int i = start;
		for (; i < nums.size(); i++) {
			if (nums[i]) {
				nums[i - k] = nums[i];
				nums[i] = 0;
			} else {
				k++;
				return moveKStenp(nums, i + 1);
			}

		}
	}
	int k;
};

int main() {

}
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
        	result = max(min(height[left], height[right]) * (right - left), result);
        	if (height[left] < height[right]) {
        		left++; 
			} else if (height[left] > height[right]) {
				right--;
			} else {
				break;
			}
		}
		return result;
    }
};

int main() {
	Solution solution;
	return 0;
} 

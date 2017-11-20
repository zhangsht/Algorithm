#include <iostream>
#include <cmath>
using namespace std;

class Solution {
	public:
	    string longestPalindrome(string s) {
	        int start = 0;
	        int length = 0;
	        for (int i = 0; i < s.length(); i++) {
	        	int len1 = expandSubstring(s, i, i); 
	        	int len2 = expandSubstring(s, i, i + 1);
	        	int len = max(len1, len2);
	        	if (len > length) {
					start = i - (len - 1) / 2;
					length = len;
				}
			}
			return s.substr(start, length);
	    }
    
    private:
    	int expandSubstring(const string &s, int left, int right) {
    		while (left >= 0 && right < s.length() && s[left] == s[right]) {
    			left--;
    			right++;
			}
			return right - left - 1;
		}
};

int main() {
	Solution longestPalindrome;
	cout << longestPalindrome.longestPalindrome("cbascdasfsbc") << endl;
	return 0;
} 

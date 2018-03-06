#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool detectCapitalUse(string word) {
		int type1 = 0, type2 = 1, type3 = 1;
		for (int i = 0; i < word.size(); i++) {
			/*if (isupper(word[i]) && i == 0 && word.size() > 1) {
				type1 = 1;
			}

			if (isupper(word[i]) && i != 0) {
				type1 = 0;
			}

			if (islower(word[i])) type2 = 0;
			else type3 = 0;*/

			if (isupper(word[i])) {
				type3 = 0;
				if (i == 0 && word.size() > 1) type1 = 1;
				else if (i != 0) type1 = 0;
			} else type2 = 0;
		}
		return type1 || type2 || type3;

	}
};

//int main() {
//	Solution s;
//	cout << s.detectCapitalUse("usa") << endl;
//	return 0;
//}
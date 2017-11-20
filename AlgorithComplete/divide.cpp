#include "common.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1)) {
        	return INT_MAX;
		}
		
		int sign = ((devidend > 0) ^ (divisor > 0)) ? -1 : 1;
		long long dvd = labs(divided);
		long long dvs = labs(divisor);
		int res = 0;
		while (dvd >= dvs) {
			long long tmp = dvs;
			long long multiple = 1;
			while ((dvd >= (tmp << 1))) {
				tmp <<= 1;
				multiple <<= 1;
			}
			dvd -= tmp;
			res += multiple;
		}
		
		return sign == 1 ? res : -res;
    }
};

#include <iostream>

using namespace std;

void printN(int n) {
	if (n < 1) return;

	cout << n << endl;
	if (n == 1) {
		return;
	}
	printN(n - 1);
}

int main() {
	printN(9);
	return 0;
}
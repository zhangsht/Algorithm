#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int x = 4;

void test() {
	static int x = 1;
	printf("test --- x is %d\n", x);
	x++;
}
int main() {
	for (int i = 0; i < x; i++) {
		printf("main ---- x is %d\n", x);
		test();
	}
	return 0;
} 

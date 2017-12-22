#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	unsigned long a = 100;
	printf("unsigned long = %lu\n", a);
//	int a = 10;
	cout  << a / 16.0 << endl;
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
	for (int i = 0; i < 10; i++) {
		cout << v[i] << ' ';
	}
	cout << endl;
	cout << "eth_elemt: \n";
	nth_element(v.begin(), v.begin() + 5, v.end());
		for (int i = 0; i < 10; i++) {
		cout << v[i] << ' ';
	}
}

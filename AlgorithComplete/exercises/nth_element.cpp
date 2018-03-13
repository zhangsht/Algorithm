#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	short int x = 0x1122;
	char x0 = ((char*)&x)[0];
	char x1 = ((char*)&x)[1];
	cout << "x0 == 0x11 " << (x0 == 0x11) << endl;
	cout << "x1 == 0x11 " << (x1 == 0x11) << endl;

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

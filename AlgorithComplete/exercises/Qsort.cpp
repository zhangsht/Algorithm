#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;


void Qsort(int a[], int left, int right) {
	if (left >= right) return;

	int i = left;
	int j = right;
	srand((unsigned)time(NULL));
	int k = i + rand() % (j - i + 1);
	swap(a[left], a[k]);
	int key = a[left];
	while (i < j) {
		while (i < j && a[j] >= key) j--;
		a[i] = a[j];
		while (i < j && a[i] <= key) i++;
		a[j] = a[i];
	}
	a[i] = key;
	Qsort(a, left, i - 1);
	Qsort(a, i + 1, right);
}

int main() {
	int a[] = {57, 68, 59, 52, 72, 28, 96, 33, 24};
	int len = sizeof(a) / sizeof(a[0]);
	cout << len << endl;
 
    Qsort(a, 0, len - 1);
    for(int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

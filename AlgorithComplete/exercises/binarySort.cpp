#include <bits/stdc++.h>
using namespace std;

//二分查找
int binarySearch(int arr[], int len, int key) {
    int left = 0;
    int right = len - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (key < arr[mid]) {//key在左边
            right = mid - 1;
        } else if (arr[mid] < key) {//key在右边
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

//1 查找最后一个小于key的元素
int findLastLess(int arr[], int len, int key) {
    int left = 0;
    int right = len - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (key <= arr[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return right;
}

//2 查找第一个大于等于key的元素
int findFirstGreaterEqual(int arr[], int len, int key) {
    int left = 0;
    int right = len - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (key <= arr[mid]) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

//3 查找最后一个小于等于key的元素
int findLastLessEqual(int arr[], int len, int key) {
    int left = 0;
    int right = len - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (key < arr[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return right;
}

//4 查找第一个大于key的元素
int findFirstGreater(int arr[], int len, int key) {
    int left = 0;
    int right = len - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (key < arr[mid]) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

//5 查找第一个与key相等的元素
int findFirstEqual(int arr[], int len, int key) {
    int left = 0;
    int right = len - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (key <= arr[mid]) {
            right = mid - 1;
        } else {//arr[mid] < key
            left = mid + 1;
        }
    }
    //arr[right] < key <= arr[left]
    //right是最后一个小于key的
    //left是第一个大于等于key的
    if (left < len && arr[left] == key) {
        return left;
    }
    return -1;
}

//6 查找最后一个与key相等的元素
int findLastEqual(int arr[], int len, int key) {
    int left = 0;
    int right = len - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (key < arr[mid]) {
            right = mid - 1;
        } else {//arr[mid] <= key
            left = mid + 1;
        }
    }
    //arr[right] <= key < arr[left]
    //right是最后一个小于等于key的
    //left是第一个大于key的
    if (right >= 0 && arr[right] == key) {
        return right;
    }
    return -1;
}


void test() {
    int a[] = {0, 1, 2, 2, 2, 5, 6};
    int len = 7;
    int key = 2;

    int index;

    int i;
    for (i = 0; i < len; ++i) {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < len; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("%d binarySearch\n", binarySearch(a, len, key));
    printf("%d findLastLess\n", findLastLess(a, len, key));
    printf("%d findFirstGreaterEqual\n", findFirstGreaterEqual(a, len, key));
    printf("%d findLastLessEqual\n", findLastLessEqual(a, len, key));
    printf("%d findFirstGreater\n", findFirstGreater(a, len, key));
    printf("%d findFirstEqual\n", findFirstEqual(a, len, key));
    printf("%d findLastEqual\n", findLastEqual(a, len, key));
}

int main() {
    test();
    return 0;
}
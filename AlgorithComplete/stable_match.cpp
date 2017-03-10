#include <iostream>
#include <stack>

using namespace std;

#define NUM 4
#define NUL -1

int GetPositionFromLaday(int ladayArray[][NUM], int laday, int man) {
	for (int i = 0; i < NUM; i++) {
		if (ladayArray[laday][i] == man) {
			return i;
		}
	}
	return NUL;
}

void ChooseParter(stack<int>& manStack, int manPos, int manArray[][NUM], int ladayArray[][NUM],
	int manPrefer[], int manStartPos[], int ladayNow[]) {

	int preferLaday = manArray[manPos][manStartPos[manPos]];

	if (ladayNow[preferLaday] == NUL) {
		ladayNow[preferLaday] = manPos;
		manPrefer[manPos] = preferLaday;
	} else {
		int oldPos = GetPositionFromLaday(ladayArray, preferLaday, ladayNow[preferLaday]);
		int newPos = GetPositionFromLaday(ladayArray, preferLaday, manPos);
		if (oldPos < newPos) {
			manStartPos[manPos]++;
			manStack.push(manPos);
		} else {
			manStartPos[ladayNow[preferLaday]]++;
			manStack.push(ladayNow[preferLaday]);
			ladayNow[preferLaday] = manPos;
			manPrefer[manPos] = preferLaday;
		}
	}
}

//int main() {
//	int manArray[NUM][NUM] = { { 2,3,1,0 },{ 2,1,3,0 },{ 0,2,3,1 },{ 1,3,2,0 } };
//	int ladayArray[NUM][NUM] = { { 0,3,2,1 },{ 0,1,2,3 },{ 0,2,3,1 },{ 1,0,3,2 } };
//	int manPrefer[NUM] = { 0 };
//	int ladayNow[NUM] = { NUL, NUL, NUL, NUL};
//	int manStartPos[NUM] = { 0 };
//
//	stack<int> manStack;
//	for (int pos = 0; pos < NUM; pos++) {
//		ChooseParter(manStack, pos, manArray, ladayArray, manPrefer, manStartPos, ladayNow);
//	}
//
//	while (!manStack.empty()) {
//		int pos = manStack.top();
//		manStack.pop();
//		ChooseParter(manStack, pos, manArray, ladayArray, manPrefer, manStartPos, ladayNow);
//	}
//	for (int i = 0; i < NUM; i++) {
//		cout << "Man No.: " << i << " Laday No.: " << manPrefer[i] << endl;
//	}
//	return 0;
//}
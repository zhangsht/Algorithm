#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

class Job {
public:
	int deadline, length;

	bool operator < (const Job& x) const {
		return deadline < x.deadline;
	}
} *jobs;

//int main() {
//	int N, i, last_finished, s, lateness, temp;
//	scanf("%d", &N);
//	jobs = new Job[N];
//	for (int i = 0; i < N; i++) {
//		scanf("%d %d", &jobs[i].deadline, &jobs[i].length);
//	}
//	scanf("%d", &s);
//
//	sort(jobs, jobs + N);
//
//	for (int i = 0, last_finished = s, lateness = 0; i < N; i++) {
//		temp = last_finished + jobs[i].length;
//		printf("Job %d: [%d, %d]\n", i, last_finished, temp);
//		last_finished = temp;
//
//		temp = max(last_finished - jobs[i].deadline, 0);
//		if (lateness < temp) {
//			lateness = temp;
//		}
//	}
//
//	printf("Maximum lateness of schedule : %d\n", lateness);
//	system("pause");
//	return 0;
//}
#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

// java
//public int getMaxIntervalOverlapCount(List<Interval> intervals) {
//	int maxWorkers = 0;
//	/*
//	* 1 check the parameter validity
//	*/
//
//	/*
//	* 2 sort the jobs(intervals) based on the start time
//	*/
//	Collections.sort(intervals, new StartTimeComparator());
//
//	/*
//	* 3 check the least number of needed workers
//	*/
//	PriorityQueue<Integer> pq = new PriorityQueue<Integer>(intervals.size());
//
//	// add the first job to the heap
//	pq.add(intervals.get(0).getEndMinuteUnit());
//	maxWorkers++;
//
//	for (int i = 1; i < intervals.size(); i++) {
//		// no allocated workers can do the next job
//		if (pq.peek() >= intervals.get(i).getBeginMinuteUnit()) {
//			maxWorkers++;
//		}
//		else {
//			pq.poll();
//		}
//		pq.add(intervals.get(i).getEndMinuteUnit());
//	}
//
//	return maxWorkers;
//}
//
//class StartTimeComparator implements Comparator<Object> {
//	public int compare(Object arg0, Object arg1) {
//		Interval i1 = (Interval)arg0;
//		Interval i2 = (Interval)arg1;
//
//		return i1.getBeginHour() != i2.getBeginHour() ? i1.getBeginHour()
//			- i2.getBeginHour() : i1.getBeginMinute()
//			- i2.getBeginMinute();
//	}
//}

//int main() {
//
//	system("pause");
//	return 0;
//}
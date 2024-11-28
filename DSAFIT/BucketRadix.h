#pragma once
#include "AlgorithmUtilities.h"
#include "PriorityQueue.h"


void BucketSort(int* arr, int size) {
	PriorityQueueLinked* PQL = new PriorityQueueLinked[size];
	int maxValue = getMaxValue(arr, size);
	for (int i = 0; i < size; i++)
	{
		int value = arr[i];
		int p = value * size / (maxValue + 1);
		PQL[p].enqueue(value);
	}

	int counter = size - 1;
	for (int i = size-1; i >=0; i--)
	{
		PriorityQueueLinked x = PQL[i];
		while (!x.isEmpty()) {
			int value = x.dequeue();
			arr[counter] = value;
			counter--;
		}
	}
}
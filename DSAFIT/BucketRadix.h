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

void Radix(int* arr, int size, int exp) {
	int counter[10] = { 0 };
	int* temp = new int[size];

	for (int i = 0; i < size; i++)
	{
		int c = (arr[i] / exp) % 10;
		counter[c]++;
	}

	for (int i = 1; i <= 9; i++)
		counter[i] += counter[i - 1];

	for (int i = size-1; i >= 0; i--)
	{
		int c = (arr[i] / exp) % 10;
		/*int& p = counter[c];
		p--;
		temp[p] = arr[i];*/
		temp[--counter[c]] = arr[i];
	}

	for (int i = 0; i < size; i++)
		arr[i] = temp[i];
}

void RadixSort(int* arr, int size) {
	int maxV = getMaxValue(arr, size);

	int exp = 1;

	while (maxV > 0) {
		Radix(arr, size, exp);
		exp *= 10;
		maxV = maxV / 10;
	}
}
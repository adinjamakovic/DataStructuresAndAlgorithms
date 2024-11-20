#pragma once
#include<iostream>
#include "AlgorithmUtilities.h"

void heapify(int* arr, int size, int i) {
	int largest = i;
	int left = i * 2 + 1;
	int right = i * 2 + 2;

	if (left >= size)
		return;

	if (arr[largest] < arr[left])
		largest = left;
	if (right < size && arr[largest] < arr[right])
		largest = right;

	if (largest != i) {
		swap(arr[largest], arr[i]);
		heapify(arr, size, largest);
	}
}

void heapSort(int* arr, int size) {
	int root = size / 2 - (size % 2 == 0);
	for (int i = root; i >= 0; i--)
		heapify(arr, size, i);

	for (int i = size-1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		size--;
		heapify(arr, size, 0);
	}
}
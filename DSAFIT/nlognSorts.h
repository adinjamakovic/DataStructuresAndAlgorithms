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


void Merge(int* temp, int* elements, int start1, int size1, int start2, int size2) {
	int i = start1, j = start2, k = start1;

	while (i < start1 + size1 && j < start2 + size2) {
		if (temp[i] < temp[j])
			elements[k++] = temp[i++];
		else
			elements[k++] = temp[j++];
	}
	while (i < start1 + size1)
		elements[k++] = temp[i++]; 
	while (j < start2 + size2)
		elements[k++] = temp[j++];
	for (k = start1; k < start1 + size1 + start2; k++)
		temp[k] = elements[k];
}

void MergeSort(int* temp, int* elements, int start1, int size) {
	int start2, size1, size2;

	if (size > 1) {
		start2 = start1 + size / 2;
		size1 = start2 - start1;
		size2 = size - size1;
		MergeSort(temp, elements, start1, size1);
		MergeSort(temp, elements, start2, size2);
		Merge(temp, elements, start1, size1, start2, size2);
	}
}


void QuickSort(int* arr, int low, int high) {
	if (low < high) {
		int pivotloc = low;
		int pivotkey = arr[low];
		for (int i = low+1; i < high; i++)
			if (arr[i] < pivotkey) {
				pivotloc++;
				swapArrayElements(arr, pivotloc, i);
			}
		swapArrayElements(arr, low, pivotloc);
		QuickSort(arr, low, pivotloc);
		QuickSort(arr, pivotloc + 1, high);
	}
}

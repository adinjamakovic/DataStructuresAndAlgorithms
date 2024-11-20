#pragma once
#include<iostream>

void print(int* numbers, int size){
	for (int i = 0; i < size; i++)
		std::cout << numbers[i] << " | ";
	std::cout << std::endl;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void BubbleSort(int* arr, int size) {
	bool change = true;
	while (change) {
		change = false;
		for (int i = 0; i < size-1; i++)
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				change = true;
			}
	}
}

void InsertionSort(int* arr, int size) {
	for (int i = 1; i < size; i++)
	{
		int j = i;
		while (j > 0 && arr[j] < arr[j - 1]) {
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}

void SelectionSort(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		int minI = i;
		for (int j = i+1; j < size; j++)
		{
			if (arr[minI] > arr[j]) minI = j;
		}
		if (minI != i)
			swap(arr[minI], arr[i]);
	}
}
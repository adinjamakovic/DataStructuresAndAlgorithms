#pragma once
#include<iostream>
void print(int* numbers, int size) {
	for (int i = 0; i < size; i++)
		std::cout << numbers[i] << " | ";
	std::cout << std::endl;
}

void swapArrayElements(int* arr, int i, int j) {
	if (i != j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int getMaxValue(int* arr, int n) {
	int maxValue = arr[0];
	for (int i = 0; i < n; i++)
		if (arr[i] > maxValue)
			maxValue = arr[i];
	return maxValue;
}

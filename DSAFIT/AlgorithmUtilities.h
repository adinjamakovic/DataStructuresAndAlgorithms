#pragma once
#include<iostream>
void print(int* numbers, int size) {
	for (int i = 0; i < size; i++)
		std::cout << numbers[i] << " | ";
	std::cout << std::endl;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

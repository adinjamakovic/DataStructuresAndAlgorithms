#include<iostream>
#include "Lists.h"
using namespace std;

int numbers[] = { 44, 12, 654, 1, 7, 2, 6, 43, 78 };



void testArray() {
	Array test(4);
	for (int i = 0; i < size(numbers); i++)
		test.add(numbers[i]);
	cout << "Initial List:" << endl;
	test.printList();

}


int main() {
	testArray();
	return 0;
}
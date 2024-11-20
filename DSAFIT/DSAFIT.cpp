#include<iostream>
#include "Lists.h"
using namespace std;

int numbers[] = { 44, 12, 654, 1, 7, 2, 6, 43, 78 };



void testArray() {
	//Array test(4);
	LinkedList test;
	for (int i = 0; i < size(numbers); i++)
		test.add(numbers[i]);
	cout << "Initial List:" << endl;
	test.printList();
	cout << "Adding element 23 to location 2:\n";
	test.addAt(23, 2);
	test.printList();
	cout << "Removing from end of list: " << test.remove() << endl;
	test.printList();
	cout << "Removing from location 2: " << test.removeFrom(2)<<endl;
	cout << "Removing element 654 using findEl and removeFrom "<<endl;
	test.removeFrom(test.findEl(654));
	test.printList();
	cout << "Element at location 2: " << test.findKth(2);
}


int main() {
	testArray();
	return 0;
}
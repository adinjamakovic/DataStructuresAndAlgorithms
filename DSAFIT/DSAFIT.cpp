#include<iostream>
#include "Lists.h"
#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "nSquaredSorts.h"
#include "nlognSorts.h"
#include "BucketRadix.h"
using namespace std;

int numbers[] = { 3, 44, 12, 654, 1, 7, 2, 6, 43, 78, 41, 432, 184, 832, 974, 100, 1000, 41534561, 123,321, 95195 };
int numbersCopy[] = { 3, 44, 12, 654, 1, 7, 2, 6, 43, 78, 41, 432, 184, 832, 974, 100, 1000, 41534561, 123,321, 95195 };



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

void testStack() {
	//StackSeq test(3);
	StackLinked test;
	for (int i = 0; i < size(numbers); i++)
		test.push(numbers[i]);
	test.print();
	cout << "Top element: " << test.peek() << endl;
	cout << "Removing top element" << endl;
	test.pop();
	test.print();
	for (int i = 0; i < size(numbers) - 1; i++)
		test.pop();
	if (test.isEmpty())
		cout << "Empty list" << endl;
}

void testQueue() {
	//QueueSeq test(3);
	//QueueLinked test;
	//PriorityQueueSeq test(3);
	//PriorityQueueLinked test;
	Heap test;
	for (int i = 0; i < size(numbers); i++)
		test.enqueue(numbers[i]);
	cout << "Initial Queue: \n";
	test.print();
	cout << "Removing element by element until empty:\n";
	int i = 0;
	while(!test.isEmpty()) {
		if (i == rand() % 9 + 1)
			test.enqueue(rand());
		cout << "Removing element: " << test.dequeue() << endl;
		if (test.isEmpty()) cout << "Queue is empty";
		else test.print();
		i++;
	}
}

/*
	To test code remove/add comments :)
*/

int main() {
	//=============DATA STRUCTURES==================
	//testArray();
	//testStack();
	//testQueue();
	//=============DATA STRUCTURES==================
	//=============SORTING ALGORITHMS==================
	print(numbers, size(numbers));
	//BubbleSort(numbers, size(numbers));
	//InsertionSort(numbers, size(numbers));
	//SelectionSort(numbers, size(numbers));
	//heapSort(numbers, size(numbers));
	//MergeSort(numbers, numbersCopy, 0, size(numbers));
	//QuickSort(numbers, 0, size(numbers) - 1);
	//BucketSort(numbers, size(numbers));
	RadixSort(numbers, size(numbers));
	print(numbers, size(numbers));
	//=============SORTING ALGORITHMS==================
	return 0;
}
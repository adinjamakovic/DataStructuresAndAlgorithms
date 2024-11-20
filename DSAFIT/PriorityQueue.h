#pragma once
#include<iostream>
#include<exception>
#include "Node.h"

/*

	PRIORITY QUEUE
	LINKED 
	SEQUENTIAL 
	****HEAP*****

*/

class PriorityQueue {
public:
	virtual void enqueue(int el) = 0;
	virtual int dequeue() = 0;
	virtual bool isEmpty() = 0;
	virtual int getCounter() = 0;
	virtual void print() = 0;
};

class PriorityQueueSeq : PriorityQueue {
	int max;
	int* arr;
	int counter = 0;
	void expandQueue() {
		max += 100;
		int* newArr = new int[max];
		for (int i = 0; i < counter; i++)
			newArr[i] = arr[i];
		delete[] arr;
		arr = newArr;
	}
public:
	PriorityQueueSeq(int max = 100) {
		this->max = max;
		arr = new int[max];
	}
	void enqueue(int el) {
		if (counter == max)
			expandQueue();
		arr[counter++] = el;
	}
	int dequeue() {
		if (isEmpty()) throw std::exception("Queue is empty");
		int maxI=0;
		for (int i = 1; i < counter; i++)
			if (arr[i] > arr[maxI])
				maxI = i;
		int x = arr[maxI];
		counter--;
		arr[maxI] = arr[counter];
		return x;
	}
	bool isEmpty() { return counter == 0; }
	int getCounter() { return counter; }
	void print() {
		for (int i = 0; i < counter; i++)
			std::cout << arr[i] << "-";
		std::cout << std::endl;
	}
};

class PriorityQueueLinked : PriorityQueue {
	Node* head = nullptr;
	int counter = 0;
public:
	void enqueue(int el) {
		Node* temp = head;
		Node* priorityTemp = nullptr;
		counter++;

		while (temp != nullptr) {
			if (temp->getValue() < el)
				break;

			priorityTemp = temp;
			temp = temp->getNext();
		}

		Node* newNode = new Node(el, temp);
		if (priorityTemp == nullptr) {
			head = newNode;
		}
		else{
			priorityTemp->setNext(newNode);
		}
	}
	int dequeue() {
		if (isEmpty()) throw std::exception("Queue is empty");
		Node* temp = head;
		head = head->getNext();
		int x = temp->getValue();
		delete temp;
		counter--;
		return x;
	}
	bool isEmpty() { return counter == 0; }
	int getCounter() { return counter; }
	void print() {
		Node* temp = head;
		while (temp != nullptr) {
			std::cout << temp->getValue() << " | ";
			temp = temp->getNext();
		}
		std::cout << std::endl;
	}
};

class Heap : PriorityQueue {
	int* arr;
	int counter = 0;
	int max;
	void swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}
	void expandHeap() {
		max += 100;
		int* temp = arr;
		arr = new int[max];
		for (int i = 0; i < counter; i++)
			arr[i] = temp[i];
		delete[] temp;
	}
	void bubbleUp(int index) {
		if (index == 0)
			return;
		int root = index / 2 - (index % 2 == 0);

		if (arr[index] < arr[root]) {
			swap(arr[index], arr[root]);
			bubbleUp(root);
		}
	}
	void bubbleDown(int index) {
		if (index * 2 + 1 >= counter)
			return;

		int left = index * 2 + 1;
		int right = index * 2 + 2;

		int maxI = index;
		if (arr[left] < arr[maxI]) {
			maxI = left;
		}
		if (right < counter && arr[right] < arr[maxI])
			maxI = right;

		if (maxI != index) {
			swap(arr[index], arr[maxI]);
			bubbleDown(maxI);
		}
	}
public:
	Heap(int max = 100) {
		this->max = max;
		arr = new int[max];
	}
	void enqueue(int el) {
		if (counter == max)
			expandHeap();
		arr[counter++] = el;
		bubbleUp(counter - 1);
	}
	int dequeue() {
		if (isEmpty()) throw std::exception("Heap is empty");
		int x = arr[0];
		counter--;
		swap(arr[0], arr[counter]);
		bubbleDown(0);
		return x;
	}
	bool isEmpty() {
		return counter == 0;
	}
	int getCounter() {
		return counter;
	}
	void print() {
		for (int i = 0; i < counter; i++)
			std::cout << arr[i] << "-";
		std::cout << std:: endl;
	}
};
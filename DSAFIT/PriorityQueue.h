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
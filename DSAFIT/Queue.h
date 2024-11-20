#pragma once
#include "Node.h"

class Queue {
public:
	virtual void enqueue(int el) = 0;
	virtual int dequeue() = 0;
	virtual bool isEmpty() = 0;
	virtual int getCounter() = 0;
	virtual void print() = 0;
};

class QueueSeq : Queue {
	int start = 0;
	int end = 0;
	int counter = 0;
	int max;
	int* arr = nullptr;
	void expandQueue() {
		max += 100;
		int* temp = arr;
		arr = new int[max];
		int b = start;
		for (int i = 0; i < counter; i++)
		{
			arr[i] = temp[b];
			b++;
			if (b == max)
				b = 0;
		}
		delete[] temp;
		start = 0;
		end = counter;
		counter = max - 100;
	}
public:
	QueueSeq(int max = 100) {
		this->max = max;
		arr = new int[max];
	}
	QueueSeq(QueueSeq& obj) {
		max = obj.max;
		arr = new int[max];
		start = obj.start;
		end = obj.end;
		for (int i = 0; i < obj.counter; i++)
			arr[i] = obj.arr[i];
	}
	void enqueue(int el) {
		if (counter == max)
			expandQueue();
		arr[end] = el;
		counter++;
		end++;
		if (end == max)
			end = 0;
	}
	int dequeue() {
		if (isEmpty())
			throw std::exception("Queue is empty");
		int x = arr[start];
		counter--;
		start++;
		if (start == end)
			start = 0;
		return x;
	}
	bool isEmpty() {return counter == 0;}
	int getCounter() {return counter;}
	void print() {
		int a = start;
		int b = end;
		while (a != b) {
			std::cout << arr[a] << " | ";
			a++;
			if (a == max)
				a = 0;
		}
		std::cout << std::endl;
	}
};
#pragma once
#include<exception>
#include "Node.h"
#include<iostream>
/*
	STACKS
	SEQUENTIAL
	LINKED
*/

class Stack {
public:
	virtual void push(int el) = 0;
	virtual int pop() = 0;
	virtual int peek() = 0;
	virtual bool isEmpty() = 0;
	virtual void print() = 0;
};

class StackSeq : Stack {
	int* arr;
	int counter = 0;
	int max;
	void expandList() {
		max += 100;
		int* temp = arr;
		arr = new int[max];
		for (int i = 0; i < counter; i++)
			arr[i] = temp[i];
		delete[] temp;
	}
public:
	StackSeq(int max = 100) {
		this->max = max;
		arr = new int[max];
	}
	StackSeq(StackSeq& obj) {
		max = obj.max;
		arr = new int[max];
		for (int i = 0; i < obj.counter; i++)
			push(obj.arr[i]);
	}
	void push(int el) {
		if (counter == max)
			expandList();
		arr[counter++] = el;
	}
	int pop() {
		if (isEmpty())
			throw std::exception("Stack is empty");
		return arr[--counter];
	}
	int peek() {
		if (isEmpty())
			throw std::exception("Stack is empty");
		return arr[counter - 1];
	}
	bool isEmpty() {
		return counter == 0;
	}
	void print() {
		for (int i = counter-1; i >= 0; i--)
			std::cout << "|" << arr[i] << "|" << std::endl;
		std::cout << "---" << std::endl;
	}
};

class StackLinked : Stack {
	Node* top = nullptr;
	int counter = 0;
public:
	void push(int el) {
		Node* newNode = new Node(el, top);
		top = newNode;
		counter++;
	}
	int pop() {
		Node* deleted = top;
		top = top->getNext();
		int x = deleted->getValue();
		delete deleted;
		counter--;
		return x;
	}
	int peek() {
		if (isEmpty())
			throw std::exception("Empty stack");
		return top->getValue();
	}
	bool isEmpty() {return counter == 0;}
	void print() {
		Node* temp = top;
		while (temp != nullptr) {
			std::cout << "|" << temp->getValue() << "|" << std::endl;
			temp = temp->getNext();
		}
		std::cout << "---" << std::endl;
	}
};
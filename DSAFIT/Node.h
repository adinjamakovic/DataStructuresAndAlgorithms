#pragma once

class Node
{
	int value;
	Node* next;
public:
	Node(int value, Node* next) {
		this->value = value;
		this->next = next;
	}
	int getValue() { return value; }
	Node* getNext() { return next; }
	void setValue(int val) {
		value = val;
	}
	void setNext(Node* nextN) {
		next = nextN;
	}
};

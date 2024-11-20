#pragma once

/*
	LISTS
	SEQUENTIAL(Array)
	LINKED
*/

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

class List {
public:
	virtual void add(int el) = 0;
	virtual int remove() = 0;
	virtual void addAt(int el, int index) = 0;
	virtual int removeFrom(int index) = 0;
	virtual int findEl(int el) = 0;
	virtual int findKth(int index) = 0;
	virtual void printList() = 0;
};

class Array : List {
	int* arr = nullptr;
	int counter = 0;
	int max;
	void expandList() {
		max += 100;
		int* temp = arr;
		arr = new int[max];
		for (int i = 0; i < counter; i++)
			arr[i] = temp[i];
	}
public:
	Array(int max = 100) {
		this->max = max;
		arr = new int[max];
	}
	Array(Array& obj) {
		max = obj.max;
		counter = 0;
		arr = new int[max];
		for (int i = 0; i < obj.counter; i++)
			add(obj.arr[i]);
	}
	void add(int el) {
		if (counter == max)
			expandList();
		arr[counter++] = el;
	}
	int remove() {
		if (counter == 0)
			throw std::exception("List is empty, removing an element is impossible");
		return arr[--counter];
	}
	void addAt(int el, int index) {
		if (counter == max)
			expandList();
		for (int i = counter; i > index; i--)
			arr[i] = arr[i - 1];
		arr[index] = el;
		counter++;
	}
	int removeFrom(int index) {
		if (counter == 0)
			throw std::exception("List is empty, removing an element is impossible");
		int x = arr[index];
		for (int i = index; i < counter - 1; i++)
			arr[i] = arr[i + 1];
		counter--;
		return x;
	}
	int findEl(int el) {
		if (counter == 0)
			throw std::exception("List is empty, no elements are present");
		for (int i = 0; i < counter; i++)
			if (el == arr[i])
				return i;
		//Returns a negative number if element is not found
		return -1;
	}
	int findKth(int index) {
		if (index >= counter || index < 0)
			throw std::exception("Not valid index");
		if (counter == 0)
			throw std::exception("List is empty");
		return arr[index];
	}
	void printList() {
		for (int i = 0; i < counter; i++)
			std::cout << arr[i] << " | ";
		std::cout << std::endl;
	}
};

class LinkedList : Array {
	int counter = 0;
	Node* head = nullptr;
public:
	void add(int el) {
		Node* temp = new Node(el, head);
		head = temp;
		counter++;
	}
	int remove() {
		if (counter == 0)
			throw std::exception("Not possible, list empty");
		/*Node* temp = head;
		int x = temp->getValue();
		head = head->getNext();
		delete temp;*/
		Node* temp = head;
		while (temp->getNext()->getNext() != nullptr)
			temp = temp->getNext();
		Node* deleted = temp->getNext();
		int x = deleted->getValue();
		temp->setNext(nullptr);
		counter--;
		return x;
	}
	void addAt(int el, int index) {
		if (counter == 0) {
			add(el);
			return;
		}
		Node* temp = head;
		for (int i = 0; i < index-1; i++)
			temp = temp->getNext();
		Node* newNode = new Node(el, temp->getNext());
		temp->setNext(newNode);
		counter++;
	}
	int removeFrom(int index) {
		if(counter==0)
			throw std::exception("Not possible, list empty");
		Node* temp = head;
		for (int i = 0; i < index-1; i++)
			temp = temp->getNext();
		Node* deleted = temp->getNext();
		temp->setNext(deleted->getNext());
		int x = deleted->getValue();
		delete deleted;
		counter--;
		return x;
	}
	int findEl(int el) {
		if (counter == 0)
			throw std::exception("List is empty, item doesn't exist");
		Node* temp = head;
		int i = 0;
		while (temp != nullptr) {
			if (temp->getValue() == el)
				return i;
			i++;
			temp = temp->getNext();
		}
	}
	int findKth(int index) {
		if (index >= counter || index < 0)
			throw std::exception("Not valid index");
		Node* temp = head;
		for (int i = 0; i < index; i++)
			temp = temp->getNext();
		return temp->getValue();
	}
	void printList() {
		Node* temp = head;
		while (temp != nullptr) {
			std::cout << temp->getValue() << " | ";
			temp = temp->getNext();
		}
		std::cout << std::endl;
	}
};

#pragma once

/*
	LISTS
	SEQUENTIAL(Array)
	LINKED
*/

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



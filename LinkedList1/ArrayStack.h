#pragma once
#include <iostream>
using namespace std;

class ArrayStack {

	int top = -1;
	int maxElements = 200;
	int stack[200];

public:

	void push(int data) {

		if (top == maxElements - 1)
		{
			cout << "Stack is full" << endl;
			return;
		}
		//add element to the array
		stack[++top] = data;
	};
	void pop() {
		if (top == -1)
		{
			cout << "Stack is empty" << endl;
			return;
		}
		//remove element
		stack[top--] = 0;
	
	};
	void peek() {
	
		if (top == -1)
		{
			cout << "Stack is empty" << endl;
			return;
		}
		cout << stack[top] << endl;;
	};
	bool isFull() {
		if (top == maxElements - 1)
		{
			return true;
		}
		else
			return false;
	}; 
	bool isEmpty() {
		if (top == - 1)
		{
			return true;
		}
		else
			return false;
	};


};


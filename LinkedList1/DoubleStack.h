#pragma once
#include<iostream>
using namespace std;

class DoubleStack {

	int doubleStack[200];
	int MAXELEMENTS = 199;
	int topUpper = -1;
	int topLower = -1;

public:

	void push(int data) {
		
		if (data <= 1000)
		{
			//push data in lower stack 
			if (isFull())
			{
				cout << "Stack Overflow" << endl;
				return;
			}
			//move all elements of the upper stack one number higher to keep stacks seperated.
			topUpper++;
			for (size_t i = topUpper; i > topLower; i--)
			{
				doubleStack[i] = doubleStack[i-1];
			}
			//now push the fucking data!
			doubleStack[++topLower] = data;
		}

		//now if we push data for the higher stack
		if (data >= 1000)
		{ 
			if (isFull())
			{
				cout << "Stack Overflow" << endl;
				return;
			}
			doubleStack[++topUpper] = data;
		}

	};
	void display() {
		cout << "Lower Stack:" << endl;
		display(0,topLower);
		cout << "\nUpper Stack:" << endl;
		display(topLower+1,topUpper);
	};

	void display(int start, int end) {
		for (size_t i = start; i <= end; i++)
		{
			cout << doubleStack[i] << " ";
		}
	}
	bool isFull() {
		return (topUpper == MAXELEMENTS);
	};
	bool isEmpty() {
		if (topLower == -1)
		{
			return true;
		}
		else
			return false;
	};


};
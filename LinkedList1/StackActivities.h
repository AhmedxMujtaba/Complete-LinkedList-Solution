#pragma once
#include <string>
#include <iostream>
using namespace std;

class Stack {
public:
	struct Node
	{
		string data;
		Node* nextNode;
	}*top;

	void push(string data) {
		Node* newNode = new Node;
		newNode->data = data;
		newNode->nextNode = top; // Set newNode's nextNode to current top
		top = newNode; // Update top to newNode
	};

	void pop() {
		if (top == nullptr)
		{
			printf("Stack is Empty\n");
			return;
		}
		Node* temp = top;
		top = top->nextNode;
		delete temp;
	};

	string top() {
		if (top == nullptr)
		{
			return NULL;
		}
		Node* currentNode;
		currentNode = top;
		return currentNode->data;

	}

	void print() {
		if (top == nullptr) {
			printf("Stack is Empty []");
			return;
		}
		Node* currentNode = top;
		while (currentNode != nullptr) {
			cout << currentNode->data << " "; // Debugging output
			currentNode = currentNode->nextNode;
		}
		printf("\n");
	};

	bool paranthesisChecker() {
		string equation = equationInput();
	

	
	}

	string equationInput() {
		printf("Enter the Equation: ");
		string equation;
		cin >> equation;
		return equation;
	};
	bool isClosed(string equation) {
		//declare the chars to compare
		string openingBrackets = "(";
		string closingBrackets = ")";

		if (equation.find(openingBrackets)) {
			push(openingBrackets);
		}
		


		
	
	};

};

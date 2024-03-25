#pragma once
#include <iostream>
using namespace std;


class LinkedListStack {

	struct Node
	{
		int data;
		Node* nextNode;
	}*top;

public:
	LinkedListStack() {
		top = nullptr;
	};

	void push(int data) {
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
	
	void print() {
		if (top == nullptr) {
			printf("Stack is Empty []");
			return;
		}
		Node* currentNode = top;
		while (currentNode!= nullptr) {
			cout << currentNode->data << " "; // Debugging output
			currentNode = currentNode->nextNode;
		}
		printf("\n");
	};

	void find(int data) {
		Node* currentNode = top;
		int count = 0;
		while (currentNode != nullptr)
		{
			if (currentNode->data == data) {
				cout << count;
				return;
			}
			count++;
			currentNode = currentNode->nextNode;
		}
		printf("Data does not exist\n");
	};

	void menu() {
	
		LinkedListStack stack;
		int choice, data;

		while (true) {
			cout << "\nStack Menu\n";
			cout << "1. Push\n";
			cout << "2. Pop\n";
			cout << "3. Print Stack\n";
			cout << "4. Search Data\n";
			cout << "5. Exit\n";
			cout << "Enter your choice: ";
			cin >> choice;

			switch (choice) {
			case 1:
				cout << "Enter data to push onto the stack: ";
				cin >> data;
				stack.push(data);
				break;
			case 2:
				stack.pop();
				break;
			case 3:
				stack.print();
				break;
			case 4:
				cout << "Enter data to find: ";
				cin >> data;
				stack.find(data);
				break;
			case 5:
				cout << "Exiting program." << endl;
				exit(0);
			default:
				cout << "Invalid choice. Please try again.\n" << endl;
			}
		}
	};

};
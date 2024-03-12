#pragma once
#include<iostream>
using namespace std;

class CircularList {
	//Same as Single Linked List but we have the last element connected to the first
private:
	struct node
	{
		int data;
		node* nextNode;
	}*firstNode;

public:
	// Constructor
	CircularList()
	{
		firstNode = nullptr;
	}

	void appendNodeAtEnd(int data);
	void display();

	void deleteNode(int data);
	void insertAt(int data, int position);

};
void CircularList::appendNodeAtEnd(int data)
{

	node* newNode, * currentNode;
	newNode = new node;

	newNode->data = data;
	//Now we check if the list is empty then, we make a new first node
	if (firstNode == nullptr)
	{
		firstNode = newNode;
		firstNode->nextNode = firstNode;
		return;
	}

	currentNode = firstNode;

	//Now we need check if there are more items so we iterate the list to see the last one which will have the 
	//location of firstNode stored as next node!
	while (currentNode->nextNode != firstNode)
	{
		currentNode = currentNode->nextNode;
	}
	currentNode->nextNode = newNode;
	newNode->nextNode = firstNode;
};
void CircularList::display()
{

	node* currentNode;
	currentNode = firstNode;
	if (firstNode == nullptr)
	{
		cout << "List Empty" << endl;
		return;
	}

	cout << "[ ";

	do {
		cout << currentNode->data << " ";
		currentNode = currentNode->nextNode;
	} while (currentNode != firstNode);

	cout << "]" << endl;
};
void CircularList::deleteNode(int data) {
	if (firstNode == nullptr) {
		cout << "List is empty. Cannot delete." << endl;
		return;
	}

	node* currentNode = firstNode;
	node* previousNode = nullptr;

	do {
		if (currentNode->data == data) {
			// If the node to be deleted is the first node
			if (previousNode == nullptr) {
				// If there's only one node in the list
				if (currentNode->nextNode == firstNode) {
					delete currentNode;
					firstNode = nullptr;
					return;
				}
				else { // If there are more than one nodes
					node* lastNode = firstNode;
					while (lastNode->nextNode != firstNode) {
						lastNode = lastNode->nextNode;
					}
					lastNode->nextNode = currentNode->nextNode;
					firstNode = currentNode->nextNode;
					delete currentNode;
					return;
				}
			}
			else { // If the node to be deleted is not the first node
				previousNode->nextNode = currentNode->nextNode;
				delete currentNode;
				return;
			}
		}
		previousNode = currentNode;
		currentNode = currentNode->nextNode;
	} while (currentNode != firstNode);

	cout << "Node with data " << data << " not found in the list." << endl;
}
void CircularList::insertAt(int data, int position) {
	if (firstNode == nullptr) {
		cout << "List is empty. Cannot insert." << endl;
		return;
	}

	node* newNode = new node;  // Allocate memory for the new node
	newNode->data = data;  // Assign data to the new node
	newNode->nextNode = nullptr;

	node* currentNode = firstNode;
	node* previousNode = nullptr;
	int count = 1;

	// Traverse the list to find the insertion position
	while (currentNode != nullptr && count < position) {
		previousNode = currentNode;
		currentNode = currentNode->nextNode;
		count++;
	}

	// Insert at the beginning of the list
	if (position == 1) {
		newNode->nextNode = firstNode;
		firstNode = newNode;
		// Update the last node's next pointer to point to the new first node
		node* lastNode = firstNode;
		while (lastNode->nextNode != firstNode) {
			lastNode = lastNode->nextNode;
		}
		lastNode->nextNode = firstNode;
	}
	// Insert at the end of the list or after the last node
	else if (currentNode == nullptr) {
		previousNode->nextNode = newNode;
		newNode->nextNode = firstNode;  // Connect the new node to the first node to maintain circularity
	}
	// Insert in the middle of the list
	else {
		previousNode->nextNode = newNode;
		newNode->nextNode = currentNode;
	}
};

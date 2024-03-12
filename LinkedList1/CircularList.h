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

	node* currentNode = firstNode;
	node* previousNode = nullptr;
	while (currentNode != nullptr)
	{

		previousNode = currentNode;
		currentNode = currentNode->nextNode;

	}
}
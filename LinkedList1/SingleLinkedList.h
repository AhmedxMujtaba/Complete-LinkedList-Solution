#pragma once
#include<iostream>
using namespace std;



//Make a class to generate a single LinkedList
class SingleLinkedList {

private:
	struct node {
		int data;
		node* nextNode;
	} *firstNode;

public:
	// Constructor
	SingleLinkedList() {
		firstNode = nullptr;
	}


	//Functions for the Single Linked List

	void insertEnd(int x);
	void displayList();
	void deleteNode(int data);
	void deleteLast();
	int findNode(int data);
	void printReverseOrder();
	void removeDuplicates();
	void detectLoop();
	void swapNodes(int nodeOne, int nodeTwo);
	void evenOddSpliter();
	int totalNodesFinder();
	void reverseToMid();
	void evenOddPositionSwapper();
	void pairWiseSwaper();



};


void SingleLinkedList::insertEnd(int x) {

	//check if list is empty and a first node is being made
	if (firstNode == nullptr) {
		firstNode = new node;
		firstNode->data = x;
		firstNode->nextNode = nullptr;
		return;
	}

	//we move in the list and reach at the last node and add a new node
	//Alriht so lets begin!!

	//Here mover is the node type pointer which will move along the list to the end;
	//new node is a node type pointer which will have the location of the new node (?doubt?)
	node* currentNode, * newNode;

	//Assigning the mover node struct, the value of the first node
	currentNode = firstNode;

	//After the while loop ends we have reached the last node (node struct we made containing a data and a node type pointer)
	while (currentNode->nextNode != nullptr)
	{
		currentNode = currentNode->nextNode;
	}

	//We make a new node 'newNode' to add at the end of the list
	newNode = new node;

	//Now assigning its values.
	newNode->data = x;
	newNode->nextNode = nullptr;

	//Now assigning the 'currentNode' current node's  (which is the last node) 'nextNode' value to the location of the newNode we made
	currentNode->nextNode = newNode;

	/*
	Thats pretty much it,
	Just remember the main points.
	1- Check if the list is empty
	2- Iterate currentNode till last node
	3- Create new node and its pointer to add it
	4- Create a node type pointer to iterate it till last node
	5- Assign the pointer's nextNode's location to the newNode we made
	Thats it!!

		   +--------------+
		  /|             /|
		 / |            / |
		*--+-----------*  |
		|  |           |  |
		|  |    niga   |  |
		|  |    box    |  |
		|  +-----------+--+
		| /            | /
		|/             |/
		*--------------*
	*/

}


//Now a function to display the list we have created!
void SingleLinkedList::displayList() {
	node* iterativeNode;
	iterativeNode = firstNode;
	if (firstNode == nullptr)
	{
		cout << "List Empty" << endl;
		return;
	}

	//Just iterating and printing the values not much to see here
	cout << "[ ";
	while (iterativeNode != nullptr)
	{
		cout << iterativeNode->data << " ";
		iterativeNode = iterativeNode->nextNode;
	}
	cout << "]" << endl;
};


//Now a function to delete a node if you accidently add 14 instead of 15!!
void SingleLinkedList::deleteNode(int data) {

	//check fitst that list is empty?
	if (firstNode == nullptr)
	{
		cout << "List Empty" << endl;
		return;
	}

	//Now iterrate and compare data, when matched delete the current node, then we need to connect the previous node with the next one.
	//We also have to keep in mind that the node being deleted isnt the last one, if it is, then we need to use a different approcach.
	//we also have the check the node being deleted isnt the first one right? If it is then we make the next node the firstNode.
	node* currentNode, * tempNode;
	currentNode = firstNode;
	tempNode = nullptr;

	//first condition to see if the node to be deleted is the first
	if (currentNode->data == data)
	{
		//Assigning it the value of the next node
		firstNode = firstNode->nextNode;
		delete currentNode;
		return;
	}

	//Now if it is inside the list then we iterate until we find it and then delete it my niga
	while (currentNode != nullptr)
	{
		if (currentNode->data == data)
		{
			tempNode->nextNode = currentNode->nextNode;
			delete currentNode;
			return;
		}

		// Check if the node to be deleted is the last node
		//can also add a new function to delete last!?
		if (currentNode->nextNode != nullptr && currentNode->nextNode->nextNode == nullptr && currentNode->nextNode->data == data)
		{
			currentNode->nextNode = nullptr;
			return;
		}


		tempNode = currentNode;
		currentNode = currentNode->nextNode;
	}

	// If the node with the given data is not found
	cout << "Node with data " << data << " not found in the list" << endl;


	/*

		   firstNode           tempNode		      CurrentNode

		+----+--------+		+----+--------+		+----+--------+		+----+--------+
		|data|nextNode|===> |data|nextNode|===> |data|nextNode|===> |data|nullptr |
		+----+--------+		+----+--------+		+----+--------+		+----+--------+




	*/
};


void SingleLinkedList::deleteLast() {

	node* currentNode = firstNode;

	if (firstNode == nullptr)
	{
		cout << "List Empty" << endl;
		return;
	}
	while (currentNode->nextNode->nextNode != nullptr)
	{
		currentNode = currentNode->nextNode;
	}
	currentNode->nextNode = nullptr;
	return;

}


//Now lets make a function to find out on which node does the data lies print the number or we can also return a int!
int SingleLinkedList::findNode(int data) {
	if (firstNode == nullptr) {
		return -1;
	}

	node* currentNode = firstNode;
	int count = 1;
	while (currentNode != nullptr) {
		if (currentNode->data == data) {
			return count;
		}
		count++;
		currentNode = currentNode->nextNode;
	}

	// If the loop finishes without finding the node, return -1
	return -1; 
}


 void SingleLinkedList::printReverseOrder()
{
	//check if list is empty
	 if (firstNode == nullptr)
	 {
		 cout << "List Empty" << endl;
		 return;
	 }
	 //Now how to print reverse order?
	 //what the fuck
	 //Alright dont panic we need reverse the list first
	 //To do that we take a node and link it to the previous node
	 //we take three node, one will tail the current so that we link it to the prev, one stay foward so that we dont lose the list.

	 node* currentNode, * forwardNode, * previousNode;
	 currentNode = firstNode;
	 forwardNode = nullptr;
	 previousNode = nullptr;

	 while (currentNode != nullptr)
	 {
		 //first we set the forward node
		 forwardNode = currentNode->nextNode;
		 //Now we make the nextNode to point at the previous one
		 currentNode->nextNode = previousNode;
		 //setting the previous node to the curent and then moving the current forward
		 previousNode = currentNode;
		 currentNode = forwardNode;
	 }

	 displayList();
	 //node* iterativeNode;
	 //iterativeNode = firstNode;
	 //if (firstNode == nullptr)
	 //{
		// cout << "List Empty" << endl;
		// return;
	 //}

	 ////Just iterating and printing the values not much to see here
	 //cout << "[ ";
	 //while (iterativeNode != nullptr)
	 //{
		// cout << iterativeNode->data << " ";
		// iterativeNode = iterativeNode->nextNode;
	 //}
	 //cout << "]" << endl;

};

 //Remove duplicates by using nested while
 void SingleLinkedList::removeDuplicates() {
	 if (firstNode == nullptr) {
		 cout << "List Empty" << endl;
		 return;
	 }

	 node* currentNode = firstNode;

	 while (currentNode != nullptr) {
		 //Make a temp node to iterate and match elements
		 node* tempNode = currentNode;
		 while (tempNode->nextNode != nullptr) {
			 if (currentNode->data == tempNode->nextNode->data) {
				 node* duplicateNode = tempNode->nextNode;
				 // Remove the duplicate node
				 tempNode->nextNode = tempNode->nextNode->nextNode; 
				 delete duplicateNode;
			 }
			 else {
				 tempNode = tempNode->nextNode;
			 }
		 }
		 currentNode = currentNode->nextNode;
	 }
 };

 //we need to pointers that move along the list. One fast and one slow, if they meet than there is a loop else no loop
 void SingleLinkedList::detectLoop() {

	 
	 if (firstNode == nullptr) {
		 cout << "List Empty" << endl;
		 return;
	 }

	 node* currentNode, * fasterPointer;
	 currentNode = firstNode;
	 fasterPointer = firstNode->nextNode;

	 while (fasterPointer != nullptr || currentNode->nextNode != nullptr)
	 {

		 // Move slow pointer one step forward
		 currentNode = currentNode->nextNode;
		 // Move fast pointer two steps forward
		 fasterPointer = fasterPointer->nextNode->nextNode;

		 if (fasterPointer == currentNode) {
			 cout << "The Linked List has a loop " << endl;
			 return;
		 }
		 
	 }
	 cout << "No Loop Detected" << endl;

 };

 //swap nodes by position and changing their links instead of interchanging data
 void SingleLinkedList::swapNodes(int nodeOne, int nodeTwo) {
	 // If the list is empty
	 if (firstNode == nullptr) {
		 cout << "List Empty" << endl;
		 return;
	 }

	 // If the nodes to swap are the same, no need to swap
	 if (nodeOne == nodeTwo) {
		 cout << "Nodes are the same, no need to swap." << endl;
		 return;
	 }

	 // Ensure nodeOne is smaller than nodeTwo
	 if (nodeOne > nodeTwo) {
		 swap(nodeOne, nodeTwo);
	 }

	 // Find the nodes to swap and their previous nodes
	 node* prevNodeOne = nullptr;
	 node* prevNodeTwo = nullptr;
	 node* currentNode = firstNode;
	 node* nodeToSwapOne = nullptr;
	 node* nodeToSwapTwo = nullptr;

	 int position = 1;
	 while (currentNode != nullptr && position <= nodeTwo) {
		 if (position == nodeOne - 1) {
			 prevNodeOne = currentNode;
		 }
		 else if (position == nodeOne) {
			 nodeToSwapOne = currentNode;
		 }

		 if (position == nodeTwo - 1) {
			 prevNodeTwo = currentNode;
		 }
		 else if (position == nodeTwo) {
			 nodeToSwapTwo = currentNode;
		 }

		 currentNode = currentNode->nextNode;
		 position++;
	 }

	 // If any node doesn't exist
	 if (nodeToSwapOne == nullptr || nodeToSwapTwo == nullptr) {
		 cout << "One or both nodes do not exist." << endl;
		 return;
	 }

	 // Swapping nodes
	 if (prevNodeOne != nullptr) {
		 prevNodeOne->nextNode = nodeToSwapTwo;
	 }
	 else {
		 // If the first node itself is being swapped
		 firstNode = nodeToSwapTwo;
	 }

	 if (prevNodeTwo != nullptr) {
		 prevNodeTwo->nextNode = nodeToSwapOne;
	 }
	 else {
		 // If the second node itself is the first node
		 firstNode = nodeToSwapOne;
	 }

	 // Update next pointers
	 node* temp = nodeToSwapOne->nextNode;
	 nodeToSwapOne->nextNode = nodeToSwapTwo->nextNode;
	 nodeToSwapTwo->nextNode = temp;
 };

 void SingleLinkedList::evenOddSpliter() {
	 if (firstNode == nullptr) {
		 cout << "List Empty" << endl;
		 return;
	 }

	 node* currentNode = firstNode;
	 SingleLinkedList evenList;
	 SingleLinkedList oddList;

	 while (currentNode != nullptr) {
		 // Store the next node in the original list before modifying current node's next
		 node* nextNode = currentNode->nextNode;

		 // Detach the current node from the original list
		 currentNode->nextNode = nullptr;

		 // Determine if the current node's data is even or odd
		 if (currentNode->data % 2 == 0) {
			 // Append the current node to the even list
			 if (evenList.firstNode == nullptr) {
				 evenList.firstNode = currentNode;
			 }
			 else {
				 node* evenListCurrentNode = evenList.firstNode;
				 while (evenListCurrentNode->nextNode != nullptr) {
					 evenListCurrentNode = evenListCurrentNode->nextNode;
				 }
				 evenListCurrentNode->nextNode = currentNode;
			 }
		 }
		 else {
			 // Append the current node to the odd list
			 if (oddList.firstNode == nullptr) {
				 oddList.firstNode = currentNode;
			 }
			 else {
				 node* oddListCurrentNode = oddList.firstNode;
				 while (oddListCurrentNode->nextNode != nullptr) {
					 oddListCurrentNode = oddListCurrentNode->nextNode;
				 }
				 oddListCurrentNode->nextNode = currentNode;
			 }
		 }

		 // Move to the next node in the original list
		 currentNode = nextNode;
	 }

	 // Display the even and odd lists
	 cout << "Even List: ";
	 evenList.displayList();
	 cout << "Odd List: ";
	 oddList.displayList();
 };

 int SingleLinkedList::totalNodesFinder() {
	 node* currentNode;
	 currentNode = firstNode;
	 int count = 0;
	 while (currentNode != nullptr)
	 {
		 currentNode = currentNode->nextNode;
		 count++;
	 }
	 return count;
 };

 //needs fixing
 void SingleLinkedList::reverseToMid() {
	 if (firstNode == nullptr || firstNode->nextNode == nullptr) {
		 return; // No need to reverse if there are 0 or 1 nodes
	 }

	 // Find the midpoint using slow and fast pointers
	 node* slow = firstNode;
	 node* fast = firstNode;
	 node* prev = nullptr;

	 while (fast != nullptr && fast->nextNode != nullptr) {
		 prev = slow;
		 slow = slow->nextNode;
		 fast = fast->nextNode->nextNode;
	 }

	 // Reverse the first half of the list
	 node* currentNode = firstNode;
	 node* forwardNode = nullptr;
	 node* prevNode = nullptr;
	 node* midNode = slow; // Midpoint of the list

	 while (currentNode != midNode) {
		 forwardNode = currentNode->nextNode;
		 currentNode->nextNode = prevNode;
		 prevNode = currentNode;
		 currentNode = forwardNode;
	 }

	 // Update the head to the last node of the reversed first half
	 firstNode = prevNode;

	 // Reverse the second half of the list
	 prevNode = nullptr;
	 while (slow != nullptr) {
		 forwardNode = slow->nextNode;
		 slow->nextNode = prevNode;
		 prevNode = slow;
		 slow = forwardNode;
	 }

	 // Connect the last node of the first half to the first node of the second half
	 if (prev != nullptr) {
		 prev->nextNode = prevNode;
	 }
	 else {
		 firstNode->nextNode = prevNode;
	 }
 }

 void SingleLinkedList::evenOddPositionSwapper() {
	 if (firstNode == nullptr || firstNode->nextNode == nullptr) {
		 cout << "List does not have enough nodes for swapping." << endl;
		 return;
	 }

	 bool swapped = true;

	 while (swapped) {
		 swapped = false;
		 node* currentNode = firstNode;
		 node* prevNode = nullptr;
		 node* firstEvenNode = nullptr;
		 node* lastOddNode = nullptr;

		 // Find the first even node
		 while (currentNode != nullptr) {
			 if (currentNode->data % 2 == 0) {
				 firstEvenNode = currentNode;
				 break;
			 }
			 prevNode = currentNode;
			 currentNode = currentNode->nextNode;
		 }

		 // Find the last odd node
		 while (currentNode != nullptr) {
			 if (currentNode->data % 2 != 0) {
				 lastOddNode = currentNode;
			 }
			 prevNode = currentNode;
			 currentNode = currentNode->nextNode;
		 }

		 // Swap the data values of first even and last odd nodes
		 if (firstEvenNode != nullptr && lastOddNode != nullptr) {
			 int temp = firstEvenNode->data;
			 firstEvenNode->data = lastOddNode->data;
			 lastOddNode->data = temp;
			 swapped = true;  // Mark as swapped
		 }
	 }
 };

 void SingleLinkedList::pairWiseSwaper() {
	
	 if (firstNode == nullptr || firstNode->nextNode == nullptr) {
        return; // No need to swap if there are 0 or 1 nodes
     }

	 node* currentNode = firstNode;
	 node* prevNode = nullptr;
	 firstNode = firstNode->nextNode;

	 while (currentNode != nullptr && currentNode->nextNode != nullptr)
	 {
		 node* forwardNode = currentNode->nextNode;
		 currentNode->nextNode = forwardNode->nextNode;
		 forwardNode->nextNode = currentNode;
		 
		 if (prevNode != nullptr)
		 {
			 prevNode->nextNode = forwardNode;
		 }
		 prevNode = currentNode;
		 currentNode = currentNode->nextNode;
	 }

 };
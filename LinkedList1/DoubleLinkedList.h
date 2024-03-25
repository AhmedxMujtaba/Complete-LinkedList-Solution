#pragma once
#include <iostream>
using namespace std;

class DoubleLinkedList {

private:
    struct node {
        int data;
        node* nextNode;
        node* previousNode;
    }*firstNode;

public:
    DoubleLinkedList() {
        firstNode = nullptr;
    }

    void insertAtEnd(int data) {
        node* newNode = new node;
        newNode->data = data;
        newNode->nextNode = nullptr;

        if (!firstNode) {
            firstNode = newNode;
            firstNode->previousNode = nullptr;
        }
        else {
            node* currentNode = firstNode;
            while (currentNode->nextNode) {
                currentNode = currentNode->nextNode;
            }
            currentNode->nextNode = newNode;
            newNode->previousNode = currentNode;
        }
    }

    void insertAtStart(int data) {
        node* newNode = new node;
        newNode->data = data;
        newNode->previousNode = nullptr;

        if (!firstNode) {
            newNode->nextNode = nullptr;
        }
        else {
            newNode->nextNode = firstNode;
            firstNode->previousNode = newNode;
        }
        firstNode = newNode;
    }

    void deleteNode(int data) {
        if (!firstNode) {
            return; // Empty list
        }

        node* currentNode = firstNode;

        // Special case: deleting the only node in the list
        if (currentNode->data == data && currentNode->nextNode == nullptr) {
            delete currentNode;
            firstNode = nullptr;
            return;
        }

        // Delete the first node
        if (currentNode->data == data) {
            firstNode = currentNode->nextNode;
            if (firstNode) {
                firstNode->previousNode = nullptr;
            }
            delete currentNode;
            return;
        }

        while (currentNode != nullptr) {
            if (currentNode->data == data) {
                // Delete node from between
                currentNode->previousNode->nextNode = currentNode->nextNode;
                if (currentNode->nextNode) {
                    currentNode->nextNode->previousNode = currentNode->previousNode;
                }
                delete currentNode;
                return;
            }
            currentNode = currentNode->nextNode;
        }
    }

    void display() {

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


    //todo needs fixing
    //swap alternative nodes with their realtive position starting from back.
    void alternateSwapper() {

        /*
            Things to keep in mind
            -we need total length so we can precisely check all conditions and be varry of null pointer error
            -need the last node
            -need the middle node if any in case of odd nodes and in case of even there isnt a middle node so
             we need some other condition to check for it
            -need to make sure that nodes are more than three so we can swap them else no swaping
            -swaping begins after the first node and skips one node, and the last node is also skipped whle comming
             from reverse and so on

        */
        node* currentNode = firstNode;

        //condition to check nodes more than three
        if (firstNode == nullptr || currentNode->nextNode == nullptr || currentNode->nextNode->nextNode == nullptr)
        {
            cout << "No swaping Niga" << endl;
            return;
        }

        //to keep the last node
        node* lastNode = nullptr;

        //now finding number of nodes
        int totalNodes = 0;
        while (currentNode != nullptr)
        {
            totalNodes++;
            if (currentNode->nextNode == nullptr)
            {
                lastNode = currentNode;
            }
        }
        currentNode = firstNode;
        //checking for odd or even nodes
        bool isEven = false;
        if (totalNodes % 2 == 0)
        {
            isEven = true;
        }


        //Now a loop for nodes >3 and checking if nodes are even or odd, then make a seperate function to impliment swaping
        while (true)
        {
            //if even check for currentNode->previousNode == lastNode->nextNode break;
            //if odd check for currentNode == lastNode break;
            if (currentNode->previousNode == lastNode->nextNode && isEven)
            {
                break;
            }
            else if (currentNode == lastNode && !isEven)
            {
                break;
            }
            currentNode = currentNode->nextNode;
            lastNode = lastNode->previousNode;
            swapNodes(currentNode, lastNode);
            currentNode = currentNode->nextNode;
            lastNode = lastNode->previousNode;
        }

    };

    void swapNodes(node* node1, node* node2) {

        //check if list is empty or one node
        if (firstNode == nullptr || firstNode->nextNode == nullptr)
        {
            cout << "No nodes to swap" << endl;
            return;
        }

        node* tempNode = node2;
        node2->nextNode = node1;
        node1->nextNode = tempNode->nextNode;
        node2->previousNode = node1->previousNode;
        node1->previousNode = tempNode->previousNode;
    }

    void reverseList() {
        node* currentNode = firstNode;
        node* prevNode = nullptr;

        while (currentNode != nullptr) {
            // Swap next and previous pointers of the current node
            node* nextNode = currentNode->nextNode;
            currentNode->nextNode = currentNode->previousNode;
            currentNode->previousNode = nextNode;

            // Move to the next node
            prevNode = currentNode;
            currentNode = nextNode;
        }

        // Update the firstNode pointer to point to the last node (prevNode)
        firstNode = prevNode;
    }


};


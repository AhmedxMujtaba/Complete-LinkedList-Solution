#pragma once

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

	};

};
#include <iostream>
#include "SingleLinkedList.h"
#include "CircularList.h"

using namespace std;

int main() {
	CircularList list;
	
	list.appendNodeAtEnd(1);
	list.appendNodeAtEnd(2);
	list.appendNodeAtEnd(31);
	list.appendNodeAtEnd(4);
	list.appendNodeAtEnd(5);
	list.insertAt(200,3);
	list.display();
	return 0;
}
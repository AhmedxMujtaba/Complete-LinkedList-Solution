#include <iostream>
#include "SingleLinkedList.h"
//#include "CircularLinkedList.h"

using namespace std;

int main() {
	SingleLinkedList list;
	list.insertEnd(1);
	list.insertEnd(2);
	list.insertEnd(3);
	list.insertEnd(4);
	list.insertEnd(5);
	list.insertEnd(6);
	list.displayList();
	list.swapNodes(2, 6);

	list.displayList();
	return 0;
}
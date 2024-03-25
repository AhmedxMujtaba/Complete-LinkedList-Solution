#pragma once
template<typename T>
class DoubleLinkedListT {
public:
    struct Node {
        T data;
        Node* nextNode;
        Node* previousNode;
    }*firstNode;

public:
    DoubleLinkedListT() {
        firstNode = nullptr;
    }

    ~DoubleLinkedListT() {
        clear();
    }

    void insertAtEnd(T data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->nextNode = nullptr;

        if (!firstNode) {
            firstNode = newNode;
            firstNode->previousNode = nullptr;
        }
        else {
            Node* currentNode = firstNode;
            while (currentNode->nextNode) {
                currentNode = currentNode->nextNode;
            }
            currentNode->nextNode = newNode;
            newNode->previousNode = currentNode;
        }
    }

    void deleteNode(T data) {
        if (!firstNode) {
            return; // Empty list
        }

        Node* currentNode = firstNode;

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
    };

    void display() {
        Node* iterativeNode = firstNode;
        int count = 1;
        while (iterativeNode != nullptr) {
            cout << count++ << "- " << iterativeNode->data << endl;
            iterativeNode = iterativeNode->nextNode;
        }
    };

    T find(const T& targetData) {
        Node* currentNode = firstNode;
        while (currentNode != nullptr) {
            if (currentNode->data == targetData) {
                return currentNode->data;
            }
            currentNode = currentNode->nextNode;
        }
        return T(); // Return a default-constructed T if not found
    };

private:
    void clear() {
        Node* currentNode = firstNode;
        while (currentNode != nullptr) {
            Node* nextNode = currentNode->nextNode;
            delete currentNode;
            currentNode = nextNode;
        }
        firstNode = nullptr;
    }
};
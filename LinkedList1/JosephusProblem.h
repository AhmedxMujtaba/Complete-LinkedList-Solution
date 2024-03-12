#pragma once
#include <string>
#include <iostream>
using namespace std;

class JosephusProblem {
private:
    struct Node {
        string name;
        Node* nextNode;
        Node(const string& n) : name(n), nextNode(nullptr) {}
    };
    Node* firstNode;
    string playerName;

public:
    JosephusProblem() : firstNode(nullptr) {}

    void startGame() {
        int N, M, position;
        cout << "Josephus's Game" << endl;
        askUserName();
        cout << "Enter the number of people playing the game: ";
        cin >> N;
        addNPeople(N);
        displayContestants();
        cout << "Enter your position: ";
        cin >> position;
        playerPosition(position);
        displayContestants();
        cout << "Enter the value of M: ";
        cin >> M;
        kill(M);
    }

    void addNPeople(int N) {
        string name;
        for (int i = 0; i < N; ++i) {
            cout << "Enter name of player " << i + 1 << ": ";
            cin >> name;
            addPeople(name);
        }
    }

    void addPeople(const string& name) {
        Node* newNode = new Node(name);
        if (!firstNode) {
            firstNode = newNode;
            newNode->nextNode = firstNode; // Circular list
        }
        else {
            Node* lastNode = firstNode;
            while (lastNode->nextNode != firstNode) {
                lastNode = lastNode->nextNode;
            }
            lastNode->nextNode = newNode;
            newNode->nextNode = firstNode;
        }
    }

    void kill(int M) {
        if (!firstNode) {
            cout << "No contestants." << endl;
            return;
        }
        Node* currentNode = firstNode;
        Node* previousNode = nullptr;
        while (currentNode->nextNode != currentNode) {
            // Move M-1 steps
            for (int i = 0; i < M - 1; ++i) {
                previousNode = currentNode;
                currentNode = currentNode->nextNode;
            }
            previousNode->nextNode = currentNode->nextNode;
            cout << currentNode->name << " has been killed." << endl;
            delete currentNode;
            currentNode = previousNode->nextNode;
        }
        cout << "The winner is " << currentNode->name << endl;
        delete currentNode; // delete last remaining node
        firstNode = nullptr; // Reset firstNode
    }

    void playerPosition(int position) {
        if (!firstNode) {
            cout << "No contestants to set position." << endl;
            return;
        }
        Node* newNode = new Node(playerName);
        Node* currentNode = firstNode;
        Node* previousNode = nullptr;
        for (int i = 1; i < position && currentNode->nextNode != firstNode; ++i) {
            previousNode = currentNode;
            currentNode = currentNode->nextNode;
        }
        newNode->nextNode = currentNode->nextNode;
        currentNode->nextNode = newNode;
        if (position == 1) { // If inserting at the first position, update firstNode
            firstNode = newNode;
        }
    }

    void displayContestants() {
        if (!firstNode) {
            cout << "No contestants." << endl;
            return;
        }
        cout << "Contestants: ";
        Node* currentNode = firstNode;
        do {
            cout << currentNode->name << " ";
            currentNode = currentNode->nextNode;
        } while (currentNode != firstNode);
        cout << endl;
    }

    void askUserName() {
        cout << "Enter your name: ";
        cin >> playerName;
    }
};

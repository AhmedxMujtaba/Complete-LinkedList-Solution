#pragma once
#include <string>
#include <iostream>
#include <cctype>
#include <stack>

using namespace std;

class Stack {
public:
    struct Node {
        string data;
        int num;
        Node* nextNode;
        Node(string data) : data(data), nextNode(nullptr) {}
    };


    Node* top;

    Stack() : top(nullptr) {}

    void push(string data) {
        Node* newNode = new Node(data);
        newNode->nextNode = top; // Set newNode's nextNode to current top
        top = newNode; // Update top to newNode
    }

    string pop() {
        if (top == nullptr) {
            cout << "Stack is Empty\n";
            return "";
        }
        Node* temp = top;
        string tempData = top->data;
        top = top->nextNode;
        delete temp;
        return tempData;
    }

    string peek() {
        if (top == nullptr) {
            return "";
        }
        return top->data;
    }

    int size() {
        int count = 0;
        Node* currentNode = top;
        while (currentNode != nullptr) {
            count++;
            currentNode = currentNode->nextNode;
        }
        return count;
    }

    void display() {
        if (top == nullptr) {
            cout << "Stack is Empty []\n";
            return;
        }
        Node* currentNode = top;
        while (currentNode != nullptr) {
            cout << currentNode->data << " "; // Debugging output
            currentNode = currentNode->nextNode;
        }
        cout << endl;
    }

    bool parenthesisChecker() {
        string equation = equationInput();
        return isClosed(equation);
    }

    string equationInput() {
        cout << "Enter the Equation: ";
        string equation;
        cin >> equation;
        return equation;
    }

    bool isClosed(string equation) {
        string openingBrackets = "([{";
        string closingBrackets = ")]}";
        Stack openBrackets;
        for (char& c : equation) {
            if (openingBrackets.find(c) != string::npos) {
                openBrackets.push(string(1, c));
            }
            else if (closingBrackets.find(c) != string::npos) {
                if (openBrackets.size() == 0) {
                    return false;
                }
                string topBracket = openBrackets.pop();
                if (openingBrackets.find(topBracket) != closingBrackets.find(c)) {
                    return false;
                }
            }
        }
        return openBrackets.size() == 0;
    }

    Stack generateRandomPacket() {}

    void eatYellow() {
        Stack newPacket;
        while (top != nullptr) {
            if (top->data != "Yellow") {
                newPacket.push(pop());
            }
            else {
                pop();
            }
        }
        Stack reversedPacket = newPacket.putCandiesBack();
        top = reversedPacket.top;
    }

    Stack putCandiesBack() {
        Stack candyPacket;
        while (top != nullptr) {
            candyPacket.push(pop());
        }
        return candyPacket;
    }

  
    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }
    bool isInteger(const std::string& s) {
        try {
            std::stoi(s);
            return true;
        }
        catch (const std::invalid_argument&) {
            return false;
        }
        catch (const std::out_of_range&) {
            return false;
        }
    }
    int evaluatePrefix(string expression) {
    stack<int> operands;

    // Scan the expression from right to left
    for (int i = expression.size() - 1; i >= 0; i--) {
        char token = expression[i];

        // If token is an operand, push it onto the stack
        if (isdigit(token)) {
            operands.push(token - '0'); // Convert char to int
        }
        // If token is an operator, pop two operands, perform operation, and push result
        else if (token == '+' || token == '-' || token == '*' || token == '/') {
            int operand1 = operands.top(); operands.pop();
            int operand2 = operands.top(); operands.pop();
            int result;

            // Perform operation based on the operator
            switch (token) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            // Push the result onto the stack
            operands.push(result);
        }
    }
    // The result will be the only value left on the stack
    return operands.top();
}
    int precedence(char op) {
        if (op == '+' || op == '-') {
            return 1;
        }
        else if (op == '*' || op == '/') {
            return 2;
        }
        return 0;
    }
    string infixToPrefix(string infix) {
        stack<char> operatorStack;
        string prefix = "";
        // Reverse the infix expression
        reverse(infix.begin(), infix.end());

        for (char& c : infix) {
            if (c == ' ') {
                continue; // Skip whitespace
            }
            if (isdigit(c)) {
                // If character is a digit, add it to the prefix string
                prefix += c;
            }
            else if (c == ')') {
                // If character is ')', push it onto the operator stack
                operatorStack.push(c);
            }
            else if (c == '(') {
                // If character is '(', pop operators from the stack and add them to the prefix until ')' is encountered
                while (!operatorStack.empty() && operatorStack.top() != ')') {
                    prefix += operatorStack.top();
                    operatorStack.pop();
                }
                // Pop the ')' from the stack
                operatorStack.pop();
            }
            else if (isOperator(c)) {
                // If character is an operator
                // Pop operators from the stack and add them to the prefix if their precedence is higher or equal
                while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(c)) {
                    prefix += operatorStack.top();
                    operatorStack.pop();
                }
                // Push the current operator onto the stack
                operatorStack.push(c);
            }
        }

        // Pop remaining operators from the stack and add them to the prefix
        while (!operatorStack.empty()) {
            prefix += operatorStack.top();
            operatorStack.pop();
        }

        // Reverse the prefix string to get the final result
        reverse(prefix.begin(), prefix.end());

        return prefix;
    }
};







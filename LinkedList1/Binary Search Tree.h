#pragma once
#include <iostream>;
using namespace std;

/*
A bsa tree like structure, uses nodes to store data and has a main root node a the top and then we
have left and right nodes. Left contains the smaller values then right and right has the bigger value

Hight is the no of edges (The number of childs something like that) from current node till the 
leaf (last node) of the tree

Depth is the no of edges from the current node till the tree root

        5       <- Root (Depth = 0, Height = 2)
       / \
      3   8     <- Depth = 1, Height = 1
     / \   \
    1   4   10  <- Depth = 2, Height = 1 for [10] || Height = 0 for [1] and [4] (Leaf)
             \
             15 <- Depth = 3, Height = 0 (Leaf)

*/

class Tree {

private:
    struct node
    {
        int data;
        node* left;
        node* right;
    }*root;

public:
    Tree() {
        root = nullptr;
    };
    void insertNode(node* rootNode, node* newNode);
    void traversePreOrder(node* node);
    void traverseInOrder(node* node);
    void traversePostOrder(node* node);
    node* search(int data);
};

void Tree::insertNode(node* rootNode, node* newNode) {

    //check if this is the first node of the tree
    if (root == nullptr) {
        root = newNode;
        root->left = nullptr;
        root->right = nullptr;
        root->data = newNode->data;
        return;
    }

    //check if data is being repeated
    if (root->data == newNode->data)
    {
        cout << "Data is being repeated" << endl;
    }

    //Main if conditions to check for the data size and organize it in the tree

    if (newNode->data < rootNode->data)
    {
        //if data is lesser than the root node
        if (rootNode->left != nullptr)
        {
            insertNode(rootNode->left, newNode);
        }
        else
        {
            rootNode->left = newNode;
            rootNode->left->left = nullptr;
            rootNode->left->right = nullptr;
            return;
        }
    }
    //else if data is greater than the root node
    else
    {
        if (rootNode->right != nullptr)
        {
            insertNode(rootNode->right, newNode);
        }
        else
        {
            rootNode->right = newNode;
            rootNode->right->left = nullptr;
            rootNode->right->right = nullptr;
            return;
        }
    }
};
void Tree::traversePreOrder(node* temp)
{
    if (temp != nullptr)
    {
        cout << " " << temp->data;
        traversePreOrder(temp->left);
        traversePreOrder(temp->right);
    }
};
void Tree::traverseInOrder(node* temp) {
    if(temp != nullptr) 
    {
        traverseInOrder(temp->left);
        cout << " " << temp->data;
        traverseInOrder(temp->right);
    }
};
void Tree::traversePostOrder(node* temp) {
    if(temp != nullptr) 
    {
        traversePostOrder(temp->left);
        traversePostOrder(temp->right);
        cout << " " << temp->data;
    }
};
node* Tree::search(int data) {

};

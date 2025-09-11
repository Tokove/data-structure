#include"BinarySearchTree.h"

// Recursive version
BstNode* BinarySearchTree::Insert(BstNode* root, int val){
    if(root == nullptr) root = new BstNode{val, nullptr, nullptr};
    else if(val <= root->data) root->left = Insert(root->left, val);
    else root->right = Insert(root->right, val);
    return root;
}

void BinarySearchTree::Insert(int val){ root = Insert(root, val); }

// Iterative version
/*
void BinarySearchTree::Insert(int val) {
    BstNode* newNode = new BstNode{val, nullptr, nullptr};

    if (root == nullptr) { 
        root = newNode;
        return;
    }

    BstNode* curr = root;
    BstNode* parent = nullptr;

    while (curr != nullptr) {
        parent = curr;
        if (val <= curr->data) curr = curr->left;
        else curr = curr->right;
    }
    
    if (val <= parent->data) parent->left = newNode;
    else parent->right = newNode;
}
*/

// Recursive version
bool BinarySearchTree::Search(BstNode* root, int val) const{
    if(root == nullptr) return false;
    else if(val == root->data) return true;
    else if(val < root->data) return Search(root->left, val);
    else return Search(root->right, val);
}

bool BinarySearchTree::Search(int val) const { return Search(root, val); }

// Iterative version
/*
bool BinarySearchTree::Search(int val) const {
    BstNode* curr = root;
    while (curr != nullptr) {
        if (val == curr->data) return true;
        if (val < curr->data)  curr = curr->left;
        else  curr = curr->right;
    }
    return false;
}
*/

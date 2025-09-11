#include"BinarySearchTree.h"

// Recursive version
BstNode* BinarySearchTree::Insert(BstNode* root, int val){
    if(root == nullptr) root = new BstNode{val, nullptr, nullptr};
    else if(val <= root->data) root->left = Insert(root->left, val);
    else root->right = Insert(root->right, val);
    return root;
}

void BinarySearchTree::Insert(int val){ root = Insert(root, val); }

bool BinarySearchTree::Search(BstNode* root, int val) const{
    if(root == nullptr) return false;
    else if(val == root->data) return true;
    else if(val < root->data) return Search(root->left, val);
    else return Search(root->right, val);
}

bool BinarySearchTree::Search(int val) const { return Search(root, val); }

int BinarySearchTree::FindMin(BstNode* root) const {
    if(root == nullptr) throw std::out_of_range("Tree is empty");
    if(root->left == nullptr) return root->data;
    return FindMin(root->left);
}

int BinarySearchTree::FindMin() const { return FindMin(root); }

int BinarySearchTree::FindMax(BstNode* root) const {
    if(root == nullptr) throw std::out_of_range("Tree is empty");
    if(root->right == nullptr) return root->data;
    return FindMax(root->right);
}

int BinarySearchTree::FindMax() const { return FindMax(root); }

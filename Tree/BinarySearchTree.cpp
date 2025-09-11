#include"BinarySearchTree.h"

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

#include"BinarySearchTreee.h"

BstNode* BinarySearchTree::Insert(BstNode* root, int val){
    if(root == nullptr){
        BstNode* newNode = new BstNode();
        newNode->data = val;
        newNode->left = newNode->right = nullptr;
        root = newNode;
    }else if(val <= root->data){
        root->left = Insert(root->left, val);
    }else{
        root->right = Insert(root->right, val);
    }
    return root;
}

bool BinarySearchTree::Search(BstNode* root, int val) const{
    if(root == nullptr) return false;
    else if(val == root->data) return true;
    else if(val < root->data) return Search(root->left, val);
    else return Search(root->right, val);
}

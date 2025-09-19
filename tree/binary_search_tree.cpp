#include"binary_search_tree.h"

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

void BinarySearchTree::LevelOrder() const {
    if(root == nullptr) return;
    std::queue<BstNode*> q;
    q.push(root);
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        std::cout << t->data << ' ';
        if(t->left) q.push(t->left);
        if(t->right) q.push(t->right);
    }
    std::cout << std::endl;
}

void BinarySearchTree::PreOrder(BstNode* root) const {
    if(root == nullptr) return;
    std::cout << root->data << ' ';
    PreOrder(root->left);
    PreOrder(root->right);
}

void BinarySearchTree::PreOrder() const { 
    PreOrder(root); 
    std::cout << std::endl;
}

void BinarySearchTree::InOrder(BstNode* root) const {
    if(root == nullptr) return;
    InOrder(root->left);
    std::cout << root->data << ' ';
    InOrder(root->right);
}

void BinarySearchTree::InOrder() const { 
    InOrder(root); 
    std::cout << std::endl;
}

void BinarySearchTree::PostOrder(BstNode* root) const{
    if(root == nullptr) return;
    PostOrder(root->left);
    PostOrder(root->right);
    std::cout << root->data << ' ';
}

void BinarySearchTree::PostOrder() const {
    PostOrder(root); 
    std::cout << std::endl;
}

bool BinarySearchTree::IsBST(BstNode* root, int minValue, int maxValue) const {
    if(root == nullptr) return true;
    if(root->data <= minValue || root->data >= maxValue) return false;
    return IsBST(root->left, minValue, root->data) 
        && IsBST(root->right, root->data, maxValue);
    
}

bool BinarySearchTree::IsBST() const { return IsBST(root, INT_MIN, INT_MAX); }

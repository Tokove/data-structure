#pragma once
// Create a node
struct BstNode
{
    int data;
    BstNode* left;  // Left child
    BstNode* right; // Right child
};

class BinarySearchTree
{
private:
    BstNode* root;
    BstNode* Insert(BstNode* root, int val);
    bool Search(BstNode* root, int val) const;
    int FindMin(BstNode* root) const;
    int FindMax(BstNode* root) const;
public:
    BinarySearchTree():root(nullptr){}
    ~BinarySearchTree();
    void Insert(int val);
    bool Search(int val) const;
    int FindMin() const;
    int FindMax() const;
    void LevelOrder() const;
};

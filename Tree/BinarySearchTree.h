// 二叉搜索树
#pragma once
// 创建节点
struct BstNode
{
    int data;
    BstNode* left;  // 左子节点
    BstNode* right; // 右子节点
};

class BinarySearchTree
{
private:
    BstNode* root;
    BstNode* Insert(BstNode* root, int val);
    bool Search(BstNode* root, int val) const;
public:
    BinarySearchTree():root(nullptr){}
    ~BinarySearchTree();
    void Insert(int val);
    bool Search(int val) const;
};

// 栈

// 创建节点
struct Node
{
    int data;
    Node* link;
};

class Stack
{
private:
    Node* top;
    int size;
public:
    Stack():top(nullptr){}
    ~Stack();
    void Push(int val);
    void Pop();
    int Top();
    int Size()const;
    bool Empty()const;
};

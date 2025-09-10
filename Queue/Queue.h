// 队列

// 创建节点
struct Node
{
    int data;
    Node* link;
};

class Queue
{
private:
    Node* front;
    Node* back;
    int size;
public:
    Queue():front(nullptr), back(nullptr), size(0){}
    ~Queue();
    void Push(int val);
    void Pop();
    int Front() const;
    int Back() const;
    bool Empty() const;
    int Size() const;
};

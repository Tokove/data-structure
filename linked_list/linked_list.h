#pragma once
// Create a node
struct Node 
{
	int data;
	Node* next;
};

class LinkedList
{
private:
	Node* head;
	int size;
public:
	LinkedList() : head(nullptr), size(0) {}
	~LinkedList();
	void Insert(int value);
	void Insert(int index, int value);
	void Delete(int index);
	void Print()const;
	void Reverse();
};

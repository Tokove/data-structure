#include"stack.h"
#include<iostream>

void Stack::Push(int val){
    Node* temp = new Node();
    temp->data = val;
    temp->link = top;
    top = temp;
    size++;
}

void Stack::Pop(){
    if(top == nullptr){
        throw std::out_of_range("Stack is empty");
    }
    int val = top->data;
    Node* temp = top;
    top = top->link;
    delete temp;
    size--;
}

int Stack::Top() const {
    if(top == nullptr){
        throw std::out_of_range("Stack is empty");
    }
    return top->data;
}

int Stack::Size() const { return size; }

bool Stack::Empty() const { return top == nullptr; }

Stack::~Stack(){
    while(top){
        Node* temp = top;
        top = top->link;
        delete temp;
    }
}

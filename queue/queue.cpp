#include"queue.h"
#include<iostream>

void Queue::Push(int val){
    Node* temp = new Node();
    temp->data = val;
    temp->link = nullptr;
    if(front == nullptr && back == nullptr){ // Equivalent to front == nullptr
        front = back = temp;
        return ;
    }
    back->link = temp;
    back = temp;
    size++;
}

void Queue::Pop(){
    if(front == nullptr){
        throw std::out_of_range("Queue is empty");
    }
    Node* temp = front;
    if(front == back){
        front = back = nullptr;
    }else{
        front = front->link;
    }
    delete temp;
    size--;
}

int Queue::Front() const {
    if(front == nullptr){
        throw std::out_of_range("Queue is empty");
    }
    return front->data;
}

int Queue::Back() const {
    if(back == nullptr){
        throw std::out_of_range("Queue is empty");
    }
    return back->data;
}

bool Queue::Empty() const { return front == nullptr; }

int Queue::Size() const { return size; }

Queue::~Queue(){
    while(front){
        Node* temp = front;
        front = front->link;
        delete temp;
    }
}

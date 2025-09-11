#include"linked_list.h"
#include<iostream>

void LinkedList::Insert(int value)
{
	Node* temp = new Node();
	temp->data = value;
	temp->next = head;
	head = temp;
	size++;
}

void LinkedList::Insert(int index, int value)
{
	if (index < 1 || index > size + 1)
		throw std::out_of_range("Insert out of range");
	if (index == 1){
		Insert(value);
		return;
	}
	Node* temp1 = head;
	for (int i = 1; i < index - 1; i++)
		temp1 = temp1->next;
	Node* temp = new Node();
	temp->data = value;
	temp->next = temp1->next;
	temp1->next = temp;
	size++;
}

void LinkedList::Delete(int index)
{
	if (index < 1 || index > size)
		throw std::out_of_range("Delete out of range");
	Node* temp = head;
	if (index == 1) {
		head = temp->next;
		delete temp;
		size--;
		return;
	}
	for (int i = 1; i < index - 1; i++)
		temp = temp->next;
	Node* temp1 = temp->next;
	temp->next = temp1->next;
	delete temp1;
	size--;
}

void LinkedList::Print() const
{
	Node* temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std:: cout << std::endl;
}

void LinkedList::Reverse()
{
	Node* prev = nullptr;
	Node* next = nullptr;
	Node* current = head;
	while (current != nullptr) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

LinkedList::~LinkedList()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		Node* temp1 = temp->next;
		delete temp;
		temp = temp1;
	}
}

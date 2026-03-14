#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename T>
struct Node
{
  T data;
  Node* next;

  Node(T value) : data{value}, next{nullptr} {}
};

template <typename T>
class LinkedList
{
private:
  Node<T>* head;

public:
  // Cosntructs an empty list.
  LinkedList() : head{nullptr} {}
  
  // Destructs the list.
  ~LinkedList()
  {
    Node<T>* current = head;

    while (current != nullptr)
    {
      Node<T>* nextNode = current->next;
      delete current;
      current = nextNode;
    }
    head = nullptr;
  }

  void insertAtHead(T value)
  {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
  }

  void display() const
  {
    Node<T>* temp = head;

    while (temp != nullptr)
    {
      std::cout << temp->data << " -> ";
      temp = temp->next;
    }

    std::cout << "nullptr" << std::endl;
  }
};

#endif

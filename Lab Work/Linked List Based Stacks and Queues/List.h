/*
 * Name: Sam Pupke
 * Date Submitted: Jan 30 2024
 * Lab Section: 002
 * Assignment Name: Lab 1: Linked List Based Stacks and Queues
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

// This class represents a linked list of node objects
// Do not modify anything in the class interface
template <class T>
class List
{

private:
  Node<T> *start; // pointer to the first node in this list
  int mySize;     // size (or length) of this list

public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  // Print the name and this list's size and values to stdout
  // This function is already implemented (no need to change it)
  void print(string name)
  {
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> *iterator = start;
    while (iterator != nullptr)
    {
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; // end of class interface (you may modify the code below)

// Implement all of the functions below
// Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List()
{
  start = nullptr;
  mySize = 0;
}

// Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List()
{
  while (!empty())
  {
    removeEnd();
  }
  mySize=0;
}

// Return the size of this list
template <class T>
int List<T>::size()
{

  Node<T> *current = start;
  if (current == nullptr)
  {
    return 0;
  }
  else
  {
    int counter = 1;
    while (current->next != nullptr)
    {
      current = current->next;
      counter++;
    }
    mySize = counter;
    return counter;
  }
}

// Return true if this list is empty
// Otherwise, return false
template <class T>
bool List<T>::empty()
{
  Node<T>* current = start;
  if(current==nullptr) {
    return true;
  } else {
    return false;
  }
}

// Create a new node with value, and insert that new node
// into this list at start
template <class T>
void List<T>::insertStart(T value)
{
  Node<T>* newNode;
  newNode->next = start;
  newNode->value=value;
  start=newNode;
  mySize++;
}

// Create a new node with value, and insert that new node
// into this list at end
template <class T>
void List<T>::insertEnd(T value)
{
  mySize++;
  Node<T>* newNode;
  newNode->next=nullptr;
  newNode->value=value;
  Node<T>* current = start;
  while(current->next!=nullptr) {
    current=current->next;
  }
  current->next=newNode;
}

// Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j)
{
  Node<T>* newNode;
  newNode->value=value;

  if(mySize>=j) {
  mySize++;
    Node<T>* current = start;
    for(int i = 0; i<j; i++) {
      current=current->next;
    }
    newNode->next = current->next;
    current->next = newNode->next;
  } //can't else because void func
}

// Remove node at start
// Make no other changes to list
template <class T>
void List<T>::removeStart()
{
  if(!empty()) {
    mySize--;
    Node<T>* delscratch = start;
    start=start->next;
    delete delscratch;
  }
}

// Remove node at end
// Make no other changes to list
template <class T>
void List<T>::removeEnd()
{
  if(mySize==1) {
    removeStart();
  } else if(!empty()) {
    mySize--;
    Node<T>* current = start;
    while(current->next->next!=nullptr) {
      current=current->next;
    }
    delete current->next;
    current->next=nullptr;
  }
}

// Remove node at position j
// Make no other changes to list
template <class T>
void List<T>::removeAt(int j)
{
  mySize--;
}

// Return the value of the first node in the Linked List,
// If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst()
{
}

// Return the value of the last node in the Linked List,
// If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast()
{
}

// Return the value of the node at position j in the Linked List,
// If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j)
{
}

// Return the position of the (first) node whose value is equal to the key
// Otherwise, return -1
template <class T>
int List<T>::find(T key)
{
  Node<T>* current = start;
  int checkIndex = 0;
  int foundIndex = -1;
  while(current->value!=key){
    checkIndex++;
    current = current->next;

  }
  return foundIndex;
}

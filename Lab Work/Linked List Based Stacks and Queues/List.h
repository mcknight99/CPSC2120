/*
 * Name: Sam Pupke
 * Date Submitted: Jan 30 2024
 * Lab Section: 002
 * Assignment Name: Lab 1: Linked List Based Stacks and Queues
 */

// -1073741819 Segfault

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
  //std::cout<<"destructing linked list\n";
  while (!empty())
  {
    removeStart();
  }
  mySize=0; //should already be zero after removeStart()s but whatever
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
  if(mySize==0) {
    Node<T>* newNode = new Node<T>(value);
    start=newNode;
    start->next=nullptr;
    mySize++;
    //std::cout<<"inserted "<<value<<" at start\n";
  } else {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = start;
    start=newNode;
    mySize++;
    //std::cout<<"inserted "<<value<<" at start\n";
  }
}

// Create a new node with value, and insert that new node
// into this list at end
template <class T>
void List<T>::insertEnd(T value)
{
  if(mySize==0) {
    Node<T>* newNode = new Node<T>(value);
    start=newNode;
    mySize++;
    //std::cout<<"inserted " << value << " at end\n";
  } else {
    mySize++;
    Node<T>* newNode = new Node<T>(value);
    Node<T>* current = start;
    while(current->next!=nullptr) {
      current=current->next;
    }
    current->next=newNode;
    //std::cout<<"inserted " << value << " at end\n";
  }
}

// Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j)
{

  if(mySize>j) { // > because mySize will be one larger than the index of the last value
  if(j==0) {
    insertStart(value);
  } else if(j==mySize) {
    insertEnd(value);
  } else {
    // ex. size of 10, last index is 9. if j is 10, no such index exists
    Node<T>* newNode = new Node<T>(value);
    //std::cout<<"inserting "<<value<<" at "<<j<<std::endl;
    mySize++;
      Node<T>* current = start;
      for(int i = 0; i<j-1; i++) { //-1 because inserting at index j will put the newNode after the current node without it
        current=current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
    } //can't error else because void func
  }
}

// Remove node at start
// Make no other changes to list
template <class T>
void List<T>::removeStart()
{
  if(!empty()) {
    mySize--;
    Node<T>* afterDel = start->next;
    //std::cout<<"removed start (" << start->value << ")\n";
    delete start;
    start=afterDel;
  }
}

// Remove node at end
// Make no other changes to list
template <class T>
void List<T>::removeEnd()
{
  if(mySize==1) { //doing this to be able to store backwards one node, and the start doesn't have a node before it
    //std::cout<<"removing end of one long list, ";
    removeStart();
  } else if(!empty()) { //it's times like this that i'd like to use doubly linked lists
    mySize--;
    Node<T>* current = start;
    while(current->next->next!=nullptr) {
      current=current->next;
    }
    //std::cout<<"removing end (" << current->next->value << ")\n";
    delete current->next;
    current->next=nullptr;
  }
}

// Remove node at position j
// Make no other changes to list
template <class T>
void List<T>::removeAt(int j)
{
  if(mySize>j)  {
    mySize--;
    Node<T>* current = start;
    for(int i = 0; i<j-1; i++) { //j-1 to land on the node before the node to remove
      current = current->next;
    }
    Node<T>* afterDel = current->next->next; //the node that comes after the deleted node
    delete current->next; //delete the actual memory 
    // I initially wanted to make a new Nodeptr and store the deleted node then delete the nodeptr, 
    // but wasn't sure if it deleted the actual memory so this fixes it in a roundabout way.
    // Working backwards, I fixed this in removeStart() as well, and removeEnd() had no such issue.
    current->next = afterDel;
  }
}

// Return the value of the first node in the Linked List,
// If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst()
{
  if(!empty()) {
  return start->value;
  } else {
    return T();
  }
}

// Return the value of the last node in the Linked List,
// If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast()
{
  Node<T>* current = start;
  //in retrospect, I've written this while loop a lot, and it may have been good
  //to have a helper function to return the node instead of the value for
  //select functions, like a getLastNode() function instead of rewriting the iterator
  while(current->next!=nullptr) { 
    current=current->next;
  }
  return current->value;
}

// Return the value of the node at position j in the Linked List,
// If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j)
{
  if(mySize>j && mySize!=0) {
    Node<T>* current = start;
    for(int i = 0; i<j; i++) {
      current = current->next;
    }
    return current->value;
  } else { //will also return T() if j is OOB
    return T();
  } 

}

// Return the position of the (first) node whose value is equal to the key
// Otherwise, return -1
template <class T>
int List<T>::find(T key)
{
  //std::cout<<"finding "<<key<<std::endl;
  Node<T>* current = start;
  int checkIndex = 0;
  while(current->value!=key && current->next!=nullptr){
    checkIndex++;
    current = current->next;
    
  }
  if(current->next==nullptr && current->value!=key) {
    //std::cout<<"didn't find it\n";
    return -1;
  } else {
    //std::cout<<"found it at "<<checkIndex<<std::endl;
    return checkIndex;
  }
}

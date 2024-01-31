#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

/*
Lina Goto
12/4/23
Linked list
 */

void add(int newvalue);
void print(Node* next);

static Node *head = NULL;

//add number in node
void add(int newvalue){
  Node *current = head;
  Node *newnode;
  //very first node; add new node and set value
  if (current == NULL) {
    head = new Node();
    head -> setValue(newvalue);
  } else {//find node which next is NULL - set new node by pointer and set value
    while (current -> getNext() != NULL){
      current = current -> getNext();
    }
    newnode = new Node();
    current -> setNext(newnode);
    current -> getNext() -> setValue(newvalue);
  }
}

//printing the node
void print (Node *next) {
  //if the node is very first print list:
  if (next == head){
    cout << "list: ";
  }
  //if the node is not null (until the last node) print the values
  if (next != NULL) {
    cout << next -> getValue() << " ";
    //recursive call
    print (next -> getNext());
    if (next -> getNext() == NULL) {
      cout << endl;
    }
  }
}

int main() {
  add(5);
  print(head);
  add(1);
  print(head);
  add(2);
  print(head);

  return 0;
}


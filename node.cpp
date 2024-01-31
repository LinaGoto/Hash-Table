#include "node.h"
#include "student.h"
#include <iostream>

Node::Node(){
  next = NULL;
}

Node::~Node(){
  next = NULL;
}

Student *Node::getStudent() {
  return &student;
}

Node* Node::getNext(){
  return next;
}

void Node::setNext(Node* newnext){
  next = newnext;
}

void Node::setValue(int newvalue) {
  student.setValue(newvalue);
}

int Node::getValue() {
  return student.getValue();
}

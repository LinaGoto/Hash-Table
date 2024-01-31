//code from Gorden Chen

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "student.h"

using namespace std;

class Node{
 public:
  Node(Student* newStudent);
  ~Node();
  Node* getNext();
  Student* getStudent();
  void setNext(Node* n);
 private:
  Node* next;
  Student* stud;
};

#endif

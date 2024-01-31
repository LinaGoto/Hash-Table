#ifndef NODE_H
#define NODE_H
#include "student.h"

class Node{
 public:

  //constructor destructor
  Node();
  ~Node();
  
  //get next Node pointer
  Node* getNext();

  //get student pointer
  Student *getStudent();

  //set the next pointer to the corresponding node pointer
  void setNext(Node* newnext);

  //set value
  void setValue(int);
  //get value
  int  getValue();

 private:
  Student student;
  Node *next;
};
#endif

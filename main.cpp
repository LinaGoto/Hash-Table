#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

/*
Lina Goto
1/3/24
Linked list
 */

#define	HASH_RANGE 101


void add(Student *newstudent);
void del(int id);
void print(Node* next);
void average(Node *next, int count, float sum);

static Node *head[HASH_RANGE] = {NULL};

//hash function
int hash(int id) {
  return id % HASH_RANGE;
}

// Recursive call function to find out last node
Node *findLastNode(Node *CurNode) {
  Node *RetNode;
  if (CurNode == NULL) {
    RetNode = NULL;
  } else if (CurNode -> getNext() == NULL) {
    RetNode = CurNode;
  } else {
    RetNode = findLastNode(CurNode -> getNext());
  }
  return RetNode;
}

// Recursive call function to find out previous Node
Node *findPreNode(Node *CurNode, Node *target) {
  Node *RetNode;
  if ((CurNode == NULL) || (CurNode == target)) {
    RetNode = NULL;
  } else if (CurNode -> getNext() == target) {
    RetNode = CurNode;
  } else {
    RetNode = findPreNode(CurNode -> getNext(), target);
  }
  return RetNode;
}

// Recursive call function to find out equal to specified ID
Node *findNodeWithID(Node *CurNode, int id) {
  Node *RetNode;
  if (CurNode == NULL) {
    RetNode = NULL;
  } else if (CurNode -> getStudent() -> getid() == id) {
    RetNode = CurNode;
  } else {
    RetNode = findNodeWithID(CurNode -> getNext(), id);
  }
  return RetNode;
}

// function to find out the node with the smallerst ID
Node *findNodeWithSmallestID(Node *CurNode) {
  Node *MinNode;
  
  if (CurNode == NULL) return NULL;
  
  MinNode = CurNode;
  CurNode = CurNode -> getNext();
  while (CurNode != NULL) {
    if (MinNode -> getStudent() -> getid() > CurNode -> getStudent() -> getid()) MinNode = CurNode;
    CurNode = CurNode -> getNext();
  }
  return MinNode;
}

// Recursive function to sort the node by the ID
void sortNode(Node *CurNode) {
  Node *MinNode, *PreCurNode, *PreMinNode;
  
  if ((CurNode == NULL) || (CurNode -> getNext() == NULL)) return;
  
  PreCurNode = findPreNode(head[0], CurNode);
  MinNode    = findNodeWithSmallestID(CurNode);
  PreMinNode = findPreNode(head[0], MinNode);

  // if MinNode is different, it will perform swap
  if (MinNode != CurNode) {
    PreMinNode -> setNext(MinNode -> getNext());
    MinNode -> setNext(CurNode);
    if (CurNode == head[0]) {
      head[0] = MinNode;
    } else {
      PreCurNode -> setNext(MinNode);
    }
    sortNode(CurNode);
  } else {
    sortNode(CurNode -> getNext());
  }
}

//add student in node
void add(Student *newstudent) {
  Node *LstNode, *NewNode;

  int hnumb = hash(newstudent -> getid());
  
  LstNode = findLastNode(head[hnumb]);
  NewNode = new Node(newstudent);
  
  //very first node; add new node and set value
  if (LstNode == NULL) {
    head[hnumb] = NewNode;
  } else {
      LstNode -> setNext(NewNode);
  }
}

//delete student in node
void del(int id){
  Node *CurNode, *PreNode;

  int hnumb = hash(id);
  
  // find the node which is same or larger than student ID
  CurNode = findNodeWithID(head[hnumb], id);
  // find the previous node
  PreNode = findPreNode(head[hnumb], CurNode);

  if (CurNode == NULL) return;

  if (CurNode == head[hnumb]) {
    head[hnumb] = CurNode -> getNext();
  } else {
    PreNode -> setNext(CurNode -> getNext());
  }

  delete CurNode;
}

//printing the node
void print (Node *next) {
  //if the node is very first print list:

  int hnumb == 0;
  
  if (next == head[hnumb]){
    cout << "ID  GPA  NAME " << endl;
  }
  //if the node is not null (until the last node) print the values
  if (next != NULL) {
    Student *student = next -> getStudent();
    //print out
    cout << student -> getid() << "  " << student -> getgpa() <<  " "  << student -> getname() << endl;
    //recursive call
    print (next -> getNext());
    if (next -> getNext() == NULL) {
      hnumb ++;
    }
    if (hnumb == 100){
       Student *student = next -> getStudent();
       //print out
       cout << student -> getid() << "  " << student -> getgpa() <<  " "  << student -> getname() << endl;
       //recursive call
       print (next -> getNext());
       cout << endl;
    }
  }
}

void average (Node *next, int count, float sum){
  //if the node is not null (until the last node) print the values
  if (next != NULL) {
    Student *student = next -> getStudent();
    //recursive call
    average (next -> getNext(), count + 1, sum + student -> getgpa());
    if (next -> getNext() == NULL) {
      count ++;
      sum += student -> getgpa();
      cout << sum / (float)count << endl;
    }
  }
}

int main() {
  Student *student;
  char input[10];
  
  do {
    cout << "ADD/PRINT/DELETE/AVERAGE/QUIT: " << endl;
    cin.get(input,10);
    cin.get();
    
    //if add
    if ((input[0] == 'A') || (input[0] == 'a')){
      if((input[1] == 'D') || (input[1] == 'd')){
	int id;
	float gpa;
	char name[NAME_LENGTH];
	//name
	cout << "Name:" << endl;
	cin.get(name, NAME_LENGTH);
	cin.get();
	//id
	cout << "ID:" << endl;
	cin >> id;
	cin.get();
	//gpa
	cout << "GPA:" << endl;
	cin >> gpa;
	cin.get();
	student = new Student();
	//add the values
	student -> setValue(id, gpa, name);
	add(student);
	sortNode(head[0]);
      }
    }
    
    //if print
    if ((input[0] == 'P') || (input[0] == 'p')){
      print (head[0]);
    }
    
    //if delete
    if((input[0] == 'D') || (input[0] == 'd')){
      int id;
      //get id
      cout << "Enter student id: " << endl;
      cin >> id;
      cin.get();
      del(id);
    }
    
    //if average
      if((input[0] == 'A') || (input[0] == 'a')){
	if((input[1] == 'V') || (input[1] == 'v')){
	  average(head[0], 0, 0);
      }
    }
    
  } while ((input[0] != 'Q') && (input[0] != 'q'));
  //end with quit
  
  return 0;
}


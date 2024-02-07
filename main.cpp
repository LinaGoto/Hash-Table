#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

/*
Lina Goto
1/31/24
Student list with hash table
 */

int hashfun(int id, int hash);
void add(Student *newstudent, int hash);
void del(int id, int hash);
void print(Node* next);
void average(Node *next, int count, float sum);

//hash function
int hashfun(int id, int hash) {
  return id % hash;
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

//add student in node
void add(Node **head, Student *newstudent, int hash) {
  Node *LstNode, *NewNode;
 
  int hnumb = hashfun(newstudent -> getid(), hash);
  
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
void del(Node **head, int id, int hash){
  Node *CurNode, *PreNode;

  int hnumb = hashfun(id, hash);
  
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
void print (int hnumb, Node *next) {
  //if the node is not null (until the last node) print the values
  if (next != NULL) {
    Student *student = next -> getStudent();
    //print out
    cout << student -> getid() << "  " << student -> getgpa() <<  " "  << student -> getname() << endl;
    //recursive call
    print (hnumb, next -> getNext());
  }
}

int longhash(Node **head, int hash){
  int hnumb;
  int maxlen = 0;
  //Go through all the maxlen and find the hash with maxhash linked list
  for (hnumb = 0; hnumb < hash; hnumb ++){
    Node *p = head[hnumb];
    int linknum = 0;
    while (p != NULL) {
      linknum ++;
      p = p -> getNext();
    }
    if (maxlen < linknum) maxlen = linknum;
  }
  return maxlen;
}

int main() {
  Student *student;
  char input[10];
  int hnumb;
  Node **head;
  int HASH_RANGE = 100;
  
  head = (Node **)malloc(HASH_RANGE * sizeof(Node));

  for (hnumb = 0; hnumb < HASH_RANGE; hnumb ++) head[hnumb] = NULL;

  do {
    cout << "ADD/PRINT/DELETE/QUIT: " << endl;
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
	add(head, student, HASH_RANGE);

	// repeat while check number of list is larger than 4
	while (longhash(head, HASH_RANGE) >= 4) {
	  int HASH_RANGE2 = HASH_RANGE + 1;
	  Node **newhead = (Node **)malloc(HASH_RANGE2 * sizeof(Node));
	  int hnumb;

	  for (hnumb = 0; hnumb < HASH_RANGE2; hnumb ++) newhead[hnumb] = NULL;
	  
	  for (hnumb = 0; hnumb < HASH_RANGE; hnumb ++) {
	    Node *p = head[hnumb];
	    Node *n;
	    while (p != NULL) {
	      int newhash = hashfun(p -> getStudent() -> getid(), HASH_RANGE2);
	      Node *LstNode = findLastNode(newhead[newhash]);

	      if (LstNode == NULL){
		newhead[newhash] = p;
	      }else{
		LstNode -> setNext(p);
	      }
	      // back up next Node
	      n = p -> getNext();
	      // reset Next Node
	      p -> setNext(NULL);
	      p = n;
	    }
	  }

	  // update pointer and hash value
	  HASH_RANGE = HASH_RANGE2;
	  // Release previous head
	  free(head);
	  // Update new nead
	  head = newhead;
	  cout << "Hash has been updated to " << HASH_RANGE << endl;
	}
      }
    }
    
    //if print
    if ((input[0] == 'P') || (input[0] == 'p')){
      cout << "  ID   GPA   NAME " << endl;
      for (hnumb = 0; hnumb < HASH_RANGE; hnumb ++) print (hnumb, head[hnumb]);
    }
    
    //if delete
    if((input[0] == 'D') || (input[0] == 'd')){
      int id;
      //get id
      cout << "Enter student id: " << endl;
      cin >> id;
      cin.get();
      del(head, id, HASH_RANGE);
    }
    
  } while ((input[0] != 'Q') && (input[0] != 'q'));
  //end with quit
  
  free(head);

  return 0;
}


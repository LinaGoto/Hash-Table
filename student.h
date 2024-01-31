#ifndef STUDENT_H
#define STUDENT_H

#define NAME_LENGTH	50

class Student {
 private:
  int id;
  float gpa;
  char name[NAME_LENGTH];
  
 public:
  int getid();
  float getgpa();
  char *getname();
  
  void setValue(int id, float gpa, char *name);
};
#endif

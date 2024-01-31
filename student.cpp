#include "student.h"
#include <string.h>

int Student::getid() {
  return id;
}

float Student::getgpa() {
  return gpa;
}

char *Student::getname() {
  return name;
}

void Student::setValue(int newid, float newgpa, char *newname) {
  id = newid;
  gpa = newgpa;
  strcpy(name, newname);
}

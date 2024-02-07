#include <iostream>
#include <iomanip>

#define	STUDENT_ID_MIN	100000
#define	STUDENT_ID_MAX	999999

#define NAME_LEN_MIN	 5
#define NAME_LEN_MAX	10

static int *id = NULL;

using namespace std;

//random number generator
static int genrandom(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

//generate a new id
static int getid(void) {
  int newid;
  do {
    newid = genrandom(STUDENT_ID_MIN, STUDENT_ID_MAX);
  } while (id[newid] != 0);
  id[newid] = 1;
  return newid;
}

//generate a new gpa
static float getgpa(void) {
  //generate value from 0 to 400
  return (float)genrandom(0, 400) / 100.;
}

static char firstname[NAME_LEN_MAX + 1];
static char lastname [NAME_LEN_MAX + 1];

//generate a new name
static void genname(char *name) {
  int namelen, i;
  namelen = genrandom(NAME_LEN_MIN, NAME_LEN_MAX);

  // Fist letter is capital
  *name = 'A' + genrandom(0, 25);
  name ++;
  // generate the lowe cases
  for (i = 1; i < namelen; i ++) {
    *name = 'a' + genrandom(0, 25);
    name ++;
  }
  *name = '\0';
}

int main(int argc, char **argv) {
  //argc is the number of inputs
  //argv is the actual inputs
  
  int numstudent = 10;
  int i;

  //if there is more than one value, take the integer value
  if (argc > 1) numstudent = atoi(argv[1]);

  //allocaiting array for keeping student id
  id = (int *)malloc((STUDENT_ID_MAX + 1) * sizeof(int));
  if (id == (int *)NULL) exit(1);

  for (i = 0; i < STUDENT_ID_MAX + 1; i ++) id[i] = 0;

  //add, print, quit
  for (i = 0; i < numstudent; i ++) {
    cout << "add" << endl;
    genname(firstname);
    genname(lastname);
    cout << firstname << " " << lastname << endl;
    cout << getid() << endl;
    cout << fixed << setprecision(2) << getgpa() << endl;
  }
  
  cout << "print" << endl;
  cout << "quit"<< endl;
  
  free(id);

  return 0;
}

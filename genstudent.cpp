#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define	STUDENT_ID_MIN	100000
#define	STUDENT_ID_MAX	999999

#define NAME_LEN_MIN	 5
#define NAME_LEN_MAX	10

static int *id = NULL;

static int genrandom(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

static int getid(void) {
  int newid;
  do {
    newid = genrandom(STUDENT_ID_MIN, STUDENT_ID_MAX);
  } while (id[newid] != 0);
  id[newid] = 1;
  return newid;
}

static float getgpa(void) {
  // generate value : 0 to 400
  return (float)genrandom(0, 400) / 100.;
}

static char firstname[NAME_LEN_MAX + 1];
static char lastname [NAME_LEN_MAX + 1];

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
  int numstudent = 10;
  int i;

  if (argc > 1) numstudent = atoi(argv[1]);

  id = (int *)malloc((STUDENT_ID_MAX + 1) * sizeof(int));
  if (id == (int *)NULL) exit(1);

  for (i = 0; i < STUDENT_ID_MAX + 1; i ++) id[i] = 0;

  for (i = 0; i < numstudent; i ++) {
    cout << "add" << endl;
    genname(firstname);
    genname(lastname);
    cout << firstname << " " << lastname << endl;
    cout << getid();
    cout << getgpa();
  }
  
  cout << "print\n" << endl;
  cout << "quit"<< endl;
  
  free(id);

  return 0;
}

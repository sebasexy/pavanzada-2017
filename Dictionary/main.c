#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dict.h"

/* Add function signatures here */

typedef struct a{
  char *name;
  int semestre;
}Student;

int main(int argc, char **argv) {
  /* Start your code here */
  Dict *students;
  Student st;
  Student *newStudent;

  //char *matricula = argv[1];
  char matricula[100];
  int errorCode;

  st.name = strdup("Angel Perez");
  st.semestre = 5;

  students = initDictionary(100, &errorCode);
  upsertDictionary(students, "0101", (void *)&st, sizeof(Student), &errorCode);

  st.name = "Jesus Lopez";
  st.semestre = 7;
  upsertDictionary(students, "0202", (void *)&st, sizeof(Student), &errorCode);

  printf("What is the id:");
  scanf("%s", matricula);

  newStudent = (Student *)getDictionary(students, matricula, sizeof(Student), &errorCode);
  if(newStudent == NULL){
    printf("No se encuentra, compa\n");
  }else{
    printf("Name: %s, semestre: %d\n", newStudent->name, newStudent->semestre);
  }
  return 0;
}

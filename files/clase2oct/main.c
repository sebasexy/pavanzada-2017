#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "qsort.h"
#define MAX_LENGTH_ORDER 20
#define STUDENT_LENGTH 3

typedef struct s{
  char *name;
  int matricula;
} Student;


int cmpStudent(const void *name1, const void *name2, int attribute){
  Student *student1 = (Student *) name1;
  Student *student2 = (Student *) name2;

  switch(attribute){
    case 0: //name
      return strcmp(student1->name, student2->name);
    case 1: // matricula
      return student1->matricula - student2->matricula;
  }
}

int cmpNames(const void *name1, const void *name2){
  return cmpStudent(name1, name2, 0);
}

int cmpMatriculas(const void *name1, const void *name2){
  return cmpStudent(name1, name2, 1);
}

/* Add function signatures here */

int main(int argc, char **argv) {
  /* Start your code here */
  Student group[STUDENT_LENGTH];
  char order[MAX_LENGTH_ORDER];
  Student key;
  Student *foundStudent;
  int i;
  int neededStudent;

  group[0].name = strdup("juanito");
  group[0].matricula = 17;

  group[1].name = strdup("pedrito");
  group[1].matricula = 30;

  group[2].name = strdup("arturo");
  group[2].matricula = 11;

  printf("Give me the order: ");
  scanf("%s", order);
  if(!strcmp(order, "name")){
    qsort(group, STUDENT_LENGTH, sizeof(Student), cmpNames);
  }

  if(strcmp(order, "matricula")){
    qsort(group, STUDENT_LENGTH, sizeof(Student), cmpMatriculas);
  }

  for(i = 0; i < STUDENT_LENGTH; i++){
    printf("Student %s %d\n", group[i].name, group[i].matricula);
  }

  printf("Which  is the id?: ");
  scanf("%d", &neededStudent);
  key.matricula = neededStudent;

  foundStudent = bsearch(&key, group, STUDENT_LENGTH, sizeof(Student), cmpMatriculas);
  if(foundStudent != NULL){
    printf("Student %s %d \n", foundStudent->name, foundStudent->matricula);
  }else{
    printf("Student not found with id %d\n", neededStudent);
  }

  return 0;
}

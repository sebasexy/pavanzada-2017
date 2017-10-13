#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "qsort.h"

typedef struct s{
  char *name;
  int matricula;
} Student;

int cmpNames(const void *name1, const void *name2){
  Student *student1 = (Student *) name1;
  Student *student2 = (Student *) name2;

  return strcmp(student1->name, student2->name);
}

int cmpMatriculas(const void *name1, const void *name2){
  Student *student1 = (Student *) name1;
  Student *student2 = (Student *) name2;

  return student1->matricula - student2->matricula;
}

/* Add function signatures here */

int main(int argc, char **argv) {
  /* Start your code here */
  Student group[3];
  char order[20];
  int i;
  group[0].name = strdup("juanito");
  group[0].matricula = 17;

  group[1].name = strdup("pedrito");
  group[1].matricula = 30;

  group[2].name = strdup("arturo");
  group[2].matricula = 11;

  printf("Give me the order: ");
  scanf("%s", order);
  if(!strcmp(order, "name")){
    qsort(group, 3, sizeof(Student), cmpNames);
  }

  if(strcmp(order, "matricula")){
    qsort(group, 3, sizeof(Student), cmpMatriculas);
  }

  for(i = 0; i < 3; i++){
    printf("Student %s %d\n", group[i].name, group[i].matricula);
  }
  return 0;
}

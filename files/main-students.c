#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct s{
  char name[100];
  int id;
} Student;

int main(int argc, char **argv){
  assert(argc == 3);
  FILE *myFile;
  myFile = fopen(argv[1], "rb");
  assert(myFile != NULL);

  Student myStudent;
  int record = atoi(argv[2]);
  long offset = sizeof(Student) * record;
  fseek(myFile, offset, SEEK_SET);
  fread(&myStudent, sizeof(Student),1,myFile);
  fclose(myFile);
  printf("Student at %d i: name %s, id %d \n", record, myStudent.name, myStudent.id);
  return 0;
}

/*
int main(int argc, char **argv){
  Student pAvanzada[10];

  strcpy(pAvanzada[0].name, "Juan");
  pavanzada[0].id = 45;

  strcpy(pAvanzada[1].name, "Francisco");
  pavanzada[1].id = 10;

  strcpy(pAvanzada[2].name, "Alan");
  pavanzada[2].id = 25;

  strcpy(pAvanzada[3].name, "Eduardo");
  pavanzada[3].id = 30;

  assert(argc == 2);
  FILE *myFile;
  myFile = fopen(argv[1], "wb");
  assert(myFile != NULL);


  fwrite(pAvanzada, sizeof(Student), 10, myFile);)
  fclose(myFile);
}
*/

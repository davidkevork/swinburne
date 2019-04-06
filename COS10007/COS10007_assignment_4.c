#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
  char name[30];
  int id;
  float mark;
};

typedef struct student *StudentPtr;

void welcomeMessage()
{
  printf("(1) Display students' details\n");
  printf("(2) Calculate average of all students' marks\n");
  printf("(3) Add new student to the record\n");
  printf("(4) Quit program\n");
}

void leaveMessage()
{
  printf("We hope you enjoyed this app\n");
  printf("If you enjoyed this app then give us a star of github\n");
  printf("We sell github stars to make a living\n");
  printf("If you didnt like this app\n");
  printf("Then get out of here and never show us your face again\n");
}

void readFile(struct student (*studentArray)[], unsigned int *size)
{
  FILE *myFile;
  myFile = fopen("grades.txt", "r");

  char buffer[100];
  int i = 0;
  if (myFile == NULL)
  {
    perror("grades.txt not found");
  }

  while (fgets(buffer, sizeof(buffer), myFile) != NULL && i < 100)
  {
    buffer[strlen(buffer) - 1] = '\0';
    sscanf(buffer, "%s %i %f", (*studentArray)[i].name, &(*studentArray)[i].id, &(*studentArray)[i].mark);
    ++i;
  }
  *size = i;
  fclose(myFile);
}

void printDetails(struct student (*studentArray)[], unsigned int size)
{
  for (size_t i = 0; i < size; ++i)
  {
    printf("name: %s, id: %i, mark: %.2f\n", (*studentArray)[i].name, (*studentArray)[i].id, (*studentArray)[i].mark);
  }
}

double average(struct student (*studentArray)[], unsigned int size)
{
  double average = 0;
  for (size_t i = 0; i < size; ++i)
  {
    average += (*studentArray)[i].mark;
  }
  return (double)average / size;
}

void addRecord(struct student (*studentArray)[], unsigned int *size)
{
  if (*size + 1 > 100) {
    printf("You exceeded your limit. Only 100 studen records can be processed.\n");
  } else {
    printf("Enter student name: ");
    scanf("%29s", (*studentArray)[*size].name);
    printf("Enter student id: ");
    scanf("%i", &(*studentArray)[*size].id);
    printf("Enter student mark: ");
    scanf("%f", &(*studentArray)[*size].mark);

    FILE *myFile;
    myFile = fopen("grades.txt", "a+");
    char buffer[100];
    char id[10];
    char mark[10];
    sprintf(id, "%i", (*studentArray)[*size].id);
    sprintf(mark, "%.2f", (*studentArray)[*size].mark);

    fputs((*studentArray)[*size].name, myFile);
    fputs(" ", myFile);
    fputs(id, myFile);
    fputs(" ", myFile);
    fputs(mark, myFile);
    fputs("\n", myFile);

    fclose(myFile);
    ++(*size);
  }
}

unsigned int getOption()
{
  unsigned int option = 0;
  printf("Enter the option number that you would like: ");
  scanf("%u", &option);
  return option;
}

int main(int argc, char const *argv[])
{
  struct student studentArray[100];
  unsigned int size = 0;
  unsigned int option = 0;

  welcomeMessage();
  readFile(&studentArray, &size);

  while (option != 4)
  {
    option = getOption();
    switch (option)
    {
    case 1:
      printDetails(&studentArray, size);
      break;
    case 2:
      printf("Average scrore: %.2f\n", average(&studentArray, size));
      break;
    case 3:
      addRecord(&studentArray, &size);
      break;
    case 4:
      leaveMessage();
      break;

    default:
      break;
    }
  }

  return 0;
}

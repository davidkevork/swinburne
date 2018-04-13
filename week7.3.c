#include <stdio.h>

struct student {
  char name[20];
  int roll;
  float marks;
};

int main () {

  int i;
  struct student s[5];

  for(i = 0; i < 5; i++) {
    printf("Enter name of the student %d\n",i+1);
    scanf("%s", &s[i].name);

    printf("Enter Roll number of  student %d\n",i+1);
    scanf("%d", &s[i].roll);

    printf("Enter Marks of student  %d\n",i+1);
    scanf("%f", &s[i].marks);
  }
  
  printf("******** Details of Students ********\n");

  for (i = 0; i < 5; i++) {
    printf("Name = %s, Roll = %d, Marks = %0.2f \n", s[i].name, s[i].roll, s[i].marks);
  }

  return  0;
}

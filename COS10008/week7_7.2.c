#include <stdio.h>

struct student {
  char name[20];
  int roll;
  float marks;
};

int main() {
  struct student s;
  printf("Enter Student's Name \n");
  scanf("%s", &s.name);
  printf("Enter Roll Number \n");
  scanf("%d", &s.roll);
  printf("Enter Marks \n");
  scanf("%f", &s.marks);

  printf("****** The student's details *******\n");
  printf("Name = %s \nRoll = %d \nMarks = %.2f", s.name, s.roll, s.marks);
}

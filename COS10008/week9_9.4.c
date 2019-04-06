#include <stdio.h>

int main(){
  int g[]={2,4,5,8,10,32,78};
  int *ptr1 = &g[0], *ptr2 = &g[3];

  printf("%d\n", *g);
  printf("%d\n", *(g+1));
  printf("%d\n", *g+1);
  printf("%d\n", *(g+5));
  printf("%d\n", *ptr1);
  printf("%d\n", *ptr2);
  printf("%d\n", *(ptr1+1));
  printf("%d\n", *(ptr2+2));
}

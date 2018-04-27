#include <stdio.h>

int main(){
  int x[2][4] = {
    {1,8,7,6},
    {2,4,-1,0}
  };
  int *xptr=&x[0][0];

  printf("%d\n", *xptr);
  printf("%d\n", *(xptr+2));
  printf("%d\n", *xptr + 2);
  printf("%d\n", *(xptr+1) + *(xptr+3));
}

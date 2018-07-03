#include <stdio.h>

int main(void) {
    int q[10];
    int m = 10;
    int a[8] = {1,2,3,4,5,6,7,8};
    //int i = 20;
    for(int i = 0; i <= 4; ++i)
    {
        q[i] = m + i;
        printf("1: q[i]=%d m=%d i=%d\n", q[i], m, i);
    }
    for(int i = 0; i <= 4; ++i)
    {
        *(a + i) = &q[i] + a[i];
        printf("1: q[i]=%d *(a+i)=%d i=%d\n", q[i], *(a+i), i);
    }

    return 0;
}

#include <stdio.h>
#include <math.h>

int main()
{
    unsigned m;
    unsigned n = 0;
    do {
        printf("Enter a positive integer less than 30: ");
        scanf("%u", &m);
        m > 30 ? printf("YOU KNOW IT IS WRONG. ENTER A VALID DATA\n") : (n = 1);
    } while (n == 0);

    printf("m=%u\n", m);

    float x[30];
    float d[30];
    float mean = 0;
    float s = 0;

    for (int i = 0; i < m; ++i) {
        x[i] = i+1;
        mean += x[i];
        printf("x[%i] = %f\n", i, x[i]);
    }

    mean /= m;
    printf("\nmean = %f\n\n", mean);

    for (int j = 0; j < m; ++j) {
        d[j] = x[j] - mean;
        s += d[j] * d[j];
        printf("Deviation [x=%f] = %f\n", x[j], d[j]);
    }

    s = sqrt(s / (m - 1));

    printf("\nStandard Deviation = %f\n", s);
    return 0;
}

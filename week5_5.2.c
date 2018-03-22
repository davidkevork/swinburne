#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
	int max_0 = 0;
	int max_1 = 0;
	printf("Please input 10 numbers\n");
	for (int i = 0; i < 10; ++i)
	{
		printf("Number %i:", i+1);
		int input = 0;
		scanf("%d", &input);
		if (input > max_0) {
			max_1 = max_0;
			max_0 = input;
		}
		if (input > max_1 && input < max_0) {
			max_1 = input;
		}
	}
	printf("max_0=%d, max_1=%d\n",max_0, max_1);
	return 0;
}

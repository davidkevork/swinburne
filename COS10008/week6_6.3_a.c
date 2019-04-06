#include <stdio.h>

float total_array(int array[], int array_size) {
	int sum = 0;
	for (int i = 0; i < array_size; i++)
	{
		sum += array[i];
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int array[10] = {5, 8, 11, 13, 15, 16, 23, 38, 45, 48};
	printf("%f\n", total_array(array, 10));
	return 0;
}

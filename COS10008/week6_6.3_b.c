#include <stdio.h>

int negative_count(int array[], int array_size) {
	int count = 0;
	for (int i = 0; i < array_size; i++)
	{
		if (array[i] < 0) {
			count++;
		}
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int array[10] = {5, -8, 11, -13, 15, 16, -23, 38, 45, -48};
	printf("%d\n", negative_count(array, 10));
	return 0;
}

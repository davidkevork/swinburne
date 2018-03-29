#include <stdio.h>
#include <stdbool.h>

bool check_total(int array[], int array_size) {
	int sum = 0;
	for (int i = 0; i < array_size; i++)
	{
		sum += array[i];
	}
	if (sum >= 100) {
		return true;
	} else {
		return false;
	}
}

int main(int argc, char const *argv[])
{
	int array[10] = {5, 8, 11, 13, 15, 16, 23, 38, 45, 48};
	printf("%i\n", check_total(array, 10));
	return 0;
}

#include <stdio.h>
#include <stdbool.h>

int total_array(int array[], int array_size) {
	int sum = 0;
	for (int i = 0; i < array_size; i++)
	{
		sum += array[i];
	}
	return sum;
}

bool check_total(int total) {
	if (total >= 100) {
		return true;
	} else {
		return false;
	}
}

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
	int array[10];
	printf("Enter values in array:\n");
	for (int i = 0; i < 10; ++i)
	{
		scanf("%d", &array[i]);
	}
	int total = total_array(array, 10);
	printf("total=%d\n", total);

	int i = 0;
	if (check_total(total)) {
		while (i < 10) {
			printf("Sum is greater than 100\n");
			i++;
		}
	} else {
		printf("Sum is less than 100\n");
	}
	int neg = negative_count(array, 10);
	printf("neg=%d\n", neg);
	return 0;
}

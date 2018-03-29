#include <stdio.h>
#include <stdbool.h>

bool check_total(int total) {
	if (total >= 100) {
		return true;
	} else {
		return false;
	}
}

int main(int argc, char const *argv[])
{
	int array[10] = {5, 8, 11, 13, 15, 16, 23, 38, 45, 48};
	printf("%i\n", check_total(222, 10));
	return 0;
}

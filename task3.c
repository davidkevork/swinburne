#include <stdio.h>

void program1();
void program2();
void program3();

int main() {
	program1();
	program2();
	program3();
	return 0;
}

void program1() {
	int a, b, c;
	a = 10;
	b = 20;
	c = a + b;
	printf("c = %d\n", c);
}

void program2() {
	int num1, num_2;
	num1 = 1;
	num_2 = 2;
	printf("%d %d\n", num1, num_2-1);
}

void program3() {
	int var_1, var_2, var_3, var_4, var_5;
	var_1 = 100;
	var_2 = 200;
	var_3 = var_2 + var_1;
	var_4 = 300;
	var_5 = var_2 + var_4;
	var_4 = var_5;
	var_2 = var_3;
	printf("%d \n%d", var_1,var_2);
	printf("%d %d\n", var_3,var_4);
	printf("%d", var_5);
}
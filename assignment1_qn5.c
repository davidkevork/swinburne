#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_int(int a, int b)
{
	return rand()%(b-a+1)+a;
}

void correct_question() {
	switch(rand_int(0,3)) {
		case 0:
			printf("Very good!\n");
			break;
		case 1:
			printf("Excellent!\n");
			break;
		case 2:
			printf("Nice work!\n");
			break;
		case 3:
			printf("Keep up the good work!\n");
			break;
	}
}

void wrong_question() {
	switch(rand_int(0,3)) {
		case 0:
			printf("No. Please try again.\n");
			break;
		case 1:
			printf("Wrong. Try once more.\n");
			break;
		case 2:
			printf("Don't give up!\n");
			break;
		case 3:
			printf("No. Keep trying\n");
			break;
	}
}

int generate_question() {
	int num1 = rand_int(0,9);
	int num2 = rand_int(0,9);
	int answer;
	printf("How much is %d + %d = ", num1, num2);
	scanf("%d", &answer);
	if (answer == num1 + num2) {
		correct_question();
		return 1;
	} else {
		wrong_question();
		return 0;
	}
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int correct = 0;
	while (correct != 2) {
		if (generate_question()) {
			correct++;
		} else {
			generate_question();
		}
	}
	return 0;
}

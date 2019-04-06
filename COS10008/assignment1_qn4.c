#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
	int num[3];
	int newNum[3];
	int point = 0;
	int sum = 0;
	int player = 0;
	/**
	 * 0 is start
	 * 1 is win
	 * 2 is lose
	 * 3 is win when it "make your point."
	 */
	srand(time(NULL));
	for (int i = 0; i < 3; i++)
	{
		num[i] = rand()%(6-1+1)+1;
		point += num[i];
	}
	printf("Player rolled %d + %d + %d = %d \n", num[0], num[1], num[2], point);
	if (point >= 13) {
		printf("Player wins\n");
		player = 1;
	} else if (point <= 6) {
		printf("Player loses\n");
		player = 2;
	}
	if (player != 2) {
		do {
			sum = 0;
			for (int i = 0; i < 3; i++)
			{
				newNum[i] = rand()%(6-1+1)+1;
				sum += newNum[i];
			}
			printf("Player rolled %d + %d + %d = %d \n", newNum[0], newNum[1], newNum[2], sum);
			if (sum == point) {
				printf("Player wins\n");
				player = 3;
			} else if (sum <= 6) {
				printf("Player loses\n");
				player = 2;
			} else if (sum >= 13) {
				player = 1;
			}
		} while (player == 1);
	}
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_int(int a, int b)
{
	srand(time(NULL));
	return rand()%(b-a+1)+a;
}

int main(int argc, char const *argv[])
{
	int sum = 0;
	for (int i = 0; i < 5; ++i)
	{
		sum += rand_int(1, 6);
	}
	if (sum > 15) {
		printf("You win! num=%d\n",sum);
	} else {
		printf("You lose! num=%d\n",sum);
	}
	
	return 0;
}
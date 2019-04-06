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
	int num = rand_int(1, 6);
	if (num == 0 || num % 2 == 0) {
		printf("You win! num=%d\n",num);
	} else {
		printf("You lose! num=%d\n",num);
	}
	
	return 0;
}
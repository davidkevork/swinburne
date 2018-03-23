#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// usage: n(number, 2)
int n(char* a, int b) {
	return a[b] - '0';
}

// https://stackoverflow.com/a/4003287
int mod (int a, int b)
{
   if(b < 0)
     return mod(a, -b);   
   int ret = a % b;
   if(ret < 0)
     ret+=b;
   return ret;
}

int r(int x) {
	return mod((x+7), 10);
}

int s(int x) {
	return mod((x-7), 10);
}


void encrypt(char* x, char* m) {
	m[0] = r(n(x,0)) + '0';
	m[1] = r(n(x,1)) + '0';
	m[2] = r(n(x,2)) + '0';
	m[3] = r(n(x,3)) + '0';

	int two = n(m,1);
	m[1] = n(m, 3)+'0';
	m[3] = two+'0';

	int zero = n(m,0);
	m[0] = n(m, 2)+'0';
	m[2] = zero+'0';
}

void decrypt(char* x, char* m) {
	m[0] = s(n(x,2))+'0';
	m[1] = s(n(x,3))+'0';
	m[2] = s(n(x,0))+'0';
	m[3] = s(n(x,1))+'0';
}

int main() {
	char digit[5];
	printf("Please input the number:");
	scanf("%4[0-9]", &digit);
	printf("digit=%s\n", digit);
	
	char encrypted[5];
	encrypt(digit, encrypted);
	printf("encrypt=%c%c%c%c\n", encrypted[0], encrypted[1], encrypted[2], encrypted[3]);

	char decrypted[5];
	decrypt(encrypted, decrypted);
	printf("decrypt=%c%c%c%c\n", decrypted[0], decrypted[1], decrypted[2], decrypted[3]);
	
	return 0;
}

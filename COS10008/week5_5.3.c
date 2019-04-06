#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// usage: n(number, 2)
int n(char* a, int b) {
	return a[b] - '0';
}

// https://stackoverflow.com/a/4003287
int mod(int a, int b)
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


void e(char* x, char* m) {
	m[0] = r(n(x,0)) + '0';
	m[1] = r(n(x,1)) + '0';
	m[2] = r(n(x,2)) + '0';
	m[3] = r(n(x,3)) + '0';

	int a = n(m,1);
	m[1] = n(m, 3)+'0';
	m[3] = a+'0';

	int b = n(m,0);
	m[0] = n(m, 2)+'0';
	m[2] = b+'0';
}

void d(char* x, char* m) {
	m[0] = s(n(x,2))+'0';
	m[1] = s(n(x,3))+'0';
	m[2] = s(n(x,0))+'0';
	m[3] = s(n(x,1))+'0';
}

int main() {
	char dn[5];
	printf("Please input the number:");
	scanf("%4[0-9]", &dn);
	printf("digit=%s\n", dn);
	
	char e[5];
	e(dn, e);
	printf("encrypt=%c%c%c%c\n", e[0], e[1], e[2], e[3]);

	char d[5];
	d(e, d);
	printf("decrypt=%c%c%c%c\n", d[0], d[1], d[2], d[3]);
	
	return 0;
}

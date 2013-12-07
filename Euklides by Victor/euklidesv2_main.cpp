#include <cstdio>
#include "euklidesv2.h"

int main()
{
	int a,b;

	scanf("%d", &a);
	scanf("%d", &b);

	printf("gcd(%d, %d) = %d\n", a, b, euklides(a, b));

	return 0;
}



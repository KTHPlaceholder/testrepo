#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

int main()
{
	int a,b,p,q;
	div_t divres;
	scanf("%d", &a);
	scanf("%d", &b);
	p = a;
	q = b;
	divres = div(a, b);
	while(divres.rem != 0)
	{
		p = q;
		q = divres.rem;
		divres = div(p,  q);
	}
	printf("gcd(%d, %d) = %d\n", a, b, q);

	return 0;
}

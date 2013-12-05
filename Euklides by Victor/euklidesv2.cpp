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
	printf("%d = %d * %d + %d\n", a, b, divres.quot, divres.rem);
	while(divres.rem != 0)
	{
		p = divres.quot;
		q = divres.rem;
		divres = div(p,  q);
		printf("%d = %d * %d + %d\n", p , q, divres.quot, divres.rem);
	}
	printf("gcd(%d, %d) = %d", a, b, divres.quot);

	return 0;
}
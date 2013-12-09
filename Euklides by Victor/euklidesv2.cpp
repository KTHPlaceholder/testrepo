#include <cstdio>
#include <cstdlib>

#include "euklidesv2.h"

using namespace std;

int euklides(int a, int b) {
	int p = a;
	int q = b;
	div_t divres = div(a, b);
	printf("%d = %d * %d + %d\n", a, b, divres.quot, divres.rem);
	while(divres.rem != 0)
	{	
		p = q;
		q = divres.rem;
		divres = div(p,  q);
		printf("%d = %d * %d + %d\n", p , q, divres.quot, divres.rem);
	}
	
	return q;
}

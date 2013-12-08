#include <iostream>
using namespace std;

/*
Listing natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6, 9.
The sum of these multiples is 23.

This function finds the sum of all multiples of (int mult_1) or (int mult_2) below (int limit).
*/
int sum_of_multiples(int mult_1, int mult_2, int limit) {
	int sum = 0;
	for (int i = 0; i < limit; i++) {	

		if(i % mult_1 == 0 || i % mult_2 == 0) {
			sum += i;			
		}
		
	}	
	return sum;	
} 

int main() {
	int mult_1, mult_2, limit;

	scanf("%d",&mult_1);
	scanf("%d",&mult_2);
	scanf("%d",&limit);	

	int sum = sum_of_multiples(mult_1,mult_2, limit);
	printf("Answer: %d \n", sum);

	return 0;
}


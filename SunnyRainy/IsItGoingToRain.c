/**
 * A very naive and simple implementation of a very simple Markov state change based on 
 * https://en.wikipedia.org/wiki/Examples_of_Markov_chains#A_very_simple_weather_model
 *
 * Arguments: 
 *   * First argument: Whether it rained today (1) or not (0)
 *   * Second argument: How many days from today you want to know whether it is going to rain or not
 * 
 * Ís it going to rain tomorrow [if it rained today]?
 * 	./IsItGoingToRain 1 1
 * 	Output:
 * 		yes
 *
 * Ís it going to rain in a week [if it rained today]?
 *	 ./IsItGoingToRain 1 7
 *	 Output:
 *	 	no
 *
 * Written by: Linus Kendall
 * Reviewed by: 
 */ 

#include <stdio.h> /* PRINTF */
#include <stdlib.h> /* ATOL */

double markov[2][2];

double IsItGoingToRainOn(int today, int noInvocations);

int main(int argc, char *argv[]) {
	// Check arguments
	if(argc < 2) {
		perror("Too few arguments, please give a bit pattern as the second argument");
		return -1;
	}		

	/* Set up the inputs */
	int today = atol(argv[1]);
	int noInvoications = atol(argv[2]);

	/* Set up the Markov model */
	// Transition from sunny
	markov[0][0] = 0.9; // to sunny
	markov[0][1] = 0.5; // to rain

	// Transition from rain
	markov[1][0] = 0.1; // to sunny
	markov[1][1] = 0.5; // to rain
	
	/* */ 
	double rainProb = IsItGoingToRainOn(today, noInvoications);
	if(rainProb > 0.5) {
		printf("Yes (probability of rain = %f)\n", rainProb);
	} else {
		printf("No (probability of rain = %f)\n", rainProb);
	}	
	

	return 0;
}

/* Function to calculate the likelihood for rain in <noInvoications> days.
 * 
 * Arguments:
 * - today - whether it rained today or not
 * - noInvocations - for which day you would want to calculate it for
 * 
 * With sufficient number of invoications this will always return the result 0.167777
 * ie. regardless of what the whether is today it will always be sunny in the long run with 83% probability!
 */
double IsItGoingToRainOn(int today, int noInvocations) {
	int i;
	double rainMatrix[2];

	/* Initialize the rainMatrix depending on whether it rained today or not */
	rainMatrix[0] = 1.0 - today;
	rainMatrix[1] = (double)today;

	/* Run the markov model */
	for(i = 0; i < noInvocations; i++) {
		/* Very simple matrix multiplication */
		double sun = rainMatrix[0]*markov[0][0]+rainMatrix[1]*markov[0][1];	
		double rain = rainMatrix[0]*markov[1][0]+rainMatrix[1]*markov[1][1];	

		rainMatrix[0] = sun;
		rainMatrix[1] = rain;
	}	

	/* Return the probability for being in state 1, rain */
	return rainMatrix[1];
}

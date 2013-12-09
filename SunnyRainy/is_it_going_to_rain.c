/**
 * A very naive and simple implementation of a very simple Markov state change based on 
 * https://en.wikipedia.org/wiki/Examples_of_Markov_chains#A_very_simple_weather_model
 *
 * Arguments: 
 *   * First argument: Whether it rained today (1) or not (0)
 *   * Second argument: How many days from today you want to know whether it is going to rain or not (1 = tomorrrow)
 *   * Third argument: Bit pattern corresponding to a training set showing state changes 0 = sunny, 1 = rain 
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
 * Is it going to rain in a week given a specific training set?
 * 	 ./IsItGoingToRain 1 7 1010101010
 *	 Output:
 *		no
 * 
 * Written by: Linus Kendall
 * Reviewed by: 
 */ 

#include <stdio.h> /* PRINTF */
#include <stdlib.h> /* ATOL */
#include <string.h> /* STRLEN */

#include "is_it_going_to_rain.h"

/* Train a markov model using a supplied input bit string representing state transitions.
 *
 * Input: weatherHistory, a bit string 011101100 where 1s mean that it was raining that day.
 * Return value: Number of successful state transitions recorded
 * Global side effects.
 */
int train(const char* weatherHistory) {
	int i = 0;

	markov[0][0] = markov[0][1] = markov[1][0] = markov[1][1] = 0.0;

	// Default value if the weather history provided only contains one element	
	if(strlen(weatherHistory) > 1) {
		// Iterate through the entire weather history provided 
		for(i = 0; i < (strlen(weatherHistory)-1); i++) {
			int srcState = (weatherHistory[i] == '1' ? 1 : 0 );			
			int dstState = (weatherHistory[i+1] == '1' ? 1 : 0 );		

			markov[srcState][dstState]++;
		} 

		// Total values transition to sunny 
		double total_from_sunny = markov[0][0]+markov[0][1];
		double total_from_rain  = markov[1][0]+markov[1][1];
		
		// Transition from sunny
		if(total_from_sunny != 0) {
			markov[0][0] = markov[0][0] / total_from_sunny; // from sunny to sunny
			markov[0][1] = markov[0][1] / total_from_sunny; // from sunny to rain
		}
		
		// Transition from rain 
		if(total_from_rain != 0) {
			markov[1][0] = markov[1][0] / total_from_rain; // from rain to sunny
			markov[1][1] = markov[1][1] / total_from_rain; // from rain to rain
		}
	}

	return i;
}

/* Calculate the likelihood for rain in <noInvoications> days. 
 * The markov model will always reach a steady state after a sufficient amount of invoications.
 * 
 * Arguments:
 * - today - whether it rained today or not
 * - noInvocations - for which day you would want to calculate it for
 */
double predict(const int today, const int noInvocations) {
	int i;
	double rainMatrix[2];

	// Initialize the rainMatrix depending on whether it rained today or not 
	rainMatrix[0] = 1.0 - today;
	rainMatrix[1] = (double)today;

	// Run the markov model  
	for(i = 0; i < noInvocations; i++) {
		// Very simple matrix multiplication multiplying a 1x2 matrix with a 2x2 matrix
		double sun = rainMatrix[0]*markov[0][0]+rainMatrix[1]*markov[0][1];	
		double rain = rainMatrix[0]*markov[1][0]+rainMatrix[1]*markov[1][1];	

		rainMatrix[0] = sun;
		rainMatrix[1] = rain;
	}	

	// Return the probability for being in state 1, rain at the end of the prediction 
	return rainMatrix[1];
}

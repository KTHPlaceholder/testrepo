#include <stdio.h> /* PRINTF */
#include <stdlib.h> /* ATOL */
#include <string.h> /* STRLEN */

#include "is_it_going_to_rain.h"


int main(int argc, char *argv[]) {
	// Check arguments
	if(argc < 3) {
		perror("Too few arguments. Usage: ./raintomorrow [today] [prediction day] [training set]");
		return -1;
	} if(argc >= 4 && strlen(argv[3]) < 2) {
		perror("If a training set is provided as the fourth argument you have to provide a training set with at least one element.");
		return -1;
	}		

	// TODO: no error checking on inputs, this will be OK though since atol return 0

	// Initialize input variables
	int today = atol(argv[1]);
	int noInvoications = atol(argv[2]);
	
	// If a training set is provided train the markov model, otherwise use default values 
	if(argc == 4) {
		int training = train(argv[3]);
		if(training == -1) { 
			perror("Training failed. Bailing.");
			return -1;
		}
	} else {	
		int training = train("");
		if(training == -1) { 
			perror("Training failed. Bailing.");
			return -1;
		}
	}

	double rainProb = predict(today, noInvoications);
	if(rainProb >= 0.5) {
		printf("Yes (probability of rain = %f)\n", rainProb);
	} else {
		printf("No (probability of rain = %f)\n", rainProb);
	}	
	

	return 0;
}

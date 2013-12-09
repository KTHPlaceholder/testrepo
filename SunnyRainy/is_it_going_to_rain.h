#ifndef IS_IT_GOING_TO_RAIN_H
#define IS_IT_GOING_TO_RAIN_H

extern double markov[2][2];

int train(const char* weatherHistory);
double predict(const int today, const int noInvocations);

#endif

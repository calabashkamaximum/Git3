#ifndef GUESSER_H
#define GUESSER_H

#include "bulls_cows.h"

const int MAX_CAND = 5040;


int buildCandidates(int cand[][LEN]);


void filterCandidates(int cand[][LEN], int &count, const int guess[], int bulls, int cows);

#endif

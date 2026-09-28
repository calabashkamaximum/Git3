#ifndef BULLS_COWS_H
#define BULLS_COWS_H

#include <string>

const int LEN = 4;

void generateSecret(int secret[]);

bool parseGuess(const std::string &s, int guess[]);


void countBullsCows(const int secret[], const int guess[], int &bulls, int &cows);


void printResult(int bulls, int cows);

#endif

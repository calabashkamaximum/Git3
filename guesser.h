#ifndef GUESSER_H
#define GUESSER_H

#include "bulls_cows.h"

const int MAX_CAND = 5040;   // 10*9*8*7 чисел из 4 различных цифр

// Заполнить список всех возможных чисел, вернуть их количество
int buildCandidates(int cand[][LEN]);

// Оставить только кандидатов, совместимых с ответом (bulls, cows) на предположение guess
void filterCandidates(int cand[][LEN], int &count, const int guess[], int bulls, int cows);

#endif

#include "guesser.h"

int buildCandidates(int cand[][LEN])
{
    int count = 0;
    for (int a = 0; a < 10; a++)
        for (int b = 0; b < 10; b++)
        {
            if (b == a) continue;
            for (int c = 0; c < 10; c++)
            {
                if (c == a || c == b) continue;
                for (int d = 0; d < 10; d++)
                {
                    if (d == a || d == b || d == c) continue;
                    cand[count][0] = a;
                    cand[count][1] = b;
                    cand[count][2] = c;
                    cand[count][3] = d;
                    count++;
                }
            }
        }
    return count;
}

void filterCandidates(int cand[][LEN], int &count, const int guess[], int bulls, int cows)
{
    int newCount = 0;
    for (int i = 0; i < count; i++)
    {
        int b, c;
        countBullsCows(cand[i], guess, b, c);
        if (b == bulls && c == cows)
        {
            for (int k = 0; k < LEN; k++)
                cand[newCount][k] = cand[i][k];
            newCount++;
        }
    }
    count = newCount;
}

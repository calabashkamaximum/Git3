#include <iostream>
#include <cstdlib>
#include "bulls_cows.h"

void generateSecret(int secret[])
{
    bool used[10] = {false};
    int n = 0;
    while (n < LEN)
    {
        int d = rand() % 10;
        if (!used[d])
        {
            used[d] = true;
            secret[n++] = d;
        }
    }
}

bool parseGuess(const std::string &s, int guess[])
{
    if (s.size() != LEN)
        return false;

    bool used[10] = {false};
    for (int i = 0; i < LEN; i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
        int d = s[i] - '0';
        if (used[d])
            return false;
        used[d] = true;
        guess[i] = d;
    }
    return true;
}

void countBullsCows(const int secret[], const int guess[], int &bulls, int &cows)
{
    bulls = 0;
    cows = 0;
    for (int i = 0; i < LEN; i++)
    {
        for (int j = 0; j < LEN; j++)
        {
            if (guess[i] == secret[j])
            {
                if (i == j)
                    bulls++;
                else
                    cows++;
            }
        }
    }
}

// Выбор правильной формы слова по числу
static const char *wordForm(int n, const char *one, const char *few, const char *many)
{
    if (n % 100 >= 11 && n % 100 <= 14)
        return many;
    if (n % 10 == 1)
        return one;
    if (n % 10 >= 2 && n % 10 <= 4)
        return few;
    return many;
}

void printResult(int bulls, int cows)
{
    std::cout << bulls << " " << wordForm(bulls, "бык", "быка", "быков") << ", "
              << cows << " " << wordForm(cows, "корова", "коровы", "коров") << std::endl;
}

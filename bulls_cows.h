#ifndef BULLS_COWS_H
#define BULLS_COWS_H

#include <string>

const int LEN = 4;   // длина загадываемого числа

// Загадать число из LEN различных цифр
void generateSecret(int secret[]);

// Проверить строку: LEN различных цифр. При успехе заполняет guess[]
bool parseGuess(const std::string &s, int guess[]);

// Подсчет быков и коров
void countBullsCows(const int secret[], const int guess[], int &bulls, int &cows);

// Вывод результата ("1 бык 1 корова")
void printResult(int bulls, int cows);

#endif

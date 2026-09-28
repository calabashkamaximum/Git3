#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "bulls_cows.h"
#include "guesser.h"
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;


void playUser()
{
    int secret[LEN], guess[LEN];
    int bulls = 0, cows = 0, tries = 0;

    generateSecret(secret);
    cout << "Компьютер загадал число из 4 различных цифр. Угадывайте!" << endl;

    time_t start = time(0);
    while (bulls != LEN)
    {
        string s;
        cout << "Ваш вариант: ";
        cin >> s;

        if (!parseGuess(s, guess))
        {
            cout << "Нужно ввести 4 различные цифры." << endl;
            continue;
        }

        tries++;
        countBullsCows(secret, guess, bulls, cows);
        printResult(bulls, cows);
    }
    cout << "Число угадано за " << tries << " попыток, "
         << (long)(time(0) - start) << " сек." << endl;
}


void playComputer()
{
    static int cand[MAX_CAND][LEN];
    int count = buildCandidates(cand);
    int bulls = 0, cows = 0, tries = 0;

    cout << "Загадайте число из 4 различных цифр. Я буду его угадывать." << endl;
    cout << "После каждого моего варианта вводите число быков и коров через пробел." << endl;

    while (bulls != LEN)
    {
        if (count == 0)
        {
            cout << "Вариантов не осталось: вы где-то ошиблись в подсказках." << endl;
            return;
        }

        int guess[LEN];
        for (int k = 0; k < LEN; k++)
            guess[k] = cand[0][k];

        tries++;
        cout << "Попытка " << tries << ": ";
        for (int k = 0; k < LEN; k++)
            cout << guess[k];
        cout << endl;

        cout << "Быков и коров: ";
        cin >> bulls >> cows;
        if (bulls < 0 || cows < 0 || bulls + cows > LEN)
        {
            cout << "Некорректный ввод." << endl;
            tries--;
            bulls = 0;
            continue;
        }

        if (bulls == LEN)
            break;
        filterCandidates(cand, count, guess, bulls, cows);
    }
    cout << "Угадал за " << tries << " попыток!" << endl;
}

int main()
{
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
    srand(static_cast<unsigned int>(time(0)));

    int choice = -1;
    while (choice != 0)
    {
        cout << endl << "=== Быки и коровы ===" << endl;
        cout << "1 - Я угадываю число" << endl;
        cout << "2 - Компьютер угадывает число" << endl;
        cout << "0 - Выход" << endl;
        cout << "Выбор: ";
        cin >> choice;

        if (choice == 1)
            playUser();
        else if (choice == 2)
            playComputer();
    }
    return 0;
}

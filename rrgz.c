#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>


// Здесь всякие функции, а это просто коммент просто так

void dectox_int(unsigned long long int number, unsigned long long int osn, char* s);
int Input(int* k);
int CheckSystem(int osnovanie);
int CheckPow(int osnovanie);
int CheckNumber(unsigned long long int number, int osnovanie);
void Aftomorph(int k, int n);


int main() {
    int k = 0, osnovanie = 0;
    setlocale(LC_ALL, "RU");
    printf("Введите количество = ");
    if (!Input(&k)) return -1;
    printf("Введите основание = ");
    if (!Input(&osnovanie)) return -1;
    if (osnovanie < 2)
    {
        printf("Ошибка: Неправильно заданное основание.\n");
        return -1;

    }
    if (!CheckPow(osnovanie)) {
        printf("Ошибка: основание не должно быть простым числом или его степенью.\n");
        return -1;
    }
    Aftomorph(k, osnovanie);
    return 0;
}

void dectox_int(unsigned long long int number, unsigned long long int osn, char* s)
{
    int len = 0;
    while (number) {
        int x = number % osn;
        s[len++] = (x < 10) ? '0' + x : 'A' + x - 10;
        number /= osn;
    }
    s[len] = '\0';
}
int CheckSystem(int osnovanie) {
    int flag = 1;
    for (int i = 2; i * i <= osnovanie && flag; i++)
    {
        flag = osnovanie % i == 0 ? 0 : 1;
    }
    return flag;
}

int CheckPow(int osnovanie) {
    int flag = 1;
    for (int i = 2; i <= osnovanie && flag; i++)
        if (osnovanie % i == 0) {
            int step = i;
            for (; step < osnovanie; step *= i) continue;
            if (step == osnovanie && CheckSystem(i)) flag = 0;
        }
    return flag;
}
int Input(int* num) {
    char c;
    while (scanf("%c", &c) && isdigit(c)) *num = *num * 10 + (c - 48);
    if (c == '-')
    {
        printf("Ошибка: Введите положительное значение\n");
        return 0;
    }
    else if (c != '\n')
    {
        printf("Ошибка: Некоректный ввод");
        return 0;
    }
    else return 1;

}

int CheckNumber(unsigned long long int number, int osnovanie) {
    char str_number[50], sqr_number[50];
    dectox_int(number, osnovanie, str_number);
    dectox_int(number * number, osnovanie, sqr_number);

    int flag = 1;
    for (int i = 0; i < strlen(str_number) && flag; i++)
        if (str_number[i] != sqr_number[i]) flag = 0;

    return flag;
}
void Aftomorph(int k, int n) 
{
    int count = 0;
    for (unsigned long long int i = 0; k != count; i++)
    {
        if (CheckNumber(i, n))
        {
            printf("%d %lld^2 = %lld\n", count + 1, i, i * i);
            count++;
        }
    }
}

/*
** EPITECH PROJECT, 2023
** CSFML_WORKSHOP
** File description:
** tools
*/

#include "my.h"
#include "struct.h"

int my_strlen(char const *str)
{
    int x = 0;
    while (*str != '\0' ) {
        x++;
        str++;
    }
    return x;
}

char *my_revstr(char *str)
{
    char suite;
    int y = 0;
    int v = my_strlen(str) - 1;
    while (v > y) {
        suite = str[y];
        str[y] = str[v];
        str[v] = suite;
        y = y + 1;
        v = v - 1;
    }
    return str;
}

int my_intlen(long long number, int div)
{
    int count = 0;
    for (number; number > 0; number = number / div) {
        count++;
    }
    return count;
};

char *my_intchar(long long num)
{
    int new = 0;
    int counter = 0;
    int neg = 1;
    num < 0 ? num = num * -1, neg++ : counter;
    char *list = malloc(sizeof(char) * (my_intlen(num, 10) + neg + 1));
    if (num <= 9) {
        list[counter] = num + '0';
        neg == 2 ? counter++, list[counter] = '-' : neg;
        list[counter + 1] = '\0';
    } else {
        for (counter; num > 0; counter++) {
            new = num % 10;
            num = num / 10;
            list[counter] = new + '0';
        }
        neg == 2 ? neg, list[counter] = '-', counter++ : neg;
        list[counter] = '\0';
    }
    return my_revstr(list);
}


int my_check(char *parse, int where, char *string)
{
    int c;
    for (c = 0; parse[c] != '\0'; c++, where++) {
        if (parse[c] != string[where])
            return -1;
    }
    return c;
}

int num_args(char *argv, char *parse, int t, int c)
{
    int num = 0;
    int lock;

    for (; argv[c] != '\0'; c++) {
        lock = my_check(parse, c, argv);
        lock != -1 ? t-- : t;
        if (t < 0 && lock != -1) {
            num++;
            c = lock + c - 1;
        }
    }
    return num;
}

int size_arg(char *argv, int where, char *parse, int t)
{
    int num = 0;
    int br = 0;
    int size = strlen(parse);
    for (; argv[where] != '\0'; where++, num++) {
        for (int c = 0; c < size && argv[where + c] != '\0'; c++) {
            argv[where + c] != parse[c] ? br = 0 : br++;
        }
        br >= size ? t-- : t;
        if (br >= size && t < 0)
            break;
    }
    return num;
}

char *add(char *string, int start, int max)
{
    int l = 0;
    char *temp = malloc(sizeof(char) * (max + 1));
    for (; l < max; start++, l++) {
        temp[l] = string[start];
    }
    temp[l] = '\0';
    return temp;
}

char **my_split(char *argv, char *parse, int t)
{
    int row = 0;
    char **buff = malloc((num_args(argv, parse, t, 0) + 3) * sizeof(*buff));
    for (size_t c = 0; c < strlen(argv); c++) {
        int lock = my_check(parse, c, argv);
        if (t <= 0 && lock != -1) {
            c = c + lock - 1;
        } else {
            int i = size_arg(argv, c, parse, t);
            buff[row] = add(argv, c, i);
            c = c + i - 1;
            row = row + 1;
            t = 0;
        }
    }
    buff[row] = NULL;
    return buff;
}
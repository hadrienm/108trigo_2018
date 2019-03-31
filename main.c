/*
** EPITECH PROJECT, 2019
** 108trigo
** File description:
** 108trigo
*/

#include "my.h"

int main(int ac, char **av)
{
    double pass = sqrt(ac  - 2);
    int pass2 = (int)(sqrt(ac - 2));
    /*double **res = menos((double *[2]){(double[2]){1, 2}, (double[2]){3, 4}}, (double *[2]){(double[2]){1, 2}, (double[2]){3, 4}}, ac);*/
    char tab[5][5] = {"COS", "EXP", "SIN", "COSH", "SINH"};
    int res = 0;
    if (ac == 2 && verify_h(av[1]) == 0)return 0;
    if (ac < 3)return 84;
    if (pass != (float)pass2)return 84;
    for (int i = 0; i != 5; ++i)if (comp(tab[i], av[1]) == 0)res++;
    if (res == 1);
    else return 84;
    for (int i = 2; i != ac; ++i)for (int j = 0; av[i][j] != '\0'; ++j)if (av[i][j] > 57 || av[i][j] < 45)return 84;
    determine(ac, av);
    return 0;
}

/*
** EPITECH PROJECT, 2019
** 108trigo
** File description:
** 108trigo
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double **mult(double **matrice, int nb, int ac)
{
    double **A = matrice;
    for (int i = 0; i != sqrt(ac - 2); ++i)
            for (int j = 0; j != sqrt(ac - 2); ++j)
                A[i][j] = 0;
    double resu = 1;
    int save, save2 = 0;
    for (int k = 0; k != nb; ++k)
        for (int i = 0; i != sqrt(ac - 2); ++i)
            for (int j = 0; j != sqrt(ac - 2); ++j) {
                for (int lol = 0, salut = j; lol != sqrt(ac - 2); lol++, salut++) {
                    resu *= matrice[i][lol];
                    resu *= matrice[j][salut];
                    A[i][j] += resu;
                    resu = 1;
                }
            }
    return A;
}

int comp(char *str, char *str2)
{
    if (strlen(str) != strlen(str2))return 1;
    for (int i = 0; str[i] != '\0'; i++)if (str[i] != str2[i])return 1;
    return 0;
}

void cos_(int ac, char **av)
{
    int i = 0, j = 0;
    int k = 2;
    double tab[sqrt(ac - 2)][ac - 1];
    for (; i != sqrt(ac - 2); i++)for (j = 0; j != sqrt(ac - 2); ++j, k++)tab[i][j] = atof(av[k]);
}

void exp_(int ac, char **av)
{
    int i = 0, j = 0;
    int k = 2;
    double tab[sqrt(ac - 2)][ac - 1];
    for (; i != sqrt(ac - 2); i++)for (j = 0; j != sqrt(ac - 2); ++j, k++)tab[i][j] = atof(av[k]);
}

void sin_(int ac, char **av)
{
    int i = 0, j = 0;
    int k = 2;
    double tab[sqrt(ac - 2)][ac - 1];
    for (; i != sqrt(ac - 2); i++)for (j = 0; j != sqrt(ac - 2); ++j, k++)tab[i][j] = atof(av[k]);
}

void cosh_(int ac, char **av)
{
    int i = 0, j = 0;
    int k = 2;
    double tab[sqrt(ac - 2)][ac - 1];
    for (; i != sqrt(ac - 2); i++)for (j = 0; j != sqrt(ac - 2); ++j, k++)tab[i][j] = atof(av[k]);
}

void sinh_(int ac, char **av)
{
    int i = 0, j = 0;
    int k = 2;
    double tab[sqrt(ac - 2)][ac - 1];
    for (; i != sqrt(ac - 2); i++)for (j = 0; j != sqrt(ac - 2); ++j, k++)tab[i][j] = atof(av[k]);
}

void determine(int ac, char **av)
{
    void (*launch[5])(int, char **) = {cos_, exp_, sin_, cosh_, sinh_};
    char tab[5][5] = {"COS", "EXP", "SIN", "COSH", "SINH"};
    for (int i = 0; i != 5; ++i)if (comp(tab[i], av[1]) == 0)launch[i](ac, av);
}

int verify_h(char *str)
{
    if (strlen(str) == 2 && str[0] == '-' && str[1] == 'h') {
        printf("USAGE\n    ./108trigo fun a0 a1 a2 ...\n\nDESCRIPTION\n    fun     function to be applied, among at least “EXP”, “COS”, “SIN”, “COSH”and “SINH”\n    ai      coeficients of the matrix\n");
        return 0;
    }
    return 1;
}

int main(int ac, char **av)
{
    char tab[5][5] = {"COS", "EXP", "SIN", "COSH", "SINH"};
    int res = 0;
    if (ac == 2 && verify_h(av[1]) == 0)return 0;
    if (ac < 3)return 84;
    if (sqrt(ac - 2) * sqrt(ac - 2) != (double)(ac - 2))return 84;
    for (int i = 0; i != 5; ++i)if (comp(tab[i], av[1]) == 0)res++;
    if (res == 1);
    else return 84;
    for (int i = 2; i != ac; ++i)for (int j = 0; av[i][j] != '\0'; ++j)if (av[i][j] > 57 || av[i][j] < 45)return 84;
    determine(ac, av);
}
/*
** EPITECH PROJECT, 2019
** 108trigo
** File description:
** 108trigo
*/

#include "my.h"

double **create_idt(int ac)
{
    int space[2] = {0, 0};
    int fin = (int)sqrt(ac);
    double **idt = malloc(sizeof(double * ) * (fin + 1));
    for (int i = 0; i != fin; ++i)idt[i] = malloc(sizeof(double) * (fin + 1));
    for (int i = 0; i != fin; ++i) {
        for (int j = 0; j != fin; ++j) {
            idt[i][j] = 0;
            if (i == space[0] && j == space[1])idt[i][j] = 1;
        }
        space[0]++;
        space[1]++;
    }
    return idt;
}

double factoriel(int nb)
{
    double res = 1;
    for (; nb != 0; nb--)res *= nb;
    return res;
}

double **div_(double **save, int lol, int ac)
{
    for (int i = 0; i != sqrt(ac - 2); ++i) {
        for (int j = 0; j != sqrt(ac - 2); ++j) {
            save[i][j] /= factoriel(lol);
        }
    }
    return save;
}

double **menos(double **matrice, double **matrice2, int ac)
{
    int salut = sqrt(ac - 2);
    double **resu = malloc(sizeof(double *) * (salut + 1));
    for (int i = 0; i != sqrt(ac - 2); ++i) {
        resu[i] = malloc(sizeof(double) * (ac - 1));
        for (int j = 0; j != sqrt(ac - 2); ++j) {
            resu[i][j] = matrice[i][j] - matrice2[i][j];
        }
    }
    return resu;
}

double **add(double **matrice, double **matrice2, int ac)
{
    int salut = sqrt(ac - 2);
    double **resu = malloc(sizeof(double *) * (salut + 1));
    for (int i = 0; i != sqrt(ac - 2); ++i) {
        resu[i] = malloc(sizeof(double) * (ac - 1));
        for (int j = 0; j != sqrt(ac - 2); ++j) {
            resu[i][j] = matrice[i][j] + matrice2[i][j];
        }
    }
    return resu;
}

double **pow_(double **matrice, int nb, int ac)
{
    int number = (int)sqrt(ac - 2);
    double **A = malloc(sizeof(double *) * ((ac + 1)));
    double **B = malloc(sizeof(double *) * ((ac + 1)));
    for (int i = 0; i != number; ++i)A[i] = malloc(sizeof(double) * ((ac + 1)));
    for (int i = 0; i != number; ++i)B[i] = malloc(sizeof(double) * ((ac + 1)));
    for (int i = 0; i != number; ++i)for (int j = 0; j != number; ++j)B[i][j] = 0;
    for (int i = 0; i != number; ++i)for (int j = 0; j != number; ++j)A[i][j] = matrice[i][j];
    double resu = 1;
    for (int k = 0; k != nb - 1; ++k) {
        for (int i = 0; i != number; ++i) {
            for (int j = 0; j != number; ++j) {
                for (int lol = 0; lol != number; lol++) {
                    resu *= A[i][lol];
                    resu *= matrice[lol][j];
                    B[i][j] += resu;
                    resu = 1;
                }
            }
        }
        for (int i = 0; i != number; ++i)for (int j = 0; j != number; ++j)A[i][j] = B[i][j];
        for (int i = 0; i != number; ++i)for (int j = 0; j != number; ++j)B[i][j] = 0;
    }
    return A;
}

int comp(char *str, char *str2)
{
    if (strlen(str) != strlen(str2))return 1;
    for (int i = 0; str[i] != '\0'; i++)if (str[i] != str2[i])return 1;
    return 0;
}

double **cos_(int ac, char **av)
{
    double **identite = create_idt(ac - 2);
    int i, j, size, aled = 0;
    int k = 2;
    double save_ = 1000, save_1 = 0;
    size = sqrt(ac - 2);
    double **tab = malloc(sizeof(double *) * (size));
    double **res = malloc(sizeof(double *) * (size));
    double **save = malloc(sizeof(double *) * (size));
    for (i = 0; i != sqrt(ac - 2); i++) {
        res[i] = malloc(sizeof(double) * (ac - 1));
        tab[i] = malloc(sizeof(double) * (ac - 1));
        save[i] = malloc(sizeof(double) * (ac - 1));
        for (j = 0; j != sqrt(ac - 2); ++j, k++) {
            tab[i][j] = atof(av[k]);
        }
    }
    for (int i = 0; i != sqrt(ac - 2); ++i)for (int j = 0; j != sqrt(ac - 2); ++j)res[i][j] = 0;
    res = add(identite, res, ac);
    aled = 1;
    for (i = 2; fabs(save_ - save_1) > 0.0001; i += 2) {
        save_1 = save_;
        save = pow_(tab, i, ac);
        save = div_(save, i, ac);
        if (aled == 1) {
            res = menos(res, save, ac);
            aled = 0;
        }
        else if (aled == 0){
            res = add(res, save, ac);
            aled = 1;
        }
        save_ = res[0][0];
    }
    return res;
}

double **exp_(int ac, char **av)
{
    double **identite;
    identite = create_idt(ac - 2);
    int i, j, size = 0;
    int k = 2;
    double save_ = 1000, save_1 = 0;
    size = sqrt(ac - 2);
    double **tab = malloc(sizeof(double *) * (size));
    double **res = malloc(sizeof(double *) * (size));
    double **save = malloc(sizeof(double *) * (size));
    for (i = 0; i != sqrt(ac - 2); i++) {
        res[i] = malloc(sizeof(double) * (ac - 1));
        tab[i] = malloc(sizeof(double) * (ac - 1));
        save[i] = malloc(sizeof(double) * (ac - 1));
        for (j = 0; j != sqrt(ac - 2); ++j, k++) {
            tab[i][j] = atof(av[k]);
        }
    }
    for (int i = 0; i != sqrt(ac - 2); ++i)for (int j = 0; j != sqrt(ac - 2); ++j)res[i][j] = 0;
    res = add(identite, tab, ac);
    for (i = 2; fabs(save_ - save_1) > 0.0001; i++) {
        save_1 = save_;
        save = pow_(tab, i, ac);
        save = div_(save, i, ac);
        res = add(res, save, ac);
        save_ = res[0][0];
    }
    return res;
}

double **sin_(int ac, char **av)
{
    double **identite;
    identite = create_idt(ac - 2);
    int i, j, size = 0;
    int k = 2;
    double save_ = 1000, save_1 = 0, aled = 0;
    size = sqrt(ac - 2);
    double **tab = malloc(sizeof(double *) * (size));
    double **res = malloc(sizeof(double *) * (size));
    double **save = malloc(sizeof(double *) * (size));
    for (i = 0; i != sqrt(ac - 2); i++) {
        res[i] = malloc(sizeof(double) * (ac - 1));
        tab[i] = malloc(sizeof(double) * (ac - 1));
        save[i] = malloc(sizeof(double) * (ac - 1));
        for (j = 0; j != sqrt(ac - 2); ++j, k++) {
            tab[i][j] = atof(av[k]);
        }
    }
    for (int i = 0; i != sqrt(ac - 2); ++i)for (int j = 0; j != sqrt(ac - 2); ++j)res[i][j] = 0;
    res = add(res, tab, ac);
    for (i = 3; fabs(save_ - save_1) > 0.0001; i += 2) {
        save_1 = save_;
        save = pow_(tab, i, ac);
        save = div_(save, i, ac);
        if (aled == 0) {
            res = menos(res, save, ac);
            aled = 1;
        }
        else {
            res = add(res, save, ac);
            aled = 0;
        }
        save_ = res[0][0];
    }
    return res;
}

double **cosh_(int ac, char **av)
{
    double **identite;
    identite = create_idt(ac - 2);
    int i, j, size = 0;
    int k = 2;
    double save_ = 1000, save_1 = 0;
    size = sqrt(ac - 2);
    double **tab = malloc(sizeof(double *) * (size));
    double **res = malloc(sizeof(double *) * (size));
    double **save = malloc(sizeof(double *) * (size));
    for (i = 0; i != sqrt(ac - 2); i++) {
        res[i] = malloc(sizeof(double) * (ac - 1));
        tab[i] = malloc(sizeof(double) * (ac - 1));
        save[i] = malloc(sizeof(double) * (ac - 1));
        for (j = 0; j != sqrt(ac - 2); ++j, k++) {
            tab[i][j] = atof(av[k]);
        }
    }
    for (int i = 0; i != sqrt(ac - 2); ++i)for (int j = 0; j != sqrt(ac - 2); ++j)res[i][j] = 0;
    res = add(identite, res, ac);
    for (i = 2; fabs(save_ - save_1) > 0.0001; i += 2) {
        save_1 = save_;
        save = pow_(tab, i, ac);
        save = div_(save, i, ac);
        res = add(res, save, ac);
        save_ = res[0][0];
    }
    return res;
}

double **sinh_(int ac, char **av)
{
    double **identite;
    identite = create_idt(ac - 2);
    int i, j, size = 0;
    int k = 2;
    double save_ = 1000, save_1 = 0;
    size = sqrt(ac - 2);
    double **tab = malloc(sizeof(double *) * (size));
    double **res = malloc(sizeof(double *) * (size));
    double **save = malloc(sizeof(double *) * (size));
    for (i = 0; i != sqrt(ac - 2); i++) {
        res[i] = malloc(sizeof(double) * (ac - 1));
        tab[i] = malloc(sizeof(double) * (ac - 1));
        save[i] = malloc(sizeof(double) * (ac - 1));
        for (j = 0; j != sqrt(ac - 2); ++j, k++) {
            tab[i][j] = atof(av[k]);
        }
    }
    for (int i = 0; i != sqrt(ac - 2); ++i)for (int j = 0; j != sqrt(ac - 2); ++j)res[i][j] = 0;
    res = add(res, tab, ac);
    for (i = 3; fabs(save_ - save_1) > 0.0001; i += 2) {
        save_1 = save_;
        save = pow_(tab, i, ac);
        save = div_(save, i, ac);
        res = add(res, save, ac);
        save_ = res[0][0];
    }
    return res;
}

void determine(int ac, char **av)
{
    double **res;
    int i = 0, j = 0;
    double** (*launch[5])(int, char **) = {cos_, exp_, sin_, cosh_, sinh_};
    char tab[5][5] = {"COS", "EXP", "SIN", "COSH", "SINH"};
    for (int i = 0; i != 5; ++i)if (comp(tab[i], av[1]) == 0)res = launch[i](ac, av);
    for (i = 0; i != sqrt(ac - 2); ++i) {
        for (j = 0; j != sqrt(ac - 2) - 1; ++j) {
            printf("%0.2lf\t", res[i][j]);
        }
        printf("%0.2lf\n", res[i][j]);
    }
}

int verify_h(char *str)
{
    if (strlen(str) == 2 && str[0] == '-' && str[1] == 'h') {
        printf("USAGE\n    ./108trigo fun a0 a1 a2 ...\n\nDESCRIPTION\n    fun     function to be applied, among at least “EXP”, “COS”, “SIN”, “COSH”and “SINH”\n    ai      coeficients of the matrix\n");
        return 0;
    }
    return 1;
}

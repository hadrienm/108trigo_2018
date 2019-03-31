#ifndef MY_H
#define MY_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double **create_idt(int ac);
double factoriel(int nb);
double **div_(double **save, int lol, int ac);
double **menos(double **matrice, double **matrice2, int ac);
double **add(double **matrice, double **matrice2, int ac);
double **pow_(double **matrice, int nb, int ac);
int comp(char *str, char *str2);
double **cos_(int ac, char **av);
double **exp_(int ac, char **av);
double **sin_(int ac, char **av);
double **cosh_(int ac, char **av);
double **sinh_(int ac, char **av);
void determine(int ac, char **av);
int verify_h(char *str);

#endif //MY_H

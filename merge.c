#include <stdio.h>
#include <stdlib.h>

/*Affiche les éléments du tableau de taille n séparés par un espace.*/
void afficherTableau(int *tableau, int N)
{

    for (int i = 0; i < N; i++)
    {
        printf("%d ", *(tableau + i));
    }
    printf("\n");
}

/*Le tableau de taille N est séparé en deux piles : [0..m] est trié et [m..N] est trié. La fonction construit dans *table le tableau fusionné trié en entier.*/
void fusion(int *table, int N, int m)
{
    int i, j, count;
    i = 0; //i varie de 0 à m
    j = m; //j varie de m à N-1
    /*Création d'une copie du tableau de départ*/
    int *newtable = malloc(N * sizeof(int));
    for (count = 0; count < N; count++)
    {
        if (i == m) // on est arrivé au bout de la première pile, il faut piocher sur la deuxième
        {
            newtable[count] = table[j];
            j++;
        }
        else if (j == N) //On est arrivé au bout de la deuxième pile, il faut piocher sur la première
        {
            newtable[count] = table[i];
            i++;
        }
        else if (table[j] < table[i]) // Si l'élément de la première pile est inférieur à celui de la deuxième, on l'insère
        {
            newtable[count] = table[j];
            j++;
        }
        else // Si c'est le contraire, on insère le deuxième.
        {
            newtable[count] = table[i];
            i++;
        }
    }
    /* Copie de newtab dans tab*/
    for (count = 0; count < N; count++)
        table[count] = newtable[count];
    /*On libère l'espace alloué pour newtab*/
    free(newtable);
}

/*On applique récursivement la fonction aux deux parties [0..m] et [m+1..N] jusqu'à ce que les tableaux soient de taille au plus 2 et on les refusionne.*/
void triFusion(int *table, int N)
{
    if (N >= 2)
    {
        int m = N / 2;
        triFusion(table, m);
        triFusion(table + m, N - m);
        fusion(table, N, m);
    }
    else
        return;
}

int main()
{

    int tableau[] = {9, 10, 15, 26, 1, 0, 29, 29, 29, 36, 156, -2};
    int N = sizeof(tableau) / sizeof(tableau[0]);
    printf("Avant tri :\n");
    afficherTableau(tableau, N);
    triFusion(tableau, N);
    printf("Après tri :\n");
    afficherTableau(tableau, N);
    return 0;
}
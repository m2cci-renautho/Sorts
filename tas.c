#include <stdio.h>
#include <stdlib.h>

//Accès aux parents et aux enfants
#define LEFT(i) (i << 1) + 1
#define RIGHT(i) ((i << 1) + 2)
#define PARENT(i) (i >> 1) - 1

/* Affichage du tableau */
void afficherTableau(int *tableau, int N)
{

    for (int i = 0; i < N; i++)
    {
        printf("%d ", *(tableau + i));
    }
    printf("\n");
}
/* positionne correctement dans le tas table le noeud i pour respecter la structure de tas-max.*/
void entasserMax(int *table, int N, int i)
{
    int left = LEFT(i);
    int right = RIGHT(i);
    int max, EC;
    /*Sélectionner l'indice du maximum */
    if (left < N && table[left] > table[i])
    {
        max = left;
    }
    else
        max = i;
    if (right < N && table[right] > table[max])
        max = right;
    /*Si le noeud i n'est pas 'à sa place', on permute table[i] et table[max]*/
    if (max != i)
    {
        EC = table[i];
        table[i] = table[max];
        table[max] = EC;
        /* On recommence avec le voisin qui a la valeur maximum */
        entasserMax(table, N, max);
    }
    /* Terminaison : à un moment donné, max = N et le noeud est à sa place et on ne peut plus aller à droite ou à gauche*/
}
/*Construit une structure de tas-max dans le tableau table en entassant chacun de ses noeud à partir des feuilles.*/
void construireTasMax(int *table, int N)
{
    int taille = N;
    for (int i = taille >> 1; i >= 0; i--)
        entasserMax(table, N, i);
}
/*Tri du tableau table suivant l'algorithme du tri par tas*/
void triParTas(int *table, int N)
{
    int EC;
    /*On met le tableau sous forme d'un tas max*/
    construireTasMax(table, N);
    for (int taille = N; taille > 0; taille--)
    {
        /*On échange table[0] qui est le plus grand élément avec T[N-1]*/
        EC = table[0];
        table[0] = table[taille - 1];
        table[taille - 1] = EC;
        /*On diminue la taille du tas et on reconstitue la structure de tas à partir de table[0]*/
        entasserMax(table, taille - 1, 0);
    }
}
int main()
{

    int N;
    scanf("%d\n", &N);

    int *table = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
        scanf("%d", &table[i]);

    triParTas(table, N);
    afficherTableau(table, N);

    return 0;
}
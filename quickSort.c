#include <stdio.h>
#include <stdlib.h>

void afficherTableau(int *tableau, int p, int r)
{

    for (int i = p; i <= r; i++)
    {
        printf("%d ", *(tableau + i));
    }
    printf("\n");
}

/*Fonction choisissant l'indice q auquel couper le tableau en 2 parties telles que
    A[p..q] soit tel que pour tout p<j<q, A[j]<A[q]
*/
int partition(int *A, int p, int r)
{
    int pivot = A[r]; //Choix du pivot A[r]
    int i = p - 1;    //candidat, pour l'instant en dehors du tableau
    int EC;           //Entier temporaire
    for (int j = p; j <= r - 1; j++)
    { //j parcourt le tableau jusqu'à r-1

        if (A[j] <= pivot)
        { // Si l'entier A[j] < pivot, on incrémente i et on échange A[i] et A[j]
            i = i + 1;
            EC = A[j];
            A[j] = A[i];
            A[i] = EC;
        }
    }
    EC = A[i + 1]; //On a échange le pivot avec la valeur de A[i+1]
    A[i + 1] = A[r];
    A[r] = EC;
    return i + 1;
}

void quickSort(int *A, int p, int r)
{
    if (p < r)
    {                               //Tant que le tableau est de taille > 1
        int q = partition(A, p, r); //On calcule la valeur 'médiane'
        quickSort(A, p, q - 1);     // On recommence avec la partie inférieure
        quickSort(A, q + 1, r);     //Et avec la partie supérieure
    }
}
int main()
{

    int N;
    scanf("%d\n", &N);

    int *table = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
        scanf("%d", &table[i]);

    quickSort(table, 0, N - 1);
    afficherTableau(table, 0, N - 1);

    return 0;
}
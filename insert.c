#include <stdio.h>
#include <stdlib.h>

void afficherTableau(int *tableau, int N)
{

    for (int i = 0; i <N; i++)
    {
        printf("%d ", *(tableau + i));
    }
    printf("\n");
}

void triInsertion(int *T, int N){

    int EC,j;
    for(int i = 1; i<N; i++){
        EC = T[i];
        j = i-1;
        while(j>=0 && EC < T[j]){
            T[j+1] = T[j];
            j--;
        }
        T[j+1] = EC;
    }
}
int main(){

    int N;
    scanf("%d\n", &N);

    int *table = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
        scanf("%d", &table[i]);

    triInsertion(table, N);
    afficherTableau(table, N);
    return 0;
}
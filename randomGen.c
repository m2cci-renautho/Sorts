#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* A la lecture d'un nombre N, écrit N entiers aléatoires entre 0 et 99 séparés par un espace.
Cela permet de créer un fichier de test pour les différents algorithmes de tri */


int main(){

   time_t t;
   srand((unsigned) time(&t));
   long int N;
   scanf("%ld", &N);
   printf("%ld\n", N);
   for( int i = 0 ; i < N ; i++ ) {
      printf("%d ", rand() % MAX);
   }
}
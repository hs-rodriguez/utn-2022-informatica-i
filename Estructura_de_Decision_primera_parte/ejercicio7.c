/*
    Ejercicio 7:
    Decir si un numero N es divisible por M
*/

#include <stdio.h>

int main (void)
{
    int N, M;
    printf("Ingrese el dividendo: ");
    scanf("%d", &N);
    printf("Ingrese el divisor: ");
    scanf("%d", &M);

    if (N % M == 0)
        printf ("El resultado es: %d", N / M);
    else
        printf("La division no es exacta.");

    return 0;
}
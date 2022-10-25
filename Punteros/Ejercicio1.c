/**
 * Ejercicio 1:
 * Realizar una función INTERCAMBIO, que intercambie los valores de dos variables
 * enteras declaradas en el programa principal
 */

#include <stdio.h>

void Intercambio(int *, int *);

int main(void)
{
    int n1, n2;
    printf("\nIngrese el valor de n1: ");
    scanf("%d", &n1);
    printf("\nIngrese el valor de n2: ");
    scanf("%d", &n2);

    Intercambio(&n1, &n2);

    printf("\nValor de n1: %d", n1);
    printf("\nValor de n2: %d", n2);

    return 0;
}

void Intercambio(int *n1, int *n2)
{
    int aux;
    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}
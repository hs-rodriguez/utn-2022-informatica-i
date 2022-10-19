/**
 * Ejercicio 3:
 * Indicar la cantidad de unos de un numero entero ingresado por teclado
 */
#include <stdio.h>

int main(void)
{
    int n, i, mask = 1, cant = 0;
    printf("\nIngrese el numero: ");
    scanf("%d", &n);
    for (i = 0; i < sizeof(n)*8; i++)
    {
        if (n & mask)
            cant++;
        mask *= 2;
    }
    printf("\nEl numero %d tiene %d unos en binario.", n, cant);
    return 0;
}
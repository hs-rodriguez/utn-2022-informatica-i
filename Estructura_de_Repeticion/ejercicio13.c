/*
    Ejercicio 13:
    Determinar:
    a) Todos los numeros primos entre 1 y 100. 
    (Un nro es primo solo cuando es divisible por 1 y si mismo)
    b) Contar dichos numeros.
*/

#include <stdio.h>

int main (void)
{
    int cant = 0;

    printf("Numeros primos de 1 a 100: ");

    for (int i = 2; i <= 100; i++)
    {
        switch (i)
        {
        case 2:
        case 3:
        case 5:
        case 7:
            cant++;
            printf("%d ", i);
        default:
            if (i % 2 != 0 && i % 3 != 0 && i % 5 != 0 && i % 7 != 0)
            {
                cant++;
                printf("%d ", i);
            }
            break;
        }
    }

    printf("\nCantidad de primos: %d", cant);

    return 0;
}
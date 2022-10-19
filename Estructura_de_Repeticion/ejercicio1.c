/*
    Ejercicio 1:
    Se ingresan 50 números enteros.
    Determinar:
    a-) Cantidad de números negativos.
    b-) La suma de números positivos.
    c-) Promedio de los números positivos
*/

#include <stdio.h>

int main (void)
{
    int ingreso = 0, cantNeg = 0, suma = 0, cont = 0;
    float prom = 0;

    for (int i = 1; i <= 50; i++)
    {
        printf("Ingrese un numero entero (%d/50): ",i);
        scanf("%d", &ingreso);

        if (ingreso < 0)
            cantNeg++;
        else if (ingreso > 0)
        {
            suma += ingreso;
            cont++;
        }
    }

    if (cont != 0)
        prom = suma / cont;

    printf("\nCantidad de negativos: %d", cantNeg);
    printf("\nSuma de los positivos: %d", suma);
    printf("\nPromedio de los positivos: %.2f", prom);

    return 0;
} 
/*
    Ejercicio 7:
    Se ingresa N y N numeros naturales. Determinar:
    a) La cantidad de valores multiplos de 3.
    b) La suma de los valores que se ingresaron en orden par.
    c) El promedio de los numeros multiplos de 5 pero no multiplos de 3.
*/

#include <stdio.h>

int main (void)
{
    int n, natural, mult3 = 0, suma = 0, mult5 = 0;
    float prom;

    printf("Ingrese el valor de N: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &natural);

        if (natural % 3 == 0)
            mult3++;
        else if (natural % 5 == 0)
        {
            prom += natural;
            mult5++;
        }
        if (i % 2 == 0)
            suma += natural;
    }

    if (mult5 != 0)
        prom /= mult5;

    printf("\nCantidad de multiplos de 3: %d", mult3);
    printf("\nSuma de ingresos en orden par: %d", suma);
    printf("\nPromedio de multiplos de 5 pero no de 3: %.2f", prom);

    return 0;
}
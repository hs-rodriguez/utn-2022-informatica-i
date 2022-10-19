/*
    Ejercicio 4:
    Se ingresan 50 números enteros. Determinar el promedio de los números pares.
*/

#include <stdio.h>

int main (void)
{
    int ingreso = 0, cont = 0;
    float prom = 0;

    for (int i = 1; i <= 50; i++)
    {
        printf("Ingrese un entero (%d/50): ", i);
        scanf("%d", &ingreso);
        if (ingreso % 2 == 0)
        {
            prom += ingreso;
            cont++;
        }
    }

    if (cont != 0)
    {
        prom = prom / cont;
    }
    
    printf("El promedio de los pares es: %.2f", prom);
    
    return 0;
}
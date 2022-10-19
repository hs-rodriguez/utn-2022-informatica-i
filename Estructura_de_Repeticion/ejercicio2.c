/*
    Ejercicio 2:
    Sumar los primeros 10 nros. Naturales Pares. (sin ingreso de datos)
*/

#include <stdio.h>

int main (void)
{
    int suma;
    for (int i = 1; i <= 10 ; i++)
    {
        printf("%d", i*2);
        if (i<10)
            printf("+");
        
        suma += (i*2);
    }
    
    printf(" = %d", suma);

    return 0;
}
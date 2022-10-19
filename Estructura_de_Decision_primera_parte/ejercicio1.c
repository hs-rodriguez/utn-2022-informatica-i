/*
    Ejercicio 1:
    Decir si un Nro. entero es par o impar.
*/

#include <stdio.h>

int main (void)
{
    int numero;
    
    printf("Ingrese un numero entero: ");
    scanf("%d", &numero);

    if (numero % 2 == 0)
    {
        printf ("El numero es par.");
    }
    else
    {
        printf("El numero es impar");
    }

    return 0;
}

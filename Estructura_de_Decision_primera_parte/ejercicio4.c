/*
    Ejercicio 4:
    Dados tres nros. Determinar e informar con un mensaje
    si el primer nro. ingresado es menor que los otros dos.
*/

#include <stdio.h>

int main (void)
{
    float n1, n2, n3;
    printf ("Ingrese tres numeros: ");
    scanf("%f %f %f", &n1, &n2, &n3);

    if(n1 < n2 && n1 < n3)
    {
        printf("El numero %.2f es menor.", n1);
    }
    else
    {
        printf("El numero %.2f no es el menor.", n1);
    }

    return 0;
}
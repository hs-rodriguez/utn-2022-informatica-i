/*
    Ejercicio 12:
    Confeccionar un programa que permita ingresar 4 valores enteros
    de longitud, de a uno por vez y determine el menor valor y su numero de orden.
    Informe los valores ingresados e identifique al menor con mensaje aclaratorio.
*/

#include <stdio.h>

int main (void)
{
    int n1, n2, n3, n4, aux, orden;
    printf("Ingrese un valor entero de longitud: ");
    scanf("%d", &n1);
    printf("Ingrese otro valor entero de longitud: ");
    scanf("%d", &n2);
    printf("Ingrese otro valor entero de longitud: ");
    scanf("%d", &n3);
    printf("Ingrese otro valor entero de longitud: ");
    scanf("%d", &n4);

    aux = n1;
    orden = 1;
    if (n2 < aux)
    {
        aux = n2;
        orden = 2;
    }
    if (n3 < aux)
    {
        aux = n3;
        orden = 3;
    }
    if (n4 < aux)
    {
        aux = n4;
        orden = 4;
    }

    printf("El numero menor es %d y fue el numero de la posicion %d.", aux, orden);
    return 0;
}
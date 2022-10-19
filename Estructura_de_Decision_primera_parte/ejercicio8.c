/*
    Ejercicio 8:
    Ingresar 3 valores reales y
    a) Si los dos primeros son mayores al tercero informar "MAYORES AL TERCERO"
    b) Si los tres son iguales informas "TRES IGUALES"
    c) Si alguno de los dos primeros es menor al tercero informar "ALGUNO ES MENOR"
*/

#include <stdio.h>

int main (void)
{
    float n1, n2, n3;
    printf("Ingrese tres valores reales: ");
    scanf("%f%f%f", &n1, &n2, &n3);

    if (n1 > n3 && n2 > n3)
        printf("MAYORES AL TERCERO");
    else
        if (n1 == n2 && n2 == n3)
            printf("TRES IGUALES");
        else
            printf("ALGUNO ES MENOR");

    return 0;
}
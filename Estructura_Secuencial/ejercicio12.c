/*
    Ejercicio 12:
    Confeccionar un programa que solicite el ingreso del valor del radio de un
    círculo y determine la superficie, perímetro y volumen del mismo.

    ^Un circulo no tiene volumen, puesto que es un elemento en 2 dimensiones.
*/

#include <stdio.h>

#define pi 3.1416

int main(void)
{
    float radio, superficie, perimetro;

    printf("Ingrese el radio de la circunferencia: ");
    scanf("%f", &radio);

    superficie = pi * radio * radio;
    perimetro = 2 * pi * radio;

    printf("\nSuperficie: %.2f", superficie);
    printf("\nPerimetro: %.2f", perimetro);

    return 0;
}
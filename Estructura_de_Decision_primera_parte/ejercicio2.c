/*
    Ejercicio 2:
    Se ingresan dos números N1 (dividendo) y N2 (divisor). 
    Dividirlos siempre que sea posible.
*/

#include <stdio.h>

int main (void) 
{
    float dividendo, divisor, cociente;

    printf("Ingrese el numero a dividir: ");
    scanf("%f", &dividendo);
    printf("Ingrese el divisor: ");
    scanf("%f", &divisor);

    if(divisor != 0)
    {
        cociente = dividendo / divisor;
        printf ("El resultado es: %.2f", cociente);
    }
    else
    {
        printf("La division no se puede realizar.");
    }

    return 0;
}
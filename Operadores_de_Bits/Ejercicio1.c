/**
 * Ingresar dos números enteros y calcular la resta utilizando el complemento a 2
 */
#include <stdio.h>

int main (void)
{
    short int n1, n2, resta;
    printf("\nIngrese el primer numero: ");
    scanf("%hd", &n1);
    printf("\nIngrese el segundo numero: ");
    scanf("%hd", &n2);
    resta = n1 + (~n2+1);
    printf("\nLa resta %hd - %hd es: %hd", n1, n2, resta);
    return 0;
}
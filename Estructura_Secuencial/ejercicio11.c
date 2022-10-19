/*
    Ejercicio 11:
    Una cotillón vende chicles. La caja de 60 unidades vale $82 y por unidad $2.
    Se ingresa la cantidad de chicles a comprar. 
    Calcular e informar el importe a pagar y la cantidad de cajas compradas.
*/

#include <stdio.h>

int main(void)
{
    int chicles, cajas, importe;

    printf("Ingrese los chicles a comprar: ");
    scanf("%d", &chicles);

    cajas = chicles / 60;
    chicles %= 60;
    importe = cajas * 82 + chicles * 2;

    printf("\nImporte: $%d", importe);
    printf("\nCajas: %d", cajas);

    return 0;
}
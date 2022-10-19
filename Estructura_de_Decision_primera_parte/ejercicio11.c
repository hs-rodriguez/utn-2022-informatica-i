/*
    Ejercicio 11:
    La farmacia efectúa descuetos según el importe de la compra
    con la siguiente escala:
    a) menor de $3255 el descuento es del 4,5%
    b) entre $3255 y $5000 un 8,0%
    c) más de $5000 el descuento es del 10,5%
    Confeccionar un programa que reciba un importe e informe: el precio
    ingresado, el descuento y el precio neto a cobrar, con mensajes aclaratorios
*/

#include <stdio.h>
int main (void)
{
    float importe, porcentaje, descuento, neto;
    printf("Ingrese el importe: ");
    scanf("%f", &importe);

    porcentaje = 0.045;
    if (importe >= 3255 && importe <= 5000)
        porcentaje = 0.08;
    else
        if (importe > 5000)
            porcentaje = 0.105;
    
    descuento = importe * porcentaje;
    printf("\n\nImporte: %.2f", importe);
    printf("\nDescuento (%.1f%%): %.2f", porcentaje*100, descuento);
    printf("\nPrecio neto: %.2f", importe - descuento);

    return 0;
}
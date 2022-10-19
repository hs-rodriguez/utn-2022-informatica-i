/*
    Ejercicio 6:
    Por una promoción se realiza un descuento del 10% sobre el total de la compra.
    Se conoce el precio unitario del producto y la cantidad comprada. Determinar el 
    importe sin descuento, el descuento y el importe resultante.
*/

#include <stdio.h>

int main(void)
{
    int cantidad;
    float precio, total, descuento, final;

    printf("Ingrese el precio unitario: ");
    scanf("%f", &precio);
    printf("Ingrese la cantidad comprada: ");
    scanf("%d", &cantidad);

    total = precio * cantidad;
    descuento = total * 0.1;
    final = total - descuento;

    printf("\nEl importe total es: %.2f", total);
    printf("\nEl descuento (10%) es: %.2f", descuento);
    printf("\nEl importe final es: %.2f", final);

    return 0;
}
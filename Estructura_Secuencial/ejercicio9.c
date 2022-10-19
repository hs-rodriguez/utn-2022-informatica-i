/*
    Ejercicio 9:
    Una proveeduría de alfajores realiza descuentos dependiendo de la cantidad
    comprada. Los alfajores se pueden comprar sueltos o por caja. 
    Cada caja tiene una docena de alfajores.
    Se realiza un 5% de descuento cuando se compra caja.
    Se nos suministra por cada compra la cantidad comprada y el precio unitario
    del alfajor.
    INFORMAR:
    El importe sin descuento, el descuento y el importe final de la compra.
*/

#include <stdio.h>

int main(void)
{
    int cantidad, cajas;
    float precio, total, descuento, final;

    printf("Ingrese la cantidad de alfajores: ");
    scanf("%d", &cantidad);
    printf("Ingrese el precio unitario: ");
    scanf("%f", &precio);

    total = precio * cantidad;
    cajas = cantidad / 12;
    cantidad %= 12;
    descuento = cajas * 12 * precio * 0.05;
    final = total - descuento;

    printf("\nEl importe total es: %.2f", total);
    printf("\nEl descuento (5%% en cada caja) es: %.2f", descuento);
    printf("\nEl importe final es: %.2f", final);

    return 0;
}
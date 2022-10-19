/**
 * En un negocio de ropa deportiva por cada venta que se realiza se ingresa el precio del producto,
 * la cantidad vendida y la forma de pago. Teniendo en cuenta:
 * Efectivo se realiza un descuento del 15%
 * Tarjeta de crédito tiene un recargo del 15%
 * Tarjeta de débito tiene un descuento del 10%
 * Determinar el importe a pagar de cada venta y la recaudación total.
 * En ingreso finaliza con cantidad vendida cero.
 * Resolverlo utilizando la siguiente enumeración
 * enum FormaDePago {efectivo=1, credito, debito};
 */

#include <stdio.h>

int main(void)
{
    int cantidadVendida, formaPago, band;
    float precioUnitario, importe, recaudacion = 0;
    enum FormaDePago {efectivo=1, credito, debito};

    printf("\nIngrese la cantidad vendida: ");
    scanf("%d", &cantidadVendida);
    while (cantidadVendida > 0) {
        printf("\nIngrese el precio del producto: ");
        scanf("%f", &precioUnitario);
        importe = precioUnitario * cantidadVendida;
        band = 0;
        printf("\nIngrese la forma de pago (1: Efectivo, 2: Credito, 3: Debito): ");
        scanf("%d", &formaPago);
        switch (formaPago) {
            case efectivo: importe *= 0.85; break;
            case credito: importe *= 1.15; break;
            case debito: importe *= 0.9; break;
            default: band++;
        }
        if (!band) {
            printf("\nEl importe a pagar es: %.2f", importe);
            recaudacion += importe;
        }
        else
            printf("\nLa forma de pago no es valida.");

        printf("\nIngrese la cantidad vendida: ");
        scanf("%d", &cantidadVendida);
    }

    printf("\n\nLa recaudacion total es: %.2f", recaudacion);
    return 0;
}

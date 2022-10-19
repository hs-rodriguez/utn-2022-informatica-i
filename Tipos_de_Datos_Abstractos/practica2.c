/**
 * En un negocio de ropa deportiva, por cada venta que se realiza,
 * se ingresa el precio del producto, la cantidad vendida y la forma de pago.
 * Teniendo en cuenta:
 * Efectivo se realiza n descuento del 15%
 * Tarjeta de credito tiene un recargo de 15%
 * Tarjeta de debito tiene un descuento del 10%
 * Determinar el importe a pagar de cada venta y la recaudacion total.
 * El ingreso finaliza con cantidad vendida cero
 * Resolverlo utilizando la siguiente enumeracion
 * enum FormaDePago {efectivo=1, credito, debito}
 */

#include <stdio.h>

int main (void) {
    float precio, recaudacion;
    int cantidad, forma;
    printf("\nIngrese la cantidad vendida: ");
    scanf("%d", &cantidad);
    while (cantidad != 0)
    {
        if (cantidad < 0)
            printf("La cantidad vendida no puede ser negativo.");
        else {
            printf("Ingrese el precio unitario del producto: ");
            scanf("%f", &precio);
            printf("Ingrese forma de pago (1: efect, 2: credito, 3: debito): ");
            scanf()
        }
    }
    
    return 0;
}
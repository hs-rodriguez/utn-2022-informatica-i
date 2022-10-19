/*
    Ejercicio 15:
    En un negocio, por cada factura que se realiza, se dispone de: 
    Nro. de Factura- Cantidad vendida y precio unitario. 
    La información termina cuando se ingresa Nro. de factura cero.
    Se pide:
    a-) Importe de cada factura.
    b-) Recaudación del negocio.
    c-) Cantidad de facturas realizadas
    Se realiza un descuesto del 10% cuando el importe de la factura es superior a $5000.
*/

#include <stdio.h>

int main (void)
{
    int numeroFactura = 1, cantidadVendida, cantidadFacturas = 0;
    float precioUnitario, importe, recaudacion = 0;

    while (numeroFactura != 0)
    {
        printf("Ingrese el numero de factura: ");
        scanf("%d", &numeroFactura);

        if (numeroFactura == 0)
        {
            printf("\nRecaudacion: $%.2f", recaudacion);
            printf("\nCantidad de facturas: %d", cantidadFacturas);
        }
        else {
            printf("Ingrese la cantidad vendida: ");
            scanf("%d", &cantidadVendida);
            printf("Ingrese el precio unitario: ");
            scanf("%f", &precioUnitario);

            importe = precioUnitario * cantidadVendida;

            if (importe > 5000)
                importe *= 0.9;
            
            cantidadFacturas++;
            recaudacion += importe;

            printf("Importe: $%.2f\n\n", importe);
        }
    }

    return 0;
}
/*
    Ejercicio 16: 
    Un negocio de venta de granos desea controlar las ventas realizadas. 
    De cada una ingresa el importe total y un código que indica la forma de pago. 
    El código puede ser:
    C : cooperativa , 30% de descuento
    E : contado, 10% de descuento
    T : con tarjeta, 12% de recargo
    Se debe ingresar una F para finalizar el día de venta y arrojar los siguientes totales.
    Efectivo en caja : xxxx.xx
    Ventas con tarjeta : xxxx.xx
    Total de ventas : xxxx.xx
    Importe del IVA : xxxx.xx ( 21% del total vendido)
*/

#include <stdio.h>
#include <ctype.h>


int main (void)
{
    float importe, efectivo = 0, tarjeta = 0, total, iva;
    char codigo;

    while (codigo != 'F')
    {
        printf("Ingrese la forma de pago (C: Cooperativa | E: Contado | T: Tarjeta | F: Finalizar): ");
        scanf(" %c", &codigo);
        codigo = toupper(codigo);

        if (codigo == 'F')
        {
            total = efectivo + tarjeta;
            iva = total * 0.21;
            printf("\nEfectivo en caja: %.2f", efectivo);
            printf("\nVentas con tarjeta: %.2f", tarjeta);
            printf("\nTotal de ventas: %.2f", total);
            printf("\nImporte del IVA: %.2f", iva);
        }
        else {
            printf("Ingrese el importe de la compra: ");
            scanf("%f", &importe);
            
            switch (codigo)
            {
            case 'C':
                importe *= 0.7;
                efectivo += importe;
                break;
            case 'E':
                importe *= 0.9;
                efectivo += importe;
                break;
            case 'T':
                importe *= 1.12;
                tarjeta += importe;
                break;
            default:
                break;
            }
        }
    }
    

    return 0;
}
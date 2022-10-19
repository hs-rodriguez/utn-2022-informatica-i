/* 
    Un negocio de venta de granos desea controlar las ventas realizadas. De cada una ingresa el importe
    total y un código que indica la forma de pago. El código puede ser:
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

    printf("Ingrese el codigo: ");
        fflush(stdin);
        scanf("%c", &codigo);
        codigo = toupper(codigo);

    while (codigo != 'F'){
        printf("Ingrese el importe: ");
        scanf("%f", &importe);

        if (codigo == 'C')
        {
            importe = importe - importe * (30/100.0);
            efectivo = efectivo + importe;
        }
        else if (codigo == 'E')
        {
            importe = importe - importe * (10/100.0);
            efectivo = efectivo + importe;
        }
        else if (codigo == 'T')
        {
            importe = importe + importe * (12/100.0);
            tarjeta = tarjeta + importe;
        }
        else
            printf("\nEl codigo no es valido.");

        printf("Ingrese el codigo: ");
        fflush(stdin);
        scanf("%c", &codigo);
        codigo = toupper(codigo);
    }

    printf("\nEl efectivo es: $%.2f", efectivo);
    printf("\nLos pagos con tarjeta: $%.2f", tarjeta);
    total = efectivo + tarjeta;
    printf("El total es: $%.2f", total);
    iva = total * (21 / 100);
    printf("El IVA es: $%.2f", iva);

    return 0;
}
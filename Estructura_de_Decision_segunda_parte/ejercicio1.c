/*
    Ejercicio 1:
    En un negocio, según el mes hay promociones, a saber:
    MES 12, 1, 2, 3 Descuento del 10% sobre toda la compra, sin importar el medio de pago.
    MES 4, 5 Descuento en pago efectivo del 5% sobre total de la compra.
    MES 10, 11 Incremento del 5% para pago con tarjeta, solamente cuando el importe es inferior a
    $1000.-
    Resto de los meses No hay ni descuento ni incremento
    Se ingresa:
    Medio de Pago ( carácter(letra) )
    ‘E’ ---- Efectivo
    ‘T’ --- Tarjeta
    Mes de la compra (entero)
    Importe de la compra (real)
    INFORMAR:
    El importe final de la compra.
*/

#include <stdio.h>
#include <ctype.h>

int main (void)
{
    char pago;
    int mes;
    float importe;

    printf("Medios de pago:\n\tE ---> Efectivo\n\tT ---> Tarjeta\n\nIngrese su medio de pago: ");
    scanf("%c", &pago);

    pago = tolower(pago);

    if(pago != 'e' && pago != 't')
    {
        printf("El medio de pago ingresado no es valido.");
        return -1;
    }
    
    printf("Ingrese el mes de la compra: ");
    scanf("%d", &mes);

    if(mes < 1 || mes > 12)
    {
        printf("El mes ingresado no es valido.");
        return -1; 
    }

    printf("Ingrese el importe de la compra: ");
    scanf("%f", &importe);

    if(importe <= 0)
    {
        printf("El importe ingresado no es valido.");
        return -1; 
    }

    switch (mes)
    {
    case 12:
    case 1:
    case 2:
    case 3:
        importe *= 0.9;
        break;
    case 4:
    case 5:
        if (pago == 'e')
            importe *= 0.95;
        break;
    case 10:
    case 11:
        if (pago == 't' && importe < 1000)
            importe *= 1.05;
        break;
    }

    printf("El importe final de su compra es: %.2f", importe);

    return 0;
}
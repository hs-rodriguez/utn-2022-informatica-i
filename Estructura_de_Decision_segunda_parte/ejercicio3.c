/*
    Ejercicio 3:
    Un negocio vende distintos artículos identificados por un código, 
    y sus precios correspondientes , según se muestra:
    .código 1; 10 ; 100 : 120 pesos la unidad
    .código 2; 22; 222 : 70 pesos la unidad. La caja de 10 unidades vale 650 pesos.
    .código 3; 33 : 200 pesos la unidad. Si la compra es por más de 10 
    unidades se hace un descuento del 10% sobre el total de la compra.
    .código 4 ;44 : 100 peso la unidad.
    Confeccionar un programa que ingrese como dato el código de 
    un artículo y la cantidad a comprar y se informe el importe de la compra, 
    con las siguientes leyendas :
    ARTÍCULO xxxxx CANTIDAD xxxx IMPORTE A PAGAR $ xxxx.xx
*/

#include <stdio.h>

int main (void)
{
    int codigo, cantidad, caja, band = 0;
    float importe;

    printf("Ingrese el codigo del articulo: ");
    scanf("%d", &codigo);
    printf("Ingrese la cantidad a comprar: ");
    scanf("%d", &cantidad);


    if (cantidad < 1)
    {
        band++;
        printf("La cantidad ingresada no es valida.");
    }

    switch (codigo)
    {
    case 1:
    case 10:
    case 100:
        importe = cantidad * 120;
        break;
    case 2:
    case 22:
    case 222:
        caja = cantidad / 10;
        importe = (caja * 650) + (cantidad * 70);
        break;
    case 3:
    case 33:
        importe = cantidad * 200;
        if (cantidad > 10)
            importe *= 0.9;
        break;
    case 4:
    case 44:
        importe = cantidad * 100;
        break;
    default:
        band++;
        printf("El articulo no existe en el inventario.");
        break;
    }

    if (band == 0)
        printf("\nARTICULO: %d \tCANTIDAD: %d \tIMPORTE A PAGAR: $%.2f", codigo, cantidad, importe);

    return 0;
}
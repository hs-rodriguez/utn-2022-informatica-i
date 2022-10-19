/*
    Ejercicio 9:
    Un fabricante de repuestos para tractores ha descubierto que ciertos
    artículos identificados por los números de catálogo 12121 al 18081;
    30012 al 45565 y 67000 al 68000 son defectuosos. Desea que se
    confeccione un programa que informándole el numero de catálogo indique
    si el artícuo es o no defectuoso. Los artículos del catálogo van desde
    el 1200 al 90000.
*/

#include <stdio.h>

int main (void)
{
    int art;
    printf("Ingrese el numero de catalogo: ");
    scanf("%d", &art);

    if (art < 1200 || art > 90000)
        printf("El articulo no existe en el catalogo.");
    else
        if ((art >= 12121 && art <=18081) || (art >= 30012 && art <= 45565) || (art >= 67000 && art <= 68000))
            printf("El articulo es defectuoso.");
        else
            printf("El articulo no es defectuoso.");
    
    return 0;
}
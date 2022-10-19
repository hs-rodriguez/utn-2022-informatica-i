/*
    Ejercicio 7:
    Conociendo los asistentes a un cine el día miércoles y sabiendo que el precio del 
    cine es de $650 y que por ser miércoles tiene un descuento del 50%. Calcular la 
    recaudación del cine.
*/

#include <stdio.h>

int main(void)
{
    int asistentes;
    float recaudacion;

    printf("Ingrese la cantidad de asistentes: ");
    scanf("%d", &asistentes);

    recaudacion = asistentes * 650 * 0.5;

    printf("La recaudacion del cine fue: $%.2f", recaudacion);

    return 0;
}
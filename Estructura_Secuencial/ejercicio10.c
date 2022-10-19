/*
    Ejercicio 10:
    En una producción de plafones se sabe que el 3% son defectuosos.
    Conociendo la cantidad fabricada.
    Determinar: a-) Cantidad de plafones aceptados.
                b-) Cantidad de plafones defectuosos.
*/

#include <stdio.h>

int main(void)
{
    int plafones, aceptados;

    printf("Ingrese la cantidad de plafones fabricados: ");
    scanf("%d", &plafones);

    /*  
        Al trabajar con enteros, la parte decimal se desecha.
        Por lo tanto, se debe calcular los aceptados, en vez de los defectuosos
        ya que de no hacerlo se tendra una cantidad erronea.
        Por ejemplo: 50 plafones fabricados
        3% defectuosos -> 1,5 plafones -> int = 1
        Aceptados -> 49
        En ese caso, los aceptados deberían ser 48, y desechar los 0,5
    */

    aceptados = plafones * 0.97;

    printf("\nAceptados: %d", aceptados);
    printf("\nDefectuosos: %d", plafones - aceptados);

    return 0;
}
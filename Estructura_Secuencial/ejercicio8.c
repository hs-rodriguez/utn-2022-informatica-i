/*
    Ejercicio 8:
    El precio para un vuelo es de $8000 en clase turista y se aplica un 
    incremento del 40% en primera clase.
    Se conoce la cantidad de pasajes de clase turista y de primera clase.
    Obtener la recaudación del vuelo.
*/

#include <stdio.h>

int main(void)
{
    int turista, primera;
    float recaudacion;

    printf("Ingrese la cantidad de pasajes turista: ");
    scanf("%d", &turista);
    printf("Ingrese la cantidad de pasajes primera: ");
    scanf("%d", &primera);

    recaudacion = turista * 8000 + primera * 8000 * 1.4;

    printf("La recaudacion del vuelo fue: $%.2f", recaudacion);

    return 0;
}
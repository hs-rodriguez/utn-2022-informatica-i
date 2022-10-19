/*
    Ejercicio 3:
    Se ingresan las notas de dos evaluaciones de un alumno. 
    Determinar la nota promedio.
*/

#include <stdio.h>

int main(void)
{
    int nota1, nota2;
    float prom;

    printf("Ingrese la primera nota: ");
    scanf("%d", &nota1);
    printf("Ingrese la segunda nota: ");
    scanf("%d", &nota2);

    prom = (nota1 + nota2) / 2;

    printf("El promedio es: %.2f", prom);

    return 0;
}
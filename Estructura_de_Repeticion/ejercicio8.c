/*
    Ejercicio 8:
    Dadas las edades y estaturas de 45 alumnos de un curso. Determinar:
    a) Edad promedio
    b) Estatura promedio
    c) Cantidad de alumnos mayores de 10 años.
    d) Cantidad de alumnos que miden menos de 140 cm.
*/

#include <stdio.h>
#define cant 45

int main (void)
{
    int edad, estatura, mayores = 0, menores = 0;
    float promEdad, promEstatura;

    printf("Ingrese la edad y estatura en cm de los alumnos, separadas por espacio (Ej: 15 170)\n");

    for (int i = 1; i <= cant; i++)
    {
        printf("Alumno (%d/%d): ", i, cant);
        scanf("%d %d", &edad, &estatura);

        promEdad += edad;
        promEstatura += estatura;

        if (edad > 10)
            mayores++;
        if (estatura < 140)
            menores++;
    }

    promEdad /= cant;
    promEstatura /= cant;

    printf("\nEdad promedio: %.2f", promEdad);
    printf("\nEstatura promedio: %.2f", promEstatura);
    printf("\nMayores de 10: %d", mayores);
    printf("\nMenores a 140 cm: %d", menores);

    return 0;
}
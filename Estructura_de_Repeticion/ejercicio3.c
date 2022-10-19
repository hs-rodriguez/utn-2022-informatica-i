/*
    Ejercicio 3:
    Dados 20 notas y DNI de alumnos de un curso. Determinar:
    a) Cantidad de alumnos aplazados (nota < a 4)
    b) Imprimir los DNI de los alumns cuya nota sea mayor a 8.
*/

#include <stdio.h>

int main (void)
{
    int dni, cont = 0;
    float nota;
    printf("Ingrese la nota y DNI de los alumnos separados por espacio (Ej: 8.50 44000111\n\n");

    for (int i = 1; i <= 20; i++)
    {
        printf("Alumno (%d/20): ", i);
        scanf("%f %d", &nota, &dni);

        if (nota < 4)
            cont++;
        
        if (nota > 8)
            printf("\nAlumno con nota mayor a 8: %d\n", dni);
    }

    printf("Cantidad de alumnos aplazados (nota < 4): %d", cont);

    return 0;
}
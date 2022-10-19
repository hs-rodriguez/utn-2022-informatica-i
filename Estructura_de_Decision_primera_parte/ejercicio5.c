/*
    Ejercicio 5:
    Se ingresan 3 lados de un triangulo. Indicar que tipo de triangulo es.
    Previamente verificar si forman triangulo sino indicar mediante un mensaje.
*/

#include <stdio.h>

int main (void)
{
    float a, b, c;
    printf ("Ingrese tres lados de un triangulo: ");
    scanf("%f%f%f", &a, &b, &c);

    if((a + b > c) && (a + c > b) && (b + c > a))
        if(a == b && a == c)
            printf("Forman un triangulo equilatero.");
        else
            if(a == b || a == c || b == c)
                printf("Forman un triangulo isosceles.");
            else
                printf("Forman un triangulo escaleno.");
    else
        printf("Los lados no forman un triangulo.");

    return 0;
}
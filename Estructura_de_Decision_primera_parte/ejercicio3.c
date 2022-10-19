/*
    Ejercicio 3:
    Se ingresan 3 nros. distintos. Determinar el mayor.
*/

#include <stdio.h>

int main(void)
{
    float n1, n2, n3;
    printf ("Ingrese tres numeros: ");
    scanf("%f %f %f", &n1, &n2, &n3);

    if(n1 >= n2 && n1 >= n3)
    {
        printf("El numero mayor es: %.2f", n1);
    }
    else
        if(n2 >= n3)
        {
            printf("El numero mayor es: %.2f", n2);
        }
        else
        {
            printf("El numero mayor es: %.2f", n3);
        }

    return 0;
}
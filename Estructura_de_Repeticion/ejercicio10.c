/*
    Ejercicio 10:
    Se ingresa un nro mayor o igual a 0 y menor que 10. Informar su factorial.
*/

#include <stdio.h>

int main (void)
{
    int numero, factorial = 1;

    printf("Ingrese un numero mayor o igual a 0 y menor que 10: ");
    scanf("%d", &numero);

    if (numero >= 0 && numero < 10)
    {
        for (int i = 1; i <= numero; i++)
        {
            factorial = factorial * i;
        }

        printf("Su factorial es: %d", factorial);
    }
    else
        printf("El numero no es valido.");

    return 0;
}
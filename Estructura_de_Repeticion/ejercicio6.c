/*
    Ejercicio 6:
    Se ingresa un numero mayor que cero y menor igual que 10.
    Realizar la tabla de multiplicacion de 1 a 10 del numero ingresado
*/

#include <stdio.h>

int main (void)
{
    int numero;
    printf("Ingrese un numero de 1 a 10: ");
    scanf("%d", &numero);

    if (numero > 0 && numero <= 10)
    {
        for (int i = 1; i <= 10; i++)
        {
            printf("\n%d * %d: %d", numero, i, numero*i);
        }
        
    }
    else
        printf("El numero no es valido.");

    return 0;
}
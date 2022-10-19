/*
    Ejercicio 12:
    Se ingresa un número entero positivo. Indicar si es perfecto.
    (Un nro. es perfecto cuando es igual a la suma de sus divisores)
*/

#include <stdio.h>

int main (void)
{
    int numero, suma = 0;

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &numero);

    if (numero > 0){
        for (int i = 1; i < numero; i++)
        {
            if (numero % i == 0)
                suma += i;
        }
        
        if (numero == suma)
            printf("El numero es perfecto.");
        else
            printf("El numero no es perfecto.");
    }
    else
        printf("El numero no es valido.");

    return 0;
}
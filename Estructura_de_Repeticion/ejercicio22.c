/*
    Ejercicio 22:
    Se ingresa un numero en sistema decimal entero positivo y convertirlo a binario
*/

#include <stdio.h>
#include <math.h>

int main (void)
{
    int decimal, potencia, band = 0;
    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &decimal);

    if (decimal > 0){
        printf("Binario: ");
        for (int i = 30; i >= 0; i--)
        {
            potencia = pow(2, i);
            if (decimal >= potencia)
            {
                decimal -= potencia;
                band++;
                printf("1");
            }
            else if (band != 0)
                printf("0");
            
        }
    }
    else
        printf("El valor ingresado no es valido.");

    return 0;
}
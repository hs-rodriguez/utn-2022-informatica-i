/*
    Ejercicio 23:
    Se ingresa un número en sistema binario entero y convertirlo a decimal.
*/

#include <stdio.h>
#include <math.h>

int main (void)
{
    int decimal = 0, cont = 0;
    unsigned long long binario;
    printf("Ingrese un numero binario entero: ");
    scanf("%llu", &binario);

    
    while (binario != 0)
    {
        if (binario % 10 != 0)
        {
            decimal += pow(2, cont);
        }
        
        binario /= 10;
        cont++;
    }
    
    printf("Decimal: %d", decimal);

    return 0;
}
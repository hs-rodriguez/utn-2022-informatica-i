/*
    Ejercicio 14:
    Se ingresan pares de números. Determinar la suma de cada par excepto 
    cuando ambos sean cero, en este caso indicar “SE INGRESARON CEROS”.
    Finaliza el ingreso cuando algún o ambos números sean negativos
*/

#include <stdio.h>

int main (void)
{
    float a = 0, b = 0;
    while (a >= 0 && b >= 0)
    {
        printf("\nIngrese un par de numeros: ");
        scanf("%f %f", &a, &b);

        if (a == 0 && b == 0)
            printf("Se ingresaron ceros.");
        else
            printf("La suma es: %.2f", a+b);
    }

    

    return 0;
}
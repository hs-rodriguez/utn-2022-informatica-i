/*
    Ejercicio 1:
    Confeccionar un programa que solicite el ingreso de 10 ternas de valores reales y para cada una de
    las ternas calcule e informe el promedio de sus valores. Para el cálculo del promedio implementar y
    utilizar una función.
*/

#include <stdio.h>

float promedio(int, int, int);

int main (void)
{
    float n1, n2, n3;

    for (int i = 1; i <= 10; i++)
    {
        printf("\nIngrese tres valores reales: ");
        scanf("%f %f %f", &n1, &n2, &n3);
        printf("\nEl promedio es: %.2f", promedio(n1, n2, n3));
    }

    return 0;
}

float promedio (int n1, int n2, int n3)
{
    return (float)(n1 + n2 + n3) / 3;
}